#ifndef DB_H
#define DB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QVector>

#include "orderdata.h"
#include "activzakaz.h"

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
    void delOrder(int idOrder);
    void insertCancelOrder(int idOrder);
    void uodateAcceptOrders(int idOrder);
    void updateCancelOrders(int idOrder);
    void createUOrderData(QVector<orderData>& userOrders, int idClient);
    QString searchSurnClient(int idOrder);
    void createZakazData(QVector<activZakaz>& activWorks, int idDriver);
    int searchIdDriver(QString login);
    bool driverIsBusy(int idDriver);
    void createCompleteZakazData(QVector<activZakaz> &zakazs, int idDriver);
    void createCostZakaz(QVector<activZakaz> &worksToCost);
    void insertCost(int index, float Cost, QString dangerous);
    void createUWorks(QVector<activZakaz> &userWorks, int idU);
    void updateGradeWorks(QString grade, int idW);
    bool searchLogPass(QString login, QString pass);
    //int searchIdDriver();
};

#endif // DB_H
