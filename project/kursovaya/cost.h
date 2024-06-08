#ifndef COST_H
#define COST_H

#include <QWidget>
#include <QMessageBox>
#include <QRegularExpressionValidator>
namespace Ui {
class Cost;
}

class Cost : public QWidget
{
    Q_OBJECT

public:
    explicit Cost(QWidget *parent = nullptr);
    ~Cost();
signals:
    void back();
    void returnCost(const float Costtt, const QString dangerous);

private slots:
    void on_back_pushButton_2_clicked();

    void on_accept_pushButton_clicked();

private:
    Ui::Cost *ui;
    QRegularExpressionValidator *validator;
};

#endif // COST_H
