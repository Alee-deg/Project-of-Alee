#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->dashboard = nullptr;
    this->setWindowTitle("Phần mềm giải Quy Hoạch Tuyến Tính - Ver 1.0");
}

MainWindow::~MainWindow()
{
    delete this->dashboard;
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(this->dashboard){
        delete this->dashboard;
    }
    this->dashboard = new Dashboard(this);
    this->dashboard->setAttribute(Qt::WA_DeleteOnClose);
    connect(this->dashboard, &Dashboard::destroyed, this, [this](){
        this->dashboard = nullptr;
        this->show();
    });
    this->dashboard->show();
    this->hide();
}

