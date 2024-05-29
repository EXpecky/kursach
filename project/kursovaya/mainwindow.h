#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registration.h"
#include "administrator.h"
#include "db.h"
#include "driver.h"
#include "user.h"
#include "buh.h"
//


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RegistrationPushB_clicked();

    void on_VoitiPushB_clicked();

private:
    Ui::MainWindow *ui;
    registration *regWindow;
    Administrator *adminWindow;
    Db database;
    Driver *driverWindow;
    User *userWindow;
    Buh *buhWindow;

};
#endif // MAINWINDOW_H
