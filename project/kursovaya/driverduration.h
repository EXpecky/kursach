#ifndef DRIVERDURATION_H
#define DRIVERDURATION_H

#include <QWidget>

namespace Ui {
class DriverDuration;
}

class DriverDuration : public QWidget
{
    Q_OBJECT

public:
    explicit DriverDuration(QWidget *parent = nullptr);
    ~DriverDuration();

signals:
    void getDuration();

private slots:
    void on_accept_button_clicked();

    void on_back_button_clicked();

public:
    int gDuration();

private:
    Ui::DriverDuration *ui;
};

#endif // DRIVERDURATION_H
