#ifndef DRIVER_H
#define DRIVER_H

#include <QWidget>
#include "activzakaz.h"
#include "db.h"
#include "drivermodel.h"
#include "QMessageBox"

namespace Ui {
class Driver;
}

class Driver : public QWidget
{
    Q_OBJECT

public:
    explicit Driver(QWidget *parent = nullptr);
    ~Driver();

    void setIdLogin(int id, QString login);
signals:
    void exit();

private slots:
    void on_exit_clicked();

    void on_activOrder_button_clicked();

    void on_listDoneOrder_button_clicked();

    void on_back_button_2_clicked();

    void on_back_button_clicked();



    void on_accept_button_clicked();

private:
    QVector<activZakaz> activWorks;
    Ui::Driver *ui;
    Db database;
    int Id;
    QString login;
    driverModel *dModel;
};

#endif // DRIVER_H
