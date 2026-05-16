#include "wdsolve.h"
#include "ui_wdsolve.h"
#include <QString>
#include "simplexsolver.h"
WdSolve::WdSolve(QWidget *parent) :
    QMainWindow(parent), // hoặc QWidget(parent) tùy class của bạn
    ui(new Ui::WdSolve)
{
    ui->setupUi(this);
    this->setStyleSheet("* { font-family: 'Times New Roman'; font-size: 11pt; }");
    this->setWindowTitle("Kết quả tính toán");
}

WdSolve::~WdSolve()
{
    delete ui;
}

void WdSolve::displayResults(const QString& status, double optimalZ, double c_0, const std::vector<double>& solution, const std::vector<SimplexStep>& history) {

    // 1. XỬ LÝ KHU VỰC KẾT QUẢ DỰA VÀO TRẠNG THÁI
    QFont fontZ = ui->lineEdit_Z->font();
    fontZ.setBold(true);
    fontZ.setPointSize(11); // Chỉnh cỡ chữ to lên
    ui->lineEdit_Z->setFont(fontZ);
    if (status == "Tối ưu") {
        double finalZ = optimalZ + c_0;
        ui->lineEdit_Z->setText(QString::number(finalZ, 'f', 4));

        int n = solution.size();
        ui->table_solution->setRowCount(n);
        ui->table_solution->setColumnCount(2);
        ui->table_solution->setHorizontalHeaderLabels(QStringList() << "Biến" << "Giá trị");

        for (int i = 0; i < n; ++i) {
            QTableWidgetItem *itemVar = new QTableWidgetItem(QString("x%1").arg(i + 1));
            itemVar->setTextAlignment(Qt::AlignCenter);
            ui->table_solution->setItem(i, 0, itemVar);

            QTableWidgetItem *itemVal = new QTableWidgetItem(QString::number(solution[i], 'f', 4));
            itemVal->setTextAlignment(Qt::AlignCenter);
            ui->table_solution->setItem(i, 1, itemVal);
        }
        ui->table_solution->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->table_solution->verticalHeader()->setVisible(false);
    }
    else {
        // TRƯỜNG HỢP LỖI (Vô nghiệm / Không giới hạn)
        ui->lineEdit_Z->setText(status); // In thẳng chữ lỗi vào ô Z

        // Dọn sạch bảng nghiệm vì không có nghiệm
        ui->table_solution->clearContents();
        ui->table_solution->setRowCount(0);
        ui->table_solution->setColumnCount(0);
    }

    // 2. LUÔN LUÔN VẼ CÁC TAB LỊCH SỬ DÙ THÀNH CÔNG HAY THẤT BẠI
    ui->tabWidget_steps->clear();
    for (size_t stepIdx = 0; stepIdx < history.size(); ++stepIdx) {
        const SimplexStep& step = history[stepIdx];
        int m = step.matrix.size() - 1;
        int n = step.matrix[0].size() - 1;

        QTableWidget *table = new QTableWidget();
        table->setRowCount(m + 1);
        table->setColumnCount(n + 2);

        QStringList headers;
        headers << "Cơ sở";
        for (int j = 0; j < n; ++j) headers << QString("x%1").arg(j + 1);
        headers << "Phương án";

        for (int i = 0; i <= m; ++i) {
            // --- CỘT 0: TÊN BIẾN CƠ SỞ HOẶC Z ---
            QTableWidgetItem *itemBase = new QTableWidgetItem();
            if (i == m) {
                itemBase->setText("Z");
            } else {
                int basicVarIndex = step.currentBasicVars[i];
                QString varName = (basicVarIndex != -1) ? QString("x%1").arg(basicVarIndex + 1) : "?";
                itemBase->setText(varName);
            }
            itemBase->setTextAlignment(Qt::AlignCenter);

            // Lệnh in đậm chữ cho Cột Cơ sở
            QFont boldFont = itemBase->font();
            boldFont.setBold(true);
            itemBase->setFont(boldFont); // Set font in đậm vào ô

            table->setItem(i, 0, itemBase);

            // --- CÁC CỘT CÒN LẠI (Ma trận và Phương án) ---
            for (int j = 0; j <= n; ++j) {
                QString val = QString::number(step.matrix[i][j], 'f', 2);
                QTableWidgetItem *itemVal = new QTableWidgetItem(val);
                itemVal->setTextAlignment(Qt::AlignCenter);

                // Nếu đang ở dòng cuối cùng (Dòng Z) -> In đậm toàn bộ các số
                if (i == m) {
                    itemVal->setFont(boldFont);
                }

                table->setItem(i, j + 1, itemVal);
            }
        }
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tabWidget_steps->addTab(table, step.stepName);
    }
    // Dành cho bảng Nghiệm tối ưu
    ui->table_solution->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold;}");
}
void WdSolve::on_pushButton_clicked()
{
    if(this->parentWidget()){
        this->parentWidget()->show();
    }
    this->close();
}

