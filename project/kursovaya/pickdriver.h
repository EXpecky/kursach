#ifndef PICKDRIVER_H
#define PICKDRIVER_H

#include <QWidget>
#include <QMessageBox>
#include <QMessageBox>
#include "db.h"
#include "driverdata.h"

namespace Ui {
class PickDriver;
}

class PickDriver : public QWidget
{
    Q_OBJECT

public:
    explicit PickDriver(QWidget *parent = nullptr);
    ~PickDriver();

signals:
    void back();
    void accept(const QString name, const QString secName, const bool flag);

private slots:
    void on_back_pushButton_clicked();

    void on_addSecond_pushButton_clicked();

    void on_daleteSecond_pushButton_clicked();

    void on_accept_pushButton_clicked();

private:
    Ui::PickDriver *ui;
    Db database;
};

#endif // PICKDRIVER_H
