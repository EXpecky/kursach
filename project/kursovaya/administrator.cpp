#include "administrator.h"
#include "ui_administrator.h"


Administrator::Administrator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);
    ui->stazh_lineEdit->hide();
    ui->label_3->hide();

    orderModel = new AdminModel;
    ui->tableView->setModel(orderModel);
    //delete orderModel;
    //ui->tableView->
    //Db database;

    pickD  = new PickDriver();


    connect(pickD, &PickDriver::accept, this, &Administrator::getDataDriver);

}

Administrator::~Administrator()
{
    delete ui;

}

void Administrator::on_exit_clicked()
{
    this->close();
    emit exit();
}


void Administrator::on_order_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->order_page);
}


void Administrator::on_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void Administrator::on_reg_worker_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->add_page);

}


void Administrator::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void Administrator::on_accept_button_clicked()
{
    QString grade = ui->grade_box->currentText();
    QString login = ui->login_lineEdit->text();
    QString pass = ui->password_lineEdit->text();
    QString surn = ui->surname_lineEdit->text();
    QString name = ui->name_lineEdit->text();
    QString patr = ui->patronomyc_lineEdit->text();
    QString email = ui->email_lineEdit->text();
    QString number = ui->numberPhone_lineEdit->text();



    database.openDatabase();

    if(!(Administrator::correctNumber(number))){
        QMessageBox::critical(this,"Предупреждение!","Поле номера телефона введено неверно");
        ui->numberPhone_lineEdit->setText("");
        return;
    }

    if (database.correctLogin(login)){
        if(grade == "Водитель"){
            int stazh = ui->stazh_lineEdit->text().toInt();
            if(database.insertDataU(login, pass, grade) and database.insertDriver(surn,name,patr,email,number,stazh)){
                QMessageBox::warning(this,"Успех!","Регистрация прошла успешно!","OK");
                ui->stackedWidget->setCurrentWidget(ui->main_page);
            }else {
                QMessageBox::critical(this,"Предупреждение!","Неверно введены поля!");
            }
        }else{
            if(database.insertDataU(login, pass, grade) and database.insertWorkers(surn,name,patr,email,number)){
                QMessageBox::warning(this,"Успех!","Регистрация прошла успешно!","OK");
                ui->stackedWidget->setCurrentWidget(ui->main_page);
            }else {
                QMessageBox::critical(this,"Предупреждение!","Неверно введены поля!");
            }
        }
    }else{
        QMessageBox::critical(this,"Предупреждение!","Данный логин уже существует!");
        ui->login_lineEdit->setText("");
    }
    database.closeDatabase();


}

bool Administrator::correctNumber(QString number)
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

void Administrator::on_grade_box_currentIndexChanged(int index)
{
    if (index == 2){
        ui->stazh_lineEdit->show();
        ui->label_3->show();
    }else{
        ui->stazh_lineEdit->hide();
        ui->label_3->hide();
    }
}

void Administrator::on_tableView_clicked(const QModelIndex &index)
{
    //qDebug() << index;
//    if (index == 1){
//        ui->stackedWidget->setCurrentWidget(ui->main_page);
//    }
//    qDebug() << ui->tableView->selectionModel()->selectedRows().first().row();
}

void Administrator::on_tableView_activated(const QModelIndex &index)
{
    qDebug() << index;
    qDebug() << ui->tableView->selectionModel()->selectedIndexes().first().row();

    //qDebug() << orderModel->orders.at(0);
    //ui->tableView->setSelectionBehavior(QAbstractItemView.SelectRows);
}


void Administrator::on_accept_pushButton_clicked()
{

    pickD->show();



}
void Administrator::getDataDriver(const QString name, const QString secName, const bool flag)
{
    database.openDatabase();
    int indexOrder = ui->tableView->selectionModel()->selectedRows().first().row();
    qDebug() << flag;
    if (flag == false){
        QVector<QString> fDriver;
        fDriver = name.split(" ");
        database.insertWorks(fDriver.at(0), fDriver.at(1),"NULL", "NULL", orderModel->getId(indexOrder));
    }else{
        QVector <QString> fDriver;
        fDriver = name.split(" ");
        QVector <QString> sDriver;
        sDriver = secName.split(" ");
        database.insertWorks(fDriver.at(0), fDriver.at(1), sDriver.at(0), sDriver.at(1), orderModel->getId(indexOrder));
    }

}

