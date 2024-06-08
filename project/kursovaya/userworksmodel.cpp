#include "userworksmodel.h"


userWorksModel::userWorksModel(QObject *parent)
    :QAbstractTableModel{parent}
{

}
int userWorksModel::rowCount(const QModelIndex &parent) const
{
    return userWorks.size();
}

int userWorksModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant userWorksModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return userWorks[index.row()].pointP;
        }
        if (index.column() == 1) {
            return userWorks[index.row()].pointD;
        }
        if (index.column() == 2) {
            return userWorks[index.row()].vesGruza;
        }
        if (index.column() == 3) {
            return userWorks[index.row()].Discription;
        }
        if (index.column() == 4) {
            return userWorks[index.row()].Cost;
        }
        if (index.column() == 5) {
            return userWorks[index.row()].Grade;
        }
    }
    return {};
}

QVariant userWorksModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal){
            switch (section) {
            case 0:
                return "Адрес погрузки";
            case 1:
                return "Адрес доставки";
            case 2:
                return "Вес груза";
            case 3:
                return "Описание";
            case 4:
                return "Стоимость";
            case 5:
                return "Статус";
            }
        }
        if (orientation = Qt::Vertical){
            return QString::number(section + 1);
        }
    }
    return {};
}




void userWorksModel::createUWorks(const int id)
{

    database.createUWorks(userWorks, id);
}
