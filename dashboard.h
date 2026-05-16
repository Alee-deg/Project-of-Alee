#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "wdsolve.h"
#include "Struct.h"

#include <QMainWindow>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    void setupObjectiveFunctionTable(int n);
    void setupConstraintsTable(int m, int n);
    void setupNumericCell(int row, int col);
    void setupVariableConstraints(int n);
    void getDataFromWd(LinearProgram &lb);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dashboard *ui;
    WdSolve* wd_solve;

protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif // DASHBOARD_H
