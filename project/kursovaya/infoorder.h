#ifndef INFOORDER_H
#define INFOORDER_H

#include <QWidget>

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
    void takeData(const QString client, const QString number, const QString email, const QString pointD, const QString pointP, const QString Discription, const int ves);

private slots:
    void on_accept_pushButton_clicked();


private:
    Ui::InfoOrder *ui;
};

#endif // INFOORDER_H
