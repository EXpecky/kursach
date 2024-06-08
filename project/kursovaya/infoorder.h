#ifndef INFOORDER_H
#define INFOORDER_H

#include <QWidget>
#include "orderdata.h"
namespace Ui {
class InfoOrder;
}

class InfoOrder : public QWidget
{
    Q_OBJECT

public:
    explicit InfoOrder(QWidget *parent = nullptr);
    ~InfoOrder();

public slots:
    void takeData(const QVector<orderData> &orders, const int index);

private slots:
    void on_accept_pushButton_clicked();


private:
    Ui::InfoOrder *ui;
};

#endif // INFOORDER_H
