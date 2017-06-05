#ifndef OPTIONSHANDLER_H
#define OPTIONSHANDLER_H

#include <QWidget>
#include <QDialog>
#include "login.h"

// This class handle the user actions on the second window

namespace Ui {
class OptionsHandler;
}

class OptionsHandler : public QDialog {
    Q_OBJECT

public:
    explicit OptionsHandler(QWidget *parent = 0, QString reg = 0);
    ~OptionsHandler();

private slots:
    void on_recharge_pressed();
    void on_historicTransaction_pressed();
    void on_accessRequest_pressed();
    void on_outRequest_pressed();

public slots:

private:
    QString registration;
    Ui::OptionsHandler *ui;
};

#endif // OPTIONSHANDLER_H
