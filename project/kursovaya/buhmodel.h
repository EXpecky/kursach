#ifndef BUHMODEL_H
#define BUHMODEL_H
#include <QAbstractTableModel>
#include"activzakaz.h"
#include"db.h"
class buhModel : public QAbstractTableModel
{
//public:
//    buhModel();

public:
    explicit buhModel(QObject *parent = nullptr);
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void createCost();
    int getID(int index);

private:
    int direction = 0;
    QVector<activZakaz> worksToCost;
    Db datadase;
};

#endif // BUHMODEL_H
