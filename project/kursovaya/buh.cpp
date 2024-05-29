#include "buh.h"
#include "ui_buh.h"

Buh::Buh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buh)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

Buh::~Buh()
{
    delete ui;
}

void Buh::on_exit_clicked()
{
    this->close();
    emit exit();
}


void Buh::on_listZakazov_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->listZakazov_page);
}


void Buh::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}

