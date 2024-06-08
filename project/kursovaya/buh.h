#ifndef BUH_H
#define BUH_H

#include <QWidget>
#include <buhmodel.h>
#include <cost.h>
#include "db.h"

namespace Ui {
class Buh;
}

class Buh : public QWidget
{
    Q_OBJECT

public:
    explicit Buh(QWidget *parent = nullptr);
    ~Buh();

signals:
    void exit();

private slots:
    void on_exit_clicked();

    void on_listZakazov_button_clicked();

    void on_back_button_clicked();

    void on_tableView_doubleClicked();

    void createCost(const float Costtt, const QString dangerous);

private:
    Ui::Buh *ui;
    buhModel *costModel;
    Cost *costWindow;
    int index = 0;
    Db database;

};

#endif // BUH_H
