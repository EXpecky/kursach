#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QMessageBox>
#include "db.h"
#include <QRegularExpressionValidator>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

signals:
    void back();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    bool correctNumber(QString number);

private:
    Ui::registration *ui;
    Db database;
    QRegularExpressionValidator *validator;
};

#endif // REGISTRATION_H
