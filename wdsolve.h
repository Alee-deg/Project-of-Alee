#ifndef WDSOLVE_H
#define WDSOLVE_H
#include "simplexsolver.h"
#include <QMainWindow>

namespace Ui {
class WdSolve;
}

#include <vector>

class WdSolve : public QMainWindow // hoặc QDialog/QWidget tùy bạn set up
{
    Q_OBJECT

public:
    explicit WdSolve(QWidget *parent = nullptr);
    ~WdSolve();

    // Thêm hàm này để nhận kết quả
    void displayResults(const QString& status, double optimalZ, double c_0, const std::vector<double>& solution, const std::vector<SimplexStep>& history);

private slots:
    void on_pushButton_clicked();

private:
    Ui::WdSolve *ui;
};

#endif // WDSOLVE_H
