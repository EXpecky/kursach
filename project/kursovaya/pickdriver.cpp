#include "pickdriver.h"
#include "ui_pickdriver.h"

PickDriver::PickDriver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PickDriver)
{
    QVector<QString> driverVector;
    ui->setupUi(this);

    database.openDatabase();

    database.selectDriver(driverVector);
    ui->comboBox->clear();
    ui->comboBox->addItems(driverVector);
    ui->comboBox_2->hide();
    ui->label_2->hide();
    ui->daleteSecond_pushButton->hide();

}

PickDriver::~PickDriver()
{
    delete ui;
}

void PickDriver::on_back_pushButton_clicked()
{
    emit back();
    this->close();
}


void PickDriver::on_addSecond_pushButton_clicked()
{
    QVector<QString> driverVector;
    database.openDatabase();
    database.selectDriver(driverVector);

    ui->comboBox_2->show();
    ui->daleteSecond_pushButton->show();
    ui->label_2->show();
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(driverVector);
}


void PickDriver::on_daleteSecond_pushButton_clicked()
{
    ui->comboBox_2->clear();
    ui->comboBox_2->hide();
    ui->label_2->hide();
    ui->daleteSecond_pushButton->hide();

}


void PickDriver::on_accept_pushButton_clicked()
{
    if(ui->comboBox->count() == 0){
        QMessageBox::critical(this,"Предупреждение!","Все водители в данный момент заняты,\nЗаказ не может быть подтвержден","ОК");
        this->close();
    }else{
        emit accept(ui->comboBox->currentText(), ui->comboBox_2->currentText(), ui->comboBox_2->isVisible());
        qDebug() << ui->comboBox_2->isVisible();
        QMessageBox::information(this,"Успех!","Заявка подтверждена","ОК");
        this->close();
    }
}














