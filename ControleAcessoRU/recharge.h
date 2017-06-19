#ifndef RECHARGE_H
#define RECHARGE_H

#include <QDialog>
#include "bluetooth.h"

// This class handle the action of recharge the user credit

namespace Ui {
class Recharge;
}

class Recharge : public QDialog {
    Q_OBJECT

public:
    explicit Recharge(QWidget *parent = 0, QString reg = 0, Bluetooth *connection = 0);
    ~Recharge();

private slots:
    void on_recharge_clicked();
    void on_pushButton_clicked();

private:
    QString registration;
    Bluetooth *bluetoothConnection;
    Ui::Recharge *ui;
};

#endif // RECHARGE_H
