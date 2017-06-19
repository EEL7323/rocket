#ifndef TRANSITION_H
#define TRANSITION_H

#include <QDialog>
#include "bluetooth.h"

namespace Ui {
class Transition;
}

class Transition : public QDialog {
    Q_OBJECT

public:
    explicit Transition(QWidget *parent = 0, QString reg = 0, Bluetooth *connection = 0, QString id = 0);
    ~Transition();

    void sendOpenCommand();

private slots:
    void on_requestCaptcha_clicked();
    void on_verifyCaptcha_clicked();

private:
    QString registration;
    Bluetooth *bluetoothConnection;
    QString identification; // this variable identify if it is an access or leave request
    QByteArray response;
    Ui::Transition *ui;
};

#endif // TRANSITION_H
