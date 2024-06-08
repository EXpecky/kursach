#include "registration.h"
#include "ui_registration.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    Db databse;
    ui->numberPhone_lineEdit->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([+0-9]{12})")));

}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_2_clicked()
{
    this->close();
    emit back();
}


void registration::on_pushButton_clicked()
{
    if(ui->login_lineEdit->text().isEmpty() or ui->password_lineEdit->text().isEmpty() or ui->surname_lineEdit->text().isEmpty() or ui->name_lineEdit->text().isEmpty() or ui->email_lineEdit->text().isEmpty() or ui->numberPhone_lineEdit->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка!","Введены не все поля","OK");
        }else{
        QString login = ui->login_lineEdit->text();
        QString pass = ui->password_lineEdit->text();
        QString surn = ui->surname_lineEdit->text();
        QString name = ui->name_lineEdit->text();
        QString patr = ui->patronomyc_lineEdit->text();
        QString email = ui->email_lineEdit->text();
        QString number = ui->numberPhone_lineEdit->text();
        database.openDatabase();
        if(!(registration::correctNumber(number))){
            QMessageBox::critical(this,"Предупреждение!","Поле номера телефона введено неверно");
            ui->numberPhone_lineEdit->setText("");
            return;
        }
        if (database.correctLogin(login)){
            if(database.insertDataU(login, pass, "Заказчик") and database.insertUsers(surn,name,patr,email,number)){
                QMessageBox::warning(this,"Успех!","Регистрация прошла успешно!","OK");
                this->close();
                emit back();
            }else {
                QMessageBox::critical(this,"Предупреждение!","Неверно введены поля!");
            }
        }else{
            QMessageBox::critical(this,"Предупреждение!","Данный логин уже существует!");
            ui->login_lineEdit->setText("");
        }
    }
    database.closeDatabase();

}

bool registration::correctNumber(QString number)
{
    if(number.size() != 11) return false;
    if (number.toInt() < 0) return false;
    for (int i = 0; i<number.size(); i++){
        if ((number.at(i) <= '9') and (number.at(i) >= '0')){
            return true;
        }
    }
    return false;

}















