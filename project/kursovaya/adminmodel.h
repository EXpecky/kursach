#ifndef ADMINMODEL_H
#define ADMINMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "db.h"
#include "orderdata.h"
//#include "user.h"
class AdminModel : public QAbstractTableModel
{
//public:
//    AdminModel();
public:
    explicit AdminModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    int getId (int index);
    QString getClieint (int index);
    QString getPointDostav (int index);
    QString getPointPogruz (int index);
    QString getDescription (int index);
    QString getEmail (int index);
    QString getNumberPhone (int index);
    int getVes (int index);

    void createOrders();
   // void sortByLogin();



private:

    int direction = 0;
    QVector<orderData> orders;
    Db database;
};

#endif // ADMINMODEL_H
