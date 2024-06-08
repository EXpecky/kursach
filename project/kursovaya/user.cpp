#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);
    userOrderModel = new userModel();
    connect(this, &User::idData, userOrderModel, &userModel::createUOrders);

    ui->numberPhone_lineEdit->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([+0-9]{12})")));
    ui->vesGruza_lineEdit->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([0-9]{2})")));
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
    emit idData(this->Id);
    userOrderModel->layoutChanged();
    ui->tableView_2->setModel(userOrderModel);

    userWModel = new userWorksModel;
    userWModel->createUWorks(this->Id);
    userWModel->layoutChanged();
    ui->tableView->setModel(userWModel);

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
    if(ui->Email_lineEdit->text().isEmpty() or ui->numberPhone_lineEdit->text().isEmpty() or ui->pointDostavki_lineEdit->text().isEmpty() or ui->pointPogruzki_lineEdit->text().isEmpty() or ui->description_lineEdit->text().isEmpty() or ui->vesGruza_lineEdit->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка!","Введены не все поля","OK");

    }else{
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

}


int User::getId()
{
    return this->Id;
}
QString User::getLogin()
{
    return this->login;
}




