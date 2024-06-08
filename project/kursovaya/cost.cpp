#include "cost.h"
#include "ui_cost.h"

Cost::Cost(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cost)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(
        new QRegularExpressionValidator(
            QRegularExpression(R"([0-9]{6})")));
}

Cost::~Cost()
{
    delete ui;
}

void Cost::on_back_pushButton_2_clicked()
{
    emit back();
    this->close();
}


void Cost::on_accept_pushButton_clicked()
{
    QString dangerous = "0";

    if (ui->radioButton->isChecked()){
        dangerous = "Опасный груз";
    }
    if (ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(this,"Предупреждение!", "Стоимость грузоперевозки не указана!\nДействие отменено","OK");
        this->close();
    }else{
        float costtt = ui->lineEdit->text().toInt();
        emit returnCost(costtt,dangerous);
        this->close();
    }
}
