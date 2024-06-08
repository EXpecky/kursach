#ifndef USERMODEL_H
#define USERMODEL_H
#include "QAbstractTableModel"
#include <QVector>
#include "db.h"
#include "orderdata.h"

class userModel : public QAbstractTableModel
{
//public:
//    userModel();
public:
    explicit userModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QVector<orderData> &getUOrders();
    void createUOrders(const int id);
private:
    int direction = 0;
    QVector<orderData> userOrders;
    Db database;
};

#endif // USERMODEL_H
