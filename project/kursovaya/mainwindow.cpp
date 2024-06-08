#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Db database;


    regWindow = new registration();
    connect(regWindow, &registration::back, this, &MainWindow::show);

    adminWindow = new Administrator();
    connect(adminWindow, &Administrator::exit, this, &MainWindow::show);

    driverWindow = new Driver();
    connect(driverWindow, &Driver::exit, this, &MainWindow::show);

    userWindow = new User();
    connect(userWindow, &User::exit, this, &MainWindow::show);

    buhWindow = new Buh();
    connect(buhWindow, &Buh::exit, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_RegistrationPushB_clicked()
{
    regWindow->show();
    this->close();
}


void MainWindow::on_VoitiPushB_clicked()
{
    QString login = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    database.openDatabase();
    if (database.searchLogPass(login, pass)){

        if(database.autorization(login, pass) == "Администратор"){
            adminWindow->show();
            this->close();
        }else if(database.autorization(login, pass) == "Водитель"){
            driverWindow->setIdLogin(database.searchIdDriver(login),login);
            driverWindow->show();
            this->close();
        }else if(database.autorization(login, pass) == "Заказчик"){
            userWindow->setIdLogin(database.searchID(login), login);
            userWindow->show();
            this->close();
        }else if(database.autorization(login, pass) == "Бухгалтер"){
            buhWindow->show();
            this->close();
        }
    }else{
        QMessageBox::critical(this, "Ошибка!","Невернный логин или пароль!","OK");
    }
    database.closeDatabase();

}

