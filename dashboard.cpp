#include "dashboard.h"
#include "ui_dashboard.h"
#include <QStringList>
#include <QComboBox>
#include "wdsolve.h"
#include <QCloseEvent>
#include <QApplication>
#include <QMessageBox>
#include "Struct.h"
#include "simplexsolver.h"
#include <QMessageBox>
Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->constrain_var->hide();
    ui->matrix->hide();
    ui->table_functionTarget->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->max_min->hide();
    this->wd_solve = nullptr;
    this->setStyleSheet("* { font-family: 'Times New Roman'; font-size: 14pt; }");
    ui->table_functionTarget->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");

    // In đậm tiêu đề ngang (Cột) cho bảng Ma trận ràng buộc
    ui->matrix->horizontalHeader()->setStyleSheet("QHeaderView::section { font-weight: bold; }");
    this->setWindowTitle("Nhập liệu");
}

Dashboard::~Dashboard()
{
    delete ui;
    // In đậm tiêu đề ngang (Cột) cho bảng Hàm mục tiêu

}
void Dashboard::setupObjectiveFunctionTable(int n){
    ui->table_functionTarget->setRowCount(1);
    ui->table_functionTarget->setColumnCount(n + 1);

    QStringList headers;
    for(int i = 0; i <= n; i++){
        headers << QString("x%1").arg(i);
    }
    ui->table_functionTarget->setHorizontalHeaderLabels(headers);

    ui->table_functionTarget->verticalHeader()->setVisible(false);

    for(int i = 0; i <= n; i ++){
        QDoubleSpinBox *spinBox = new QDoubleSpinBox();
        spinBox->setRange(-99999.99, 99999.99); //Cho phep so am duong
        spinBox->setDecimals(2); // Lay hai chu so thap phan
        spinBox->setValue(0.0); // Mac dinh la 0
        spinBox->setAlignment(Qt::AlignCenter);
        //Nhung spinBox vao o cua bang
        ui->table_functionTarget->setCellWidget(0, i, spinBox);
    }
    //Cho cac cot tu dong gian deu ra vua khit voi chieu rong cua bang
    ui->table_functionTarget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void Dashboard::setupConstraintsTable(int m, int n){
    int totalColumns = n + 2;
    ui->matrix->setRowCount(m);
    ui->matrix->setColumnCount(totalColumns);
    //Thiet lap tieu de
    QStringList headers;
    for(int i = 1; i <= n; i ++) headers << QString("x%1").arg(i);
    headers << "Sign" << "b_i";
    ui->matrix->setHorizontalHeaderLabels(headers);
    //Thiet lap widget
    for(int row = 0; row < m; row ++){
        for(int col = 0; col < n; ++col){
            this->setupNumericCell(row, col);
        }
        // nhung cot n cho dau
        QComboBox* comboSign = new QComboBox();
        comboSign->addItems({"<=", "=", ">="});
        comboSign->setStyleSheet("QcomboBox {border: none; }");
        ui->matrix->setCellWidget(row, n, comboSign);
        // cot n + 1 nhap he so tu do
        this->setupNumericCell(row, n + 1);
    }
    ui->matrix->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void Dashboard::setupNumericCell(int row, int col){
    QDoubleSpinBox *spinBox = new QDoubleSpinBox();
    spinBox->setRange(-99999.99, 99999.99);
    spinBox->setDecimals(2);
    spinBox->setValue(0.0);
    spinBox->setAlignment(Qt::AlignCenter);
    ui->matrix->setCellWidget(row, col, spinBox);
}
void Dashboard::setupVariableConstraints(int n){
    ui->table_varConstraint->setRowCount(n);
    ui->table_varConstraint->setColumnCount(3);

    //Dat tieu de
    ui->table_varConstraint->setHorizontalHeaderLabels({"Bien", "Dau", "Gia tri"});

    for(int i = 0; i < n; i ++){
        // Cot 1: ten bien
        QLabel* labelVar = new QLabel(QString("x%1").arg(i + 1));
        labelVar->setAlignment(Qt::AlignCenter);
        ui->table_varConstraint->setCellWidget(i, 0, labelVar);
        // Cot 2: Dau(ComboBox)
        QComboBox* comboSign = new QComboBox();
        comboSign->addItems({">=", "<=", "=", "free"});
        comboSign->setCurrentIndex(0);
        ui->table_varConstraint->setCellWidget(i, 1, comboSign);
        // Cot 3:
        QDoubleSpinBox *spinBox = new QDoubleSpinBox();
        spinBox->setRange(-99999.99, 99999.99);
        spinBox->setDecimals(2);
        spinBox->setValue(0.0);
        spinBox->setAlignment(Qt::AlignCenter);
        ui->table_varConstraint->setCellWidget(i, 2, spinBox);

        // An cot gia tri neu nguoi dung su dung free
        connect(comboSign, &QComboBox::currentTextChanged, [spinBox](const QString &text){
            spinBox->setEnabled(text != "free");
            if(text == "free") spinBox->setValue(0);
        });
    }
    ui->table_varConstraint->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Dashboard::on_pushButton_4_clicked()
{
    if(this->parentWidget()){
        this->parentWidget()->show();
    }
    this->hide();
}


void Dashboard::on_pushButton_2_clicked()
{
    int n = ui->spinBox->value();
    int m = ui->spinBox_2->value();
    if(n > 0 && m > 0){
        this->setupConstraintsTable(m, n);
        this->setupVariableConstraints(n);
        this->setupObjectiveFunctionTable(n);
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->table_functionTarget->show();
        ui->table_varConstraint->show();
        ui->matrix->show();
        ui->constrain_var->show();
        ui->max_min->show();
    }
    else{
        QMessageBox::warning(this, "Warning","Vui lòng nhập số biến và số ràng buộc rõ ràng");
    }
}
#include <QMessageBox> // Nhớ include thư viện này để hiện thông báo

#include <QMessageBox> // Alee nhớ đảm bảo có dòng này ở đầu file dashboard.cpp nhé

void Dashboard::on_pushButton_3_clicked()
{
    LinearProgram local_lp;
    local_lp.isMaximize = (ui->max_min->currentText() != "Min");
    this->getDataFromWd(local_lp);

    SimplexSolver solver(local_lp);

    // GỌI HÀM GIẢI (Không cần nhốt trong thẻ if nữa)
    solver.solve();

    if (this->wd_solve) {
        delete this->wd_solve;
    }
    this->wd_solve = new WdSolve(this);

    // Bơm trạng thái vào làm tham số đầu tiên
    this->wd_solve->displayResults(
        solver.getStatus(),     // <--- Thêm dòng này
        solver.getOptimalZ(),
        local_lp.c_0,
        solver.getSolution(),
        solver.getHistory()
        );

    this->wd_solve->setAttribute(Qt::WA_DeleteOnClose);
    connect(this->wd_solve, &WdSolve::destroyed, this, [this](){
        this->wd_solve = nullptr;
        this->show();
    });
    this->wd_solve->show();
}
void Dashboard::closeEvent(QCloseEvent *event){
    QApplication::quit();
    event->accept();
}
void Dashboard::getDataFromWd(LinearProgram &lp){
    //1. Lay du lieu tu ham muc tieu
    int cols_obj = ui->table_functionTarget->columnCount();
    for(int j = 0;j < cols_obj; j ++){
        //Ep kieu trong o Widget ve QDoubleSpinBox
        QDoubleSpinBox* spinC = qobject_cast<QDoubleSpinBox*>(ui->table_functionTarget->cellWidget(0, j));
        if(spinC){
            lp.c.push_back(spinC->value());
        }
    }
    if (!lp.c.empty()) {
        lp.c_0 = lp.c[0];
        lp.c.erase(lp.c.begin());
    } else {
        lp.c_0 = 0.0;
        qDebug() << "Lỗi: Không lấy được hệ số hàm mục tiêu!";
        return;
    }
    //2. Lay du lieu he rang buoc
    int m = ui->matrix->rowCount();
    int cols_const = ui->matrix->columnCount();
    int n_vars = cols_const - 2;

    for(int i = 0; i < m;i ++){
        std::vector<double> rowA;

        //2a. Lay cac he so x_j
        for(int j = 0;j < n_vars; j ++){
            QDoubleSpinBox* spinA = qobject_cast<QDoubleSpinBox*>(ui->matrix->cellWidget(i, j));
            if(spinA){
                rowA.push_back(spinA->value());
            }
        }
        lp.A.push_back(rowA);
        //2b. Lay dau()
        QComboBox *comboSign = qobject_cast<QComboBox*>(ui->matrix->cellWidget(i, n_vars));
        if(comboSign){
            lp.signs.push_back(comboSign->currentText());
        }

        //2c. Lay he so tu do b_i
        QDoubleSpinBox *spinB = qobject_cast<QDoubleSpinBox*>(ui->matrix->cellWidget(i, n_vars + 1));
        if(spinB){
            lp.b.push_back(spinB->value());
        }
    }
    qDebug() << "--- Dữ liệu thu thập được ---";
    qDebug() << "c_0: " << lp.c_0;
    qDebug() << "Hàm mục tiêu C có kích thước:" << lp.c.size();
    qDebug() << "Ma trận A có kích thước:" << lp.A.size() << "x" << (lp.A.empty() ? 0 : lp.A[0].size());
    qDebug() << "Dấu ràng buộc đầu tiên:" << (lp.signs.empty() ? "None" : lp.signs[0]);
    qDebug() << "He so b_i co kich thuoc: " << lp.b.size();
    // 3. Lay rang buoc bien
    int n_vars_count = ui->table_varConstraint->rowCount();

    for(int i = 0; i < n_vars_count; ++i){
        VarBound vb;
        // 3.a Lay ComboBox dau
        QComboBox* comboVarSign = qobject_cast<QComboBox*>(ui->table_varConstraint->cellWidget(i, 1));
        // 3.b Lay SpinBox gia tri
        QDoubleSpinBox* spinVarVal = qobject_cast<QDoubleSpinBox*>(ui->table_varConstraint->cellWidget(i, 2));
        if(comboVarSign && spinVarVal){
            vb.sign = comboVarSign->currentText();
            vb.isFree = (vb.sign == "free");

            vb.value = vb.isFree ? 0 : spinVarVal->value();

            lp.varBounds.push_back(vb);
        }
    }
    qDebug() << "Số lượng ràng buộc biến đã lấy:" << lp.varBounds.size();
    if(!lp.varBounds.empty()) {
        qDebug() << "Biến x1 có điều kiện:" << lp.varBounds[0].sign << lp.varBounds[0].value;
    }
}
