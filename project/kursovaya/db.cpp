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
    insrt.prepare("INSERT INTO Orders values(:id, :idClient, :Discription, :Email, :Number, :PointPogruzki, :PointDostavki, :Ves)");
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
    qDebug() << query.value("ID").toInt() << 123;
    return query.value("ID").toInt();
}
void Db::createOrderData(QVector<orderData>& orders)
{
    orders.clear();
    orderData order;
    this->openDatabase();
    QSqlQuery query;
    query.prepare("SELECT ID, (SELECT Surname from Users where Users.ID = Orders.Client) as 'Клиент', "
                  "PointPogruski as 'Адрес погрузки', PointDostavki as 'Адрес доставки', Discription as Описание, VesGruza as 'Вес', Email, Number from Orders");
    query.exec();
    while(query.next()){
        qDebug() << " createOrderData" <<query.value(0).toString();
        order.Id = query.value(0).toInt();
        order.Client = query.value(1).toString();
        order.PointPogruski = query.value(2).toString();
        order.PointDostavki = query.value(3).toString();
        order.Discription = query.value(4).toString();
        order.VesGruza = query.value(5).toInt();
        order.Email = query.value(6).toString();
        order.Number = query.value(7).toString();
        orders.append(order);
    }
    //qDebug()<<orders.at(0).Client;

}
/* */
bool Db::insertWorks(QString surnFDriver, QString nameFDriver, QString surnSDriver, QString nameSDriver, int idOrd)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Works "
                  "values(:id, :idOrder, :idDriver, :idSecondDriver)");
    query.bindValue(":idOrder", idOrd);
    query.bindValue(":idDriver", searchDriver(surnFDriver, nameFDriver));
    query.bindValue(":idSecondDriver", searchDriver(surnSDriver, nameSDriver));

    return query.exec();
}

void Db::selectDriver(QVector<QString>& driverVector)
{
    driverVector.clear();
    QString item;
    QSqlQuery query;
    query.prepare("SELECT Surname, Name FROM Driver");
    query.exec();
    while(query.next()){
        item = query.value(0).toString();
        item += " ";
        item += query.value(1).toString();
        qDebug() << item;
        driverVector.append(item);
    }
}
int Db::searchDriver(QString surname, QString name)
{
    QSqlQuery query;
    query.prepare("SELECT ID from Driver WHERE Surname = :surname and Name = :name");
    query.bindValue(":surname", surname);
    query.bindValue(":name", name);
    query.exec();
    return query.next();
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












































