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


void Driver::on_activOrder_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->activOrder_page);
}


void Driver::on_listDoneOrder_button_clicked()
{
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

