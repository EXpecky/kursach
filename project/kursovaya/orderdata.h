#ifndef ORDERDATA_H
#define ORDERDATA_H

#include <QString>

class orderData
{
public:
    orderData();
    int Id;
    QString Client;
    QString Discription;
    QString Email;
    QString Number;
    QString PointPogruski;
    QString PointDostavki;
    int VesGruza;
    QString Grade;
};

#endif // ORDERDATA_H
