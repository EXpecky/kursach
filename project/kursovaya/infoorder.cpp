#include "infoorder.h"
#include "ui_infoorder.h"

InfoOrder::InfoOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoOrder)
{
    ui->setupUi(this);
}

InfoOrder::~InfoOrder()
{
    delete ui;
}

void InfoOrder::takeData(const QVector<orderData>& orders, const int index)
{
    ui->client_lineEdit->setText(orders.at(index).Client);
    ui->numberPhone_lineEdit->setText(orders.at(index).Number);
    ui->email_lineEdit->setText(orders.at(index).Email);
    ui->point_Dostav_lineEdit->setText(orders.at(index).PointDostavki);
    ui->pointPogr_lineEdit->setText(orders.at(index).PointPogruski);
    ui->description_lineEdit->setText(orders.at(index).Discription);
    ui->vesGruza_lineEdit->setText(QString::number(orders.at(index).VesGruza));
}

void InfoOrder::on_accept_pushButton_clicked()
{
    this->close();
}

