#ifndef USERWORKSMODEL_H
#define USERWORKSMODEL_H
#include <QAbstractTableModel>
#include "db.h"
#include "activzakaz.h"
class userWorksModel : public QAbstractTableModel
{
//public:
//    userWorksModel();
public:
    explicit userWorksModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;


    void createUWorks(const int id);
private:
    Db database;
    QVector<activZakaz> userWorks;

};

#endif // USERWORKSMODEL_H
