#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDialog>
#include <QString>

#include "optionsHandler.h"
#include "bluetooth.h"

// APP initial window

namespace Ui {
    class Login;
}

class Login : public QDialog {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    bool registrationValidation(QString reg);

private slots:
    void on_inserirMatButton_clicked();
    void on_pushButton_clicked();

private:
    QString registration;
    QByteArray usersInside;
    Bluetooth *bluetoothConnection;
    Ui::Login *ui;
};

#endif // LOGIN_H
