#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

User::~User()
{

    delete ui;
}

void User::on_exit_clicked()
{
    this->close();
    emit exit();
}


void User::on_createOrder_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->createOrder_page);
}


void User::on_listOrder_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listOrder_page);
}


void User::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void User::on_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void User::on_accept_button_clicked()
{
    QString email = ui->Email_lineEdit->text();
    QString number = ui->numberPhone_lineEdit->text();
    QString adresDost = ui->pointDostavki_lineEdit->text();
    QString adresPogr = ui->pointPogruzki_lineEdit->text();
    QString description = ui->description_lineEdit->text();
    int ves = ui->vesGruza_lineEdit->text().toInt();

    database.openDatabase();

    if(!(User::correctNumber(number))){
        QMessageBox::critical(this,"Предупреждение!","Поле номера телефона введено неверно");
        ui->numberPhone_lineEdit->setText("");
        return;
    }

    if(database.insertOrders(login, description, email, number, adresPogr, adresDost, ves)){
        QMessageBox::warning(this,"Успех!","Заявка отправленна","OK");
        ui->stackedWidget->setCurrentWidget(ui->main_page);
    }else{
        QMessageBox::critical(this,"Предупреждение!","Неверно введены поля!");
    }

    //qDebug() << this->Id;
}
bool User::correctNumber(QString number)
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


void User::setIdLogin(int id, QString llogin)
{
    this->Id = id;
    this->login = llogin;
    qDebug() << this->Id;
}








