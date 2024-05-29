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
    emit accept(ui->comboBox->currentText());
}














