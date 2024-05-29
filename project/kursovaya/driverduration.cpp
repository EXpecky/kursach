#include "driverduration.h"
#include "ui_driverduration.h"

DriverDuration::DriverDuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DriverDuration)
{
    ui->setupUi(this);
}

DriverDuration::~DriverDuration()
{
    delete ui;
}

void DriverDuration::on_accept_button_clicked()
{
    emit getDuration();
    this->close();
}
int DriverDuration::gDuration()
{
    return ui->stazh_lineEdit->text().toInt();
}


void DriverDuration::on_back_button_clicked()
{
    this->close();
}

