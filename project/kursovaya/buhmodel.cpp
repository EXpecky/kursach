#include "buhmodel.h"

buhModel::buhModel(QObject* parent)
    :QAbstractTableModel{parent}
{
    //m_users = db.showUsers();
    //orders.clear();
    //database.createOrderData(orders);
}

int buhModel::rowCount(const QModelIndex &parent) const
{
    return worksToCost.size();
}

int buhModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant buhModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return worksToCost[index.row()].Client;
        }
        if (index.column() == 1) {
            return worksToCost[index.row()].pointD;
        }
        if (index.column() == 2) {
            return worksToCost[index.row()].pointP;
        }
        if (index.column() == 3) {
            return worksToCost[index.row()].vesGruza;
        }
        if(index.column() == 4) {
            return worksToCost[index.row()].Discription;
        }

    }
    return {};
}

QVariant buhModel::headerData(int section, Qt::Orientation orientation, int role) const
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
            case 4:
                return "Описание";
            }
        }
        if (orientation = Qt::Vertical){
            return QString::number(section + 1);
        }
    }
    return {};
}

void buhModel::createCost()
{
    datadase.createCostZakaz(worksToCost);
}
int buhModel::getID(int index)
{
    return worksToCost.at(index).Id;
}
