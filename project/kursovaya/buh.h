#ifndef BUH_H
#define BUH_H

#include <QWidget>

namespace Ui {
class Buh;
}

class Buh : public QWidget
{
    Q_OBJECT

public:
    explicit Buh(QWidget *parent = nullptr);
    ~Buh();

signals:
    void exit();

private slots:
    void on_exit_clicked();

    void on_listZakazov_button_clicked();

    void on_back_button_clicked();

private:
    Ui::Buh *ui;
};

#endif // BUH_H
