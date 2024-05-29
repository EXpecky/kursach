#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QWidget>
#include <QMessageBox>
#include "db.h"
#include "orderdata.h"
#include "adminmodel.h"
#include "pickdriver.h"

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

private slots:
    void on_exit_clicked();

    void on_order_button_clicked();

    void on_back_clicked();

    void on_reg_worker_clicked();

    void on_back_button_clicked();

    void on_accept_button_clicked();

    bool correctNumber(QString number);

    void on_grade_box_currentIndexChanged(int index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_accept_pushButton_clicked();

    void getDataDriver(QString name);
public:
    AdminModel *orderModel;

private:
    Ui::Administrator *ui;
    Db database;

    PickDriver *pickD;
};

#endif // ADMINISTRATOR_H
