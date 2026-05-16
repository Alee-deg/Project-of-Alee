#include "simplexsolver.h"

SimplexSolver::SimplexSolver(const LinearProgram& inputLP){
    this->lp = inputLP;
    this->statusMsg = "Chưa giải";
}
double SimplexSolver::getOptimalZ() const{
    if(this->tableau.empty()) return 0.0;
    int m = this->tableau.size() - 1;
    int n = this->tableau[0].size() - 1;
    // Bang don hinh tieu chuan luu gia tri -Z o goc phai duoi
    double z = this->tableau[m][n];
    return this->lp.isMaximize ? z : -z;
}
std::vector<double> SimplexSolver::getSolution() const{
    std::vector<double> sol(this->originalVarsCount, 0.0);
    if(this->tableau.empty()) return sol;
    int m = this->tableau.size() - 1;
    int n = this->tableau[0].size() - 1;
    //Quet cac bien co so de lay nghiem tuong ung
    for(int i = 0; i < m;i ++){
        int basicVar = this->basicVariables[i];
        if(basicVar < this->originalVarsCount){
            sol[basicVar] = this->tableau[i][n];
        }
    }
    return sol;
}
QString SimplexSolver::getStatus() const {return this->statusMsg;}

// Chuan hoa bai toan dua ve dang chinh tac
void SimplexSolver::convertToStandardForm() {
    originalVarsCount = lp.c.size();
    this->handleNegativeB();           // Bước 1: Đảm bảo vế phải b_i >= 0
    this->handleVariableBounds();       // Bước 2: Đảm bảo x_i >= 0 (Tách biến tự do)
    this->addSlackAndSurplusVariables();  // Bước 3: Đưa bất phương trình về phương trình
}

void SimplexSolver::handleNegativeB() {
    for (int i = 0; i < lp.b.size(); ++i) {
        if (lp.b[i] < 0) {
            lp.b[i] = -lp.b[i]; // Đảo dấu b_i
            // Đảo dấu toàn bộ hệ số hàng i
            for (int j = 0; j < lp.A[i].size(); ++j) lp.A[i][j] = -lp.A[i][j];
            // Đảo chiều bất phương trình
            if (lp.signs[i] == "<=") lp.signs[i] = ">=";
            else if (lp.signs[i] == ">=") lp.signs[i] = "<=";
        }
    }
}
void SimplexSolver::handleVariableBounds() {
    // Duyệt lùi mảng để thao tác insert() cột mới không làm lệch index các cột phía sau
    for (int j = lp.varBounds.size() - 1; j >= 0; --j) {
        VarBound vb = lp.varBounds[j];

        // Nếu biến x_j là Tùy ý -> Tách thành (u_j - v_j)
        if (vb.isFree || vb.sign == "free") {
            // Chèn cột v_j (có giá trị = -u_j) vào ngay sau cột j
            for (int i = 0; i < lp.A.size(); ++i) {
                lp.A[i].insert(lp.A[i].begin() + j + 1, -lp.A[i][j]);
            }
            lp.c.insert(lp.c.begin() + j + 1, -lp.c[j]);

            // Cập nhật lại điều kiện biên (Cả 2 biến thành phần đều >= 0)
            lp.varBounds[j].sign = ">=";
            lp.varBounds.insert(lp.varBounds.begin() + j + 1, {">=", 0.0, false});
            originalVarsCount++;
        }
        // Nếu x_j <= 0 -> Đảo dấu để trở thành x_j >= 0
        else if (vb.sign == "<=") {
            for (int i = 0; i < lp.A.size(); ++i) lp.A[i][j] = -lp.A[i][j];
            lp.c[j] = -lp.c[j];
            lp.varBounds[j].sign = ">=";
        }
    }
}
void SimplexSolver::addSlackAndSurplusVariables() {
    int m = lp.signs.size();
    this -> basicVariables.assign(m, -1); // Khởi tạo mảng biến cơ sở là -1 (Chưa có)

    for (int i = 0; i < m; ++i) {
        if (lp.signs[i] == "<=") {
            // Thêm biến bù (+s_i)
            for (int row = 0; row < m; ++row) lp.A[row].push_back((row == i) ? 1.0 : 0.0);
            lp.c.push_back(0.0);
            basicVariables[i] = lp.c.size() - 1; // Biến bù này trở thành biến cơ sở
            lp.signs[i] = "=";
        }
        else if (lp.signs[i] == ">=") {
            // Thêm biến thặng dư (-s_i). Biến thặng dư mang dấu trừ nên không thể làm biến cơ sở.
            for (int row = 0; row < m; ++row) lp.A[row].push_back((row == i) ? -1.0 : 0.0);
            lp.c.push_back(0.0);
            lp.signs[i] = "=";
        }
    }
}
// Thuat toan don hinh
bool SimplexSolver::solve() {
    convertToStandardForm();

    // Kiểm tra xem bài toán có thiếu biến cơ sở không (do dấu >= hoặc =)
    bool needsPhase1 = false;
    for (int b : basicVariables) {
        if (b == -1) {
            needsPhase1 = true;
            break;
        }
    }

    // Điều hướng thuật toán
    if (needsPhase1) {
        return solveTwoPhase();
    } else {
        buildTableau();
        int m = lp.A.size();
        for(int i = 0; i < m; i++) basicVariables[i] = originalVarsCount + i;

        bool success = runSimplexLoop();

        // --- SỬA LẠI ĐOẠN NÀY ---
        if (success) {
            if (checkAlternativeOptima()) {
                statusMsg = "Vô số nghiệm (Alternative Optima)";
            } else {
                statusMsg = "Tối ưu";
            }
        }
        // ------------------------
        return success;
    }
}
void SimplexSolver::buildTableau() {
    int m = lp.A.size();
    int n = lp.c.size();
    tableau.assign(m + 1, std::vector<double>(n + 1, 0.0));

    // Nạp ma trận A và vector B vào Bảng
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) tableau[i][j] = lp.A[i][j];
        tableau[i][n] = lp.b[i];
    }
    // Nạp hàm mục tiêu vào dòng Z (Dòng cuối cùng).
    for (int j = 0; j < n; ++j) {
        tableau[m][j] = lp.isMaximize ? -lp.c[j] : lp.c[j];
    }
    iterationCount = 0;
    recordStep("Bảng khởi tạo");
}
// QUY TẮC BLAND ĐƯỢC ÁP DỤNG TRONG 2 HÀM FIND PIVOT SAU ĐÂY:
int SimplexSolver::findPivotColumn() {
    int m = tableau.size() - 1;
    int n = tableau[0].size() - 1;
    for (int j = 0; j < n; ++j) {
        // [Quy tắc Bland] Chọn biến có hệ số âm ĐẦU TIÊN (Index nhỏ nhất) thay vì âm nhỏ nhất
        if (tableau[m][j] < -EPSILON) return j;
    }
    return -1; // Nếu dòng Z không còn số âm -> Thuật toán hoàn tất
}
int SimplexSolver::findPivotRow(int pivotCol) {
    int m = tableau.size() - 1;
    int n = tableau[0].size() - 1;
    int pivotRow = -1;
    double minRatio = 1e9;
    int minVarIndex = 1e9;

    for (int i = 0; i < m; ++i) {
        double a_ij = tableau[i][pivotCol];
        if (a_ij > EPSILON) { // Chỉ xét các phần tử trục xoay > 0
            double ratio = tableau[i][n] / a_ij;

            if (ratio < minRatio - EPSILON) {
                minRatio = ratio;
                pivotRow = i;
                minVarIndex = basicVariables[i];
            }
            // [Quy tắc Bland] Nếu có 2 tỷ số min bằng nhau (Tie)
            else if (abs(ratio - minRatio) <= EPSILON) {
                // Ưu tiên chọn hàng có biến cơ sở mang Index nhỏ hơn để đưa ra khỏi cơ sở
                if (basicVariables[i] < minVarIndex) {
                    pivotRow = i;
                    minVarIndex = basicVariables[i];
                }
            }
        }
    }
    return pivotRow;
}
void SimplexSolver::performPivot(int pivotRow, int pivotCol) {
    int m = tableau.size();
    int n = tableau[0].size();
    double pivotValue = tableau[pivotRow][pivotCol];

    // Biến đổi hàng trục (Chia tất cả cho phần tử trục)
    for (int j = 0; j < n; ++j) tableau[pivotRow][j] /= pivotValue;

    // Biến đổi các hàng còn lại theo công thức hình chữ nhật Gauss
    for (int i = 0; i < m; ++i) {
        if (i != pivotRow) {
            double factor = tableau[i][pivotCol];
            for (int j = 0; j < n; ++j) {
                tableau[i][j] -= factor * tableau[pivotRow][j];
            }
        }
    }
    // Ghi nhận sự thay đổi của biến cơ sở tại hàng này
    basicVariables[pivotRow] = pivotCol;
    iterationCount++;
    recordStep(QString("Vòng lặp %1 (Xoay x%2)").arg(iterationCount).arg(pivotCol + 1));
}
bool SimplexSolver::runSimplexLoop(bool isPhaseOne) {
    while (true) {
        int pivotCol = findPivotColumn();
        if (pivotCol == -1) return true; // Dừng vì đã đạt tối ưu

        int pivotRow = findPivotRow(pivotCol);
        if (pivotRow == -1) {
            statusMsg = "Vô nghiệm do bài toán Không giới hạn (Unbounded)";
            return false;
        }
        performPivot(pivotRow, pivotCol);
    }
}
// KHỐI 3: THUẬT TOÁN HAI PHA (Xử lý biến nhân tạo)
bool SimplexSolver::solveTwoPhase() {
    int m = lp.A.size();
    int n_slack = lp.c.size(); // Số cột trước khi nạp thêm biến nhân tạo
    std::vector<int> artificialCols;

    // 1. Thêm biến nhân tạo cho các phương trình thiếu biến cơ sở
    for (int i = 0; i < m; ++i) {
        if (basicVariables[i] == -1) {
            int a_col = lp.c.size();
            for (int r = 0; r < m; ++r) lp.A[r].push_back((r == i) ? 1.0 : 0.0);
            lp.c.push_back(0.0); // Hàm mục tiêu gốc của biến nhân tạo là 0
            basicVariables[i] = a_col;
            artificialCols.push_back(a_col);
        }
    }

    buildTableau(); // Tạo khung bảng (với dòng Z hiện đang chứa C gốc)
    int cols = tableau[0].size() - 1;

    // --- PHA 1: Tối ưu hóa hàm nhân tạo (W = -sum(a_i)) ---
    qDebug() << "Bắt đầu chạy Pha 1...";

    // Thiết lập dòng Z cho Pha 1: Chỉ quan tâm đến biến nhân tạo
    for (int j = 0; j <= cols; ++j) tableau[m][j] = 0.0;
    for (int a_col : artificialCols) tableau[m][a_col] = 1.0;

    // Làm sạch dòng Z bằng cách trừ đi các hàng chứa biến nhân tạo cơ sở
    for (int i = 0; i < m; ++i) {
        if (std::find(artificialCols.begin(), artificialCols.end(), basicVariables[i]) != artificialCols.end()) {
            for (int j = 0; j <= cols; ++j) tableau[m][j] -= tableau[i][j];
        }
    }

    // Chạy vòng lặp Đơn hình cho Pha 1
    if (!this->runSimplexLoop()) return false;

    // Nếu giá trị lớn nhất của hàm W < 0 (tức là vẫn còn biến nhân tạo > 0)
    if (abs(tableau[m][cols]) > EPSILON) {
        statusMsg = "Vô nghiệm (Infeasible) do không thể triệt tiêu hết biến nhân tạo";
        return false;
    }

    // --- PHA 2: Quay về tối ưu hàm mục tiêu ban đầu ---
    qDebug() << "Bắt đầu chạy Pha 2...";

    // Khôi phục lại dòng Z gốc (Trừ các biến nhân tạo)
    for (int j = 0; j < n_slack; ++j) tableau[m][j] = lp.isMaximize ? -lp.c[j] : lp.c[j];
    for (int j = n_slack; j < cols; ++j) tableau[m][j] = 0.0;

    // >>> SỬA DÒNG NÀY: Đảm bảo nạp c_0 vào để in ra đúng giá trị Z <<<
    tableau[m][cols] = lp.isMaximize ? lp.c_0 : -lp.c_0;

    // Làm sạch dòng Z theo các biến cơ sở hiện tại
    for (int i = 0; i < m; ++i) {
        int b_col = basicVariables[i];
        double factor = tableau[m][b_col];
        if (abs(factor) > EPSILON) {
            for (int j = 0; j <= cols; ++j) tableau[m][j] -= factor * tableau[i][j];
        }
    }

    // Đánh dấu phạt cực lớn (Big-M) vào cột nhân tạo để thuật toán Pha 2 không bao giờ Pivot lại vào chúng
    for (int a_col : artificialCols) tableau[m][a_col] = 1e9;

    // >>> THÊM DÒNG NÀY: Chụp ảnh bảng khởi tạo của Pha 2 để hiển thị lên Tab <<<
    this->recordStep("Khởi tạo Pha 2 (Z thực)");

    // Chạy vòng lặp Đơn hình cho Pha 2 để ra kết quả cuối cùng
    bool success = this->runSimplexLoop();

    // --- SỬA LẠI ĐOẠN NÀY ĐỂ CHECK VÔ SỐ NGHIỆM ---
    if (success) {
        if (this->checkAlternativeOptima()) {
            statusMsg = "Vô số nghiệm (Alternative Optima)";
        } else {
            statusMsg = "Tối ưu";
        }
    }

    return success;
}
void SimplexSolver::recordStep(const QString& name) {
    SimplexStep step;
    step.stepName = name;
    step.matrix = this->tableau;
    step.currentBasicVars = this->basicVariables;
    history.push_back(step);
}
bool SimplexSolver::checkAlternativeOptima() {
    int m = tableau.size() - 1; // Dòng Z
    int n = tableau[0].size() - 1; // Bỏ qua cột vế phải B

    for (int j = 0; j < n; ++j) {
        // Kiểm tra xem cột j có đang là biến cơ sở không
        bool isBasic = false;
        for (int i = 0; i < m; ++i) {
            if (basicVariables[i] == j) {
                isBasic = true;
                break;
            }
        }

        // Nếu KHÔNG phải biến cơ sở VÀ hệ số dòng Z bằng 0 (xét theo sai số EPSILON)
        if (!isBasic && abs(tableau[m][j]) <= EPSILON) {
            // Loại trừ các cột của biến nhân tạo (nếu chạy 2 Pha, biến nhân tạo có hệ số 1e9 nên tự động né được)
            return true;
        }
    }
    return false;
}
