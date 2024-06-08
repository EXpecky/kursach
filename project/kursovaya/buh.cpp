#include "buh.h"
#include "ui_buh.h"

Buh::Buh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buh)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->main_page);

    costWindow = new Cost();
    connect(costWindow, &Cost::returnCost, this, &Buh::createCost);


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
    costModel = new buhModel;
    costModel->createCost();
    costModel->layoutChanged();
    ui->tableView->setModel(costModel);
    ui->stackedWidget->setCurrentWidget(ui->listZakazov_page);
}


void Buh::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_page);
}


void Buh::on_tableView_doubleClicked()
{
    this->index = ui->tableView->selectionModel()->selectedIndexes().first().row();
    costWindow->show();
}

void Buh::createCost(const float Costtt, const QString dangerous)
{
    database.insertCost(costModel->getID(index),Costtt,dangerous);
    costModel->createCost();
    costModel->layoutChanged();
    ui->tableView->setModel(costModel);
}






