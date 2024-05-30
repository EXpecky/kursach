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

void InfoOrder::takeData(const QString client,const QString number,const QString email,const QString pointD,const QString pointP,const QString Discription,const int ves)
{
    ui->client_lineEdit->setText(client);
    ui->numberPhone_lineEdit->setText(number);
    ui->email_lineEdit->setText(email);
    ui->point_Dostav_lineEdit->setText(pointD);
    ui->pointPogr_lineEdit->setText(pointP);
    ui->description_lineEdit->setText(Discription);
    ui->vesGruza_lineEdit->setText(QString::number(ves));
}

void InfoOrder::on_accept_pushButton_clicked()
{
    this->close();
}

