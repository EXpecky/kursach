#ifndef DRIVER_H
#define DRIVER_H

#include <QWidget>

namespace Ui {
class Driver;
}

class Driver : public QWidget
{
    Q_OBJECT

public:
    explicit Driver(QWidget *parent = nullptr);
    ~Driver();

signals:
    void exit();

private slots:
    void on_exit_clicked();

    void on_activOrder_button_clicked();

    void on_listDoneOrder_button_clicked();

    void on_back_button_2_clicked();

    void on_back_button_clicked();

private:
    Ui::Driver *ui;
};

#endif // DRIVER_H
