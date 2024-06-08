#ifndef DRIVERMODEL_H
#define DRIVERMODEL_H
#include <QAbstractTableModel>
#include <QVector>
#include "db.h"
#include "activzakaz.h"
class driverModel : public QAbstractTableModel
{
//public:
//    driverModel();
public:
    explicit driverModel(QObject *parent = nullptr);
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void createZakaz(int idDriver);

private:
    int direction = 0;
    QVector<activZakaz> zakazs;
    Db database;
};

#endif // DRIVERMODEL_H
