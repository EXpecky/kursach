#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QMessageBox>
#include "db.h"
#include "orderdata.h"
#include "adminmodel.h"
#include "pickdriver.h"
#include "infoorder.h"
#include <QRegularExpressionValidator>
namespace Ui {
class Administrator;
}

class Administrator : public QWidget
{
    Q_OBJECT


public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

signals:
    void exit();
    void getData(const QVector<orderData>& orders, const int index);

private slots:
    void on_exit_clicked();

    void on_order_button_clicked();

    void on_back_clicked();

    void on_reg_worker_clicked();

    void on_back_button_clicked();

    void on_accept_button_clicked();

    bool correctNumber(QString number);

    void on_grade_box_currentIndexChanged(int index);

    void on_accept_pushButton_clicked();

    void getDataDriver(QString name, const QString secName, const bool flag);

    void on_cancel_pushButton_clicked();

    void on_tableView_doubleClicked();

private:
    Ui::Administrator *ui;
    Db database;
    PickDriver *pickD;
    AdminModel *orderModel;
    InfoOrder *infoWindow;
    QRegularExpressionValidator *validator;
};

#endif // ADMINISTRATOR_H
