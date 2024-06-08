#include "db.h"

Db::~Db()
{

}

bool Db::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../DB/mydatabase.sqlite");
    if(db.open()){
        return true;
    }else{
        return false;
    }
}
void Db::closeDatabase()
{
    db.close();
}
QString Db::autorization(QString login, QString password)
{
    QSqlQuery aut;
    aut.prepare("SELECT Login, Password, Grade from DataU WHERE Login = :login and Password = :password");
    aut.bindValue(":login", login);
    aut.bindValue(":password", password);
    aut.exec();
    aut.next();
    return aut.value("Grade").toString();

}
bool Db::insertDataU(QString login, QString pass, QString grade)
{
    QSqlQuery insrt;
    insrt.prepare("INSERT INTO DataU values(:id, :Login, :Password, :Grade)");
    insrt.bindValue(":id", (Db::getLatID()+1));
    insrt.bindValue(":Login", login);
    insrt.bindValue(":Password", pass);
    insrt.bindValue(":Grade", grade);
    return insrt.exec();
}
bool Db::insertUsers(QString surname, QString name, QString patronomyc, QString email, QString number)
{
    QSqlQuery insrt;
    insrt.prepare("INSERT INTO Users values(:id, :Surname, :Name, :Patronomyc, :Number, :Email, :IdData)");
    insrt.bindValue(":Surname", surname);
    insrt.bindValue(":Name", name);
    insrt.bindValue(":Patronomyc",patronomyc);
    insrt.bindValue(":Number", number);
    insrt.bindValue(":Email", email);
    insrt.bindValue(":IdData", Db::getLatID());
    return insrt.exec();
}
int Db::getLatID()
{
    QSqlQuery getid;
    getid.prepare("SELECT * from DataU");
    getid.exec();
    getid.last();
    return getid.value("ID").toInt();
}
bool Db::correctLogin(QString login)
{
    QSqlQuery getLogin;
    getLogin.prepare("SELECT Login from DataU");
    getLogin.exec();
    while(getLogin.next()){
        if(getLogin.value("Login") == login){
            return false;
        }
    }
    return true;
}
bool Db::insertWorkers(QString surname, QString name, QString patronomyc, QString email, QString number)
{
    QSqlQuery insrt;
    insrt.prepare("INSERT INTO Workers values(:id, :Surname, :Name, :Patronomyc, :Number, :Email, :IdDataa)");
    insrt.bindValue(":Surname", surname);
    insrt.bindValue(":Name", name);
    insrt.bindValue(":Patronomyc",patronomyc);
    insrt.bindValue(":Number", number);
    insrt.bindValue(":Email", email);
    insrt.bindValue(":IdDataa", Db::getLatID());
    return insrt.exec();
}
bool Db::insertDriver(QString surname, QString name, QString patronomyc, QString email, QString number, int experience)
{
    QSqlQuery insrt;
    insrt.prepare("INSERT INTO Driver values(:id, :Surname, :Name, :Patronomyc, :Number, :Email, :Experience, :IdDataa)");
    insrt.bindValue(":Surname", surname);
    insrt.bindValue(":Name", name);
    insrt.bindValue(":Patronomyc",patronomyc);
    insrt.bindValue(":Number", number);
    insrt.bindValue(":Email", email);
    insrt.bindValue(":Experience", experience);
    insrt.bindValue(":IdDataa", Db::getLatID());

    return insrt.exec();
}
bool Db::insertOrders(QString login, QString discription, QString email, QString number, QString pointPogruzki, QString pointDostavki, int vesGruza)
{
    QSqlQuery insrt;
    insrt.prepare("INSERT INTO Orders values(:id, :idClient, :Discription, :Email, :Number, :PointPogruzki, :PointDostavki, :Ves, 'В рассмотрении')");
    insrt.bindValue(":idClient", Db::searchID(login));
    insrt.bindValue(":Discription", discription);
    insrt.bindValue(":Email", email);
    insrt.bindValue(":Number", number);
    insrt.bindValue(":PointPogruzki", pointPogruzki);
    insrt.bindValue(":PointDostavki", pointDostavki);
    insrt.bindValue(":Ves", vesGruza);
    return insrt.exec();
}
int Db::searchID(QString login)
{
    QSqlQuery query;
    query.prepare("SELECT Users.ID from Users "
                  "join DataU on Users.Data = DataU.ID "
                  "WHERE Login = :login");
    query.bindValue(":login", login);
    query.exec();
    query.next();

    return query.value("ID").toInt();
}
void Db::createOrderData(QVector<orderData>& orders)
{
    orders.clear();
    orderData order;
    this->openDatabase();
    QSqlQuery query;
    query.prepare("SELECT ID, (SELECT Surname from Users where Users.ID = Orders.Client) as 'Клиент', "
                  "PointPogruski as 'Адрес погрузки', PointDostavki as 'Адрес доставки', Discription as Описание, VesGruza as 'Вес', Email, Number, Grade from Orders "
                  "WHERE Grade = 'В рассмотрении'");
    query.exec();
    while(query.next()){

        order.Id = query.value(0).toInt();
        order.Client = query.value(1).toString();
        order.PointPogruski = query.value(2).toString();
        order.PointDostavki = query.value(3).toString();
        order.Discription = query.value(4).toString();
        order.VesGruza = query.value(5).toInt();
        order.Email = query.value(6).toString();
        order.Number = query.value(7).toString();
        order.Grade = query.value(8).toString();
        orders.append(order);
    }
    //qDebug()<<orders.at(0).Client;

}
/* */
bool Db::insertWorks(QString surnFDriver, QString nameFDriver, QString surnSDriver, QString nameSDriver, int idOrd)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Works "
                  "values(:id, :idOrder, :idDriver, :idSecondDriver, 0, 0, 0)");
    query.bindValue(":idOrder", idOrd);
    query.bindValue(":idDriver", searchDriver(surnFDriver, nameFDriver));
    query.bindValue(":idSecondDriver", searchDriver(surnSDriver, nameSDriver));
    qDebug() << idOrd << "1234567890";

    return query.exec();
}
bool Db::driverIsBusy(int idDriver)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(Works.ID) from Works "
                  "WHERE (Works.Driver = :idDriver or Works.Driver_second = :idSDriver) and Works.Grade = 'В пути'");
    query.bindValue(":idDriver", idDriver);
    query.bindValue(":idSDriver", idDriver);
    query.exec();
    query.next();
    if (query.value(0).toInt() == 0) return true;
    else return false;
}


void Db::selectDriver(QVector<QString>& driverVector)
{
    driverVector.clear();
    QString item;
    QSqlQuery query;
    query.prepare("SELECT Surname, Name, ID FROM Driver");
    query.exec();
    while(query.next()){
        if (this->driverIsBusy(query.value(2).toInt())) {
            item = query.value(0).toString();
            item += " ";
            item += query.value(1).toString();
            qDebug() << item;
            driverVector.append(item);
        }else continue;
    }
}
int Db::searchDriver(QString surname, QString name)
{
    QSqlQuery query;
    query.prepare("SELECT ID from Driver WHERE Surname = :surname and Name = :name");
    query.bindValue(":surname", surname);
    query.bindValue(":name", name);
    qDebug() << surname;
    query.exec();
    query.next();
    return query.value(0).toInt();
}
void Db::delOrder(int idOrder)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Orders WHERE ID = :id");
    query.bindValue(":id", idOrder);
    query.exec();
}
void Db::insertCancelOrder(int idOrder)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cancelOrder values(:id, :idOrder)");
    query.bindValue(":idOrder", idOrder);
    query.exec();
}
void Db::uodateAcceptOrders(int idOrder)
{
    QSqlQuery query;
    query.prepare("UPDATE Orders "
                  "SET Grade = 'Подтверждено' "
                  "WHERE ID = :idOrder");
    query.bindValue(":idOrder", idOrder);
    query.exec();
}
void Db::updateCancelOrders(int idOrder)
{
    QSqlQuery query;
    query.prepare("UPDATE Orders "
                  "SET Grade = 'Отказано' "
                  "WHERE ID = :idOrder");
    query.bindValue(":idOrder", idOrder);
    query.exec();
}
void Db::createUOrderData(QVector<orderData> &userOrders, int idClient)
{
    userOrders.clear();
    orderData order;
    QSqlQuery query;
    query.prepare("SELECT ID, Discription, Email, Number, PointPogruski, PointDostavki, VesGruza, Grade from Orders WHERE Grade != 'Подтверждено' and Client = :idClient");
    query.bindValue(":idClient", idClient);
    query.exec();
    while(query.next()){
        order.Id = query.value(0).toInt();
        order.Discription = query.value(1).toString();
        order.Email = query.value(2).toString();
        order.Number = query.value(3).toString();
        order.PointPogruski = query.value(4).toString();
        order.PointDostavki = query.value(5).toString();
        order.VesGruza = query.value(6).toInt();
        order.Grade = query.value(7).toString();
        userOrders.append(order);
    }
}
//QString Db::searchSurnClient(int idOrder)
//{
//    QSqlQuery query;
//    query.prepare("SELECT Client from Orders WHERE ID = ");
//}
void Db::createZakazData(QVector<activZakaz> &activWorks, int idDriver)
{
    activWorks.clear();
    activZakaz work;
    QSqlQuery query;
    query.prepare("SELECT Works.ID, Users.Surname, Orders.PointPogruski, Orders.PointDostavki, Orders.VesGruza, Orders.Discription, Users.Number from Works "
                  "JOIN Orders on Works.[Order] = Orders.ID "
                  "JOIN Users on Orders.Client = Users.ID "
                  "WHERE (Works.Driver = :idDriver or Works.Driver_second = :idSDriver) and (Works.Grade = '0' or Works.Grade = 'В пути') and Works.Cost != 0");
    query.bindValue(":idDriver", idDriver);
    query.bindValue(":idSDriver", idDriver);
    query.exec();
    while(query.next()){
        work.Id = query.value(0).toInt();
        work.Client = query.value(1).toString();
        work.pointP = query.value(2).toString();
        work.pointD = query.value(3).toString();
        work.vesGruza = query.value(4).toInt();
        work.Discription = query.value(5).toString();
        work.Number = query.value(6).toString();
        activWorks.append(work);
        //qDebug() << activWorks.at(0).Client;
    }
}
int Db::searchIdDriver(QString login)
{
    QSqlQuery query;
    query.prepare("SELECT Users.ID from Driver "
                  "join DataU on Driver.Data = DataU.ID "
                  "WHERE Login = :login");
    query.bindValue(":login", login);
    query.exec();
    query.next();
    return query.value("ID").toInt();
}
void Db::createCompleteZakazData(QVector<activZakaz> &zakazs, int idDriver)
{
    this->openDatabase();
    zakazs.clear();
    activZakaz work;
    QSqlQuery query;
    query.prepare("SELECT Works.ID, Users.Surname, Orders.PointPogruski, Orders.PointDostavki, Orders.VesGruza, Orders.Discription, Users.Number, Works.Cost from Works "
                  "JOIN Orders on Works.[Order] = Orders.ID "
                  "JOIN Users on Orders.Client = Users.ID "
                  "WHERE (Works.Driver = :idDriver or Works.Driver_second = :idSDriver) and Works.Grade = 'Доставлен' and Works.Cost != 0");
    query.bindValue(":idDriver", idDriver);
    query.bindValue(":idSDriver", idDriver);
    query.exec();
    while(query.next()){
        work.Id = query.value(0).toInt();
        work.Client = query.value(1).toString();
        work.pointP = query.value(2).toString();
        work.pointD = query.value(3).toString();
        work.vesGruza = query.value(4).toInt();
        work.Discription = query.value(5).toString();
        work.Number = query.value(6).toString();
        work.Cost = ((query.value(7).toFloat())/100)*25;
        zakazs.append(work);
    }
}
void Db::createCostZakaz(QVector<activZakaz> &worksToCost)
{
    this->openDatabase();
    worksToCost.clear();
    activZakaz work;
    QSqlQuery query;
    query.prepare("SELECT Works.ID, Users.Surname, Orders.PointPogruski, Orders.PointDostavki, Orders.VesGruza, Orders.Discription, Users.Number, Works.Cost from Works "
                  "JOIN Orders on Works.[Order] = Orders.ID "
                  "JOIN Users on Orders.Client = Users.ID "
                  "WHERE Works.Cost = 0");
    query.exec();
    while(query.next()){
        work.Id = query.value(0).toInt();
        work.Client = query.value(1).toString();
        work.pointP = query.value(2).toString();
        work.pointD = query.value(3).toString();
        work.vesGruza = query.value(4).toInt();
        work.Discription = query.value(5).toString();
        worksToCost.append(work);
    }
    this->closeDatabase();
}
void Db::insertCost(int index, float Cost, QString dangerous)
{
    this->openDatabase();
    QSqlQuery query;
    query.prepare("UPDATE Works "
                  "SET Cost = :cost, Dangerous = :dangerous "
                  "WHERE Works.ID = :index");
    query.bindValue(":cost",Cost);
    query.bindValue(":dangerous", dangerous);
    query.bindValue(":index",index);
    qDebug() << index;
    query.exec();
    this->closeDatabase();
}
void Db::createUWorks(QVector<activZakaz> &userWorks, int idU)
{
    this->openDatabase();
    userWorks.clear();
    activZakaz work;
    QSqlQuery query;
    query.prepare("SELECT Orders.PointPogruski, Orders.PointDostavki, Orders.VesGruza, Orders.Discription, Works.Cost, Works.Grade from Works "
                  "JOIN Orders on Works.[Order] = Orders.ID "
                  "WHERE Works.Cost != 0 and Orders.Client = :idU");
    query.bindValue(":idU",idU);
    query.exec();
    while(query.next()){
        work.pointP = query.value(0).toString();
        work.pointD = query.value(1).toString();
        work.vesGruza = query.value(2).toInt();
        work.Discription = query.value(3).toString();
        work.Cost = query.value(4).toFloat();
        work.Grade = query.value(5).toString();
        userWorks.append(work);
    }
    this->closeDatabase();
}
void Db::updateGradeWorks(QString grade, int idW)
{
    QSqlQuery query;
    query.prepare("UPDATE Works "
                  "SET Grade = :grade "
                  "WHERE ID = :idW");
    qDebug() << idW;
    query.bindValue(":idW",idW);
    query.bindValue(":grade", grade);
    query.exec();
}
bool Db::searchLogPass(QString login, QString pass)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) from DataU WHERE Login = :login and Password = :pass");
    query.bindValue(":login", login);
    query.bindValue(":pass",pass);
    query.exec();
    query.next();
    if (query.value(0).toInt() == 0) return false;
            else return true;

}


































