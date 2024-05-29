#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QMessageBox>
#include "db.h"
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();

signals:
    void exit();

public:
    int Id;
    QString login;
    void setIdLogin(int id, QString llogin);

private slots:
    void on_exit_clicked();

    void on_createOrder_button_clicked();

    void on_listOrder_button_clicked();

    void on_back_button_clicked();

    void on_back_button_2_clicked();

    void on_accept_button_clicked();

    bool correctNumber(QString number);


private:
    Ui::User *ui;
    Db database;
};

#endif // USER_H
