#ifndef RECHARGE_H
#define RECHARGE_H

#include <QDialog>

// This class handle the action of recharge the user credit

namespace Ui {
class Recharge;
}

class Recharge : public QDialog {
    Q_OBJECT

public:
    explicit Recharge(QWidget *parent = 0, QString reg = 0);
    ~Recharge();

private slots:
    void on_recharge_pressed();

    void on_pushButton_pressed();

private:
    QString registration;
    Ui::Recharge *ui;
};

#endif // RECHARGE_H
