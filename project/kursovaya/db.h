#ifndef DB_H
#define DB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QVector>

#include "orderdata.h"

class Db
{
public:
    ~Db();
private:
    QSqlDatabase db;
public:
    bool openDatabase();
    void closeDatabase();
    QString autorization(QString login, QString password);
    bool insertDataU(QString login, QString pass, QString grade);
    bool insertUsers(QString surname, QString name, QString patronomyc, QString email, QString number);
    int getLatID();
    bool correctLogin(QString login);
    bool insertWorkers(QString surname, QString name, QString patronomyc, QString email, QString number);
    bool insertDriver(QString surname, QString name, QString patronomyc, QString email, QString number, int experience);
    bool insertOrders(QString login, QString discription, QString email, QString number, QString pointPogruzki, QString pointDostavki, int vesGruza);
    int searchID(QString login);
    void createOrderData(QVector<orderData>& orders);
    bool insertWorks(QString surnFDriver, QString nameFDriver, QString surnSDriver, QString nameSDriver, int idOrd);
    void selectDriver(QVector<QString>& driverVector);
    int searchDriver(QString surname, QString name);
    //int searchIdDriver();
};

#endif // DB_H
