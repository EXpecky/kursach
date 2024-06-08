#include "usermodel.h"
#include <algorithm>

userModel::userModel(QObject *parent)
    :QAbstractTableModel{parent}
{

}
int userModel::rowCount(const QModelIndex &parent) const
{
    return userOrders.size();
}

int userModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant userModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return userOrders[index.row()].PointPogruski;
        }
        if (index.column() == 1) {
            return userOrders[index.row()].PointDostavki;
        }
        if (index.column() == 2) {
            return userOrders[index.row()].VesGruza;
        }
        if (index.column() == 3) {
            return userOrders[index.row()].Discription;
        }
        if (index.column() == 4) {
            return userOrders[index.row()].Grade;
        }
    }
    return {};
}

QVariant userModel::headerData(int section, Qt::Orientation orientation, int role) const
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
                return "Статус";
            }
        }
        if (orientation = Qt::Vertical){
            return QString::number(section + 1);
        }
    }
    return {};
}


QVector<orderData>& userModel::getUOrders()
{
    return this->userOrders;
}

void userModel::createUOrders(const int id)
{
    database.openDatabase();
    database.createUOrderData(this->userOrders, id);
}
