#include "adminmodel.h"

#include <algorithm>

AdminModel::AdminModel(QObject* parent)
    :QAbstractTableModel{parent}
{
    //m_users = db.showUsers();
    //orders.clear();
    //database.createOrderData(orders);
}

int AdminModel::rowCount(const QModelIndex &parent) const
{
    return orders.size();
}

int AdminModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant AdminModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return orders[index.row()].Client;
        }
        if (index.column() == 1) {
            return orders[index.row()].PointDostavki;
        }
        if (index.column() == 2) {
            return orders[index.row()].PointPogruski;
        }
        if (index.column() == 3) {
            return orders[index.row()].VesGruza;
        }
    }
    return {};
}

QVariant AdminModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal){
            switch (section) {
            case 0:
                return "Клиент";
            case 1:
                return "Адрес доставки";
            case 2:
                return "Адрес погрузки";
            case 3:
                return "Вес груза";
            }
        }
        if (orientation = Qt::Vertical){
            return QString::number(section + 1);
        }
    }
    return {};
}

int AdminModel::getId(int index)
{
    return orders.at(index).Id;
}

QString AdminModel::getClieint(int index)
{
    return orders.at(index).Client;
}
QString AdminModel::getDescription(int index)
{
    return orders.at(index).Discription;
}
QString AdminModel::getEmail(int index)
{
    return orders.at(index).Email;
}
QString AdminModel::getNumberPhone(int index)
{
    return orders.at(index).Number;
}
QString AdminModel::getPointDostav(int index)
{
    return orders.at(index).PointDostavki;
}
QString AdminModel::getPointPogruz(int index)
{
    return orders.at(index).PointPogruski;
}
int AdminModel::getVes(int index)
{
    return orders.at(index).VesGruza;
}
void AdminModel::createOrders()
{
    database.createOrderData(orders);
}
//}
