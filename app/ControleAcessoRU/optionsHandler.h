#ifndef OPTIONSHANDLER_H
#define OPTIONSHANDLER_H

#include <QWidget>
#include <QDialog>
#include "login.h"
#include "bluetooth.h"

// This class handle the user actions on the second window

namespace Ui {
class OptionsHandler;
}

class OptionsHandler : public QDialog {
    Q_OBJECT

public:
    explicit OptionsHandler(QWidget *parent = 0, QString reg = 0, Bluetooth *connection = 0, QByteArray users = 0);
    ~OptionsHandler();

private slots:
    void on_recharge_clicked();
    void on_accessRequest_clicked();
    void on_outRequest_clicked();

public slots:

private:
    QString registration;
    Bluetooth *bluetoothConnection;
    Ui::OptionsHandler *ui;
};

#endif // OPTIONSHANDLER_H
