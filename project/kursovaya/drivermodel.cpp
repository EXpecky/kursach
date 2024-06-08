#include "drivermodel.h"

driverModel::driverModel(QObject* parent)
    :QAbstractTableModel{parent}
{
    //m_users = db.showUsers();
    //orders.clear();
    //database.createOrderData(orders);
}

int driverModel::rowCount(const QModelIndex &parent) const
{
    return zakazs.size();
}

int driverModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant driverModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return zakazs[index.row()].pointD;
        }
        if (index.column() == 1) {
            return zakazs[index.row()].pointP;
        }
        if (index.column() == 2) {
            return zakazs[index.row()].Discription;
        }
        if (index.column() == 3) {
            return zakazs[index.row()].Cost;
        }
    }
    return {};
}

QVariant driverModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal){
            switch (section) {
            case 0:
                return "Адрес доставки";
            case 1:
                return "Адрес погрузки";
            case 2:
                return "Адрес описание";
            case 3:
                return "Выручка";
            }
        }
        if (orientation = Qt::Vertical){
            return QString::number(section + 1);
        }
    }
    return {};
}


void driverModel::createZakaz(int idDriver)
{
    database.createCompleteZakazData(zakazs, idDriver);
}
