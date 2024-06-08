#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QMessageBox>
#include "db.h"
#include "usermodel.h"
#include "userworksmodel.h"
#include <QRegularExpressionValidator>
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
    void idData(const int id);

public:

    void setIdLogin(int id, QString llogin);

private slots:
    void on_exit_clicked();

    void on_createOrder_button_clicked();

    void on_listOrder_button_clicked();

    void on_back_button_clicked();

    void on_back_button_2_clicked();

    void on_accept_button_clicked();

    bool correctNumber(QString number);

    int getId();

    QString getLogin();



private:
    int Id;
    QString login;
    Ui::User *ui;
    Db database;
    userModel *userOrderModel;
    userWorksModel * userWModel;
    QRegularExpressionValidator *validator;
    \
};

#endif // USER_H
