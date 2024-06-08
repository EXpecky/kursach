#include "driver.h"
#include "ui_driver.h"

Driver::Driver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Driver)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

Driver::~Driver()
{
    delete ui;
}

void Driver::on_exit_clicked()
{
    this->close();
    emit exit();
}

void Driver::setIdLogin(int id, QString login)
{
    this->Id = id;
    this->login = login;
}
void Driver::on_activOrder_button_clicked()
{
    database.openDatabase();
    database.createZakazData(activWorks, Id);
    if(activWorks.isEmpty()){
        QMessageBox::information(this,"Внимание!","У вас нет активного заказа","OK");
    }else {
        ui->Client_lineEdit->setText(activWorks.at(0).Client);
        ui->discription_lineEdit->setText(activWorks.at(0).Discription);
        ui->pointD_lineEdit->setText(activWorks.at(0).pointD);
        ui->pointP_lineEdit->setText(activWorks.at(0).pointP);
        ui->ves_lineEdit->setText(QString::number(activWorks.at(0).vesGruza));
        ui->Number_lineEdit->setText(activWorks.at(0).Number);
        ui->stackedWidget->setCurrentWidget(ui->activOrder_page);
    }
}


void Driver::on_listDoneOrder_button_clicked()
{
    dModel = new driverModel;
    dModel->createZakaz(this->Id);
    dModel->layoutChanged();
    ui->tableView->setModel(dModel);
    ui->stackedWidget->setCurrentWidget(ui->list_page);
}


void Driver::on_back_button_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void Driver::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void Driver::on_accept_button_clicked()
{
    database.updateGradeWorks(ui->comboBox->currentText(),activWorks.at(0).Id);
}

