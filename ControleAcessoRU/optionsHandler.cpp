#include "optionsHandler.h"
#include "ui_optionsHandler.h"
#include "historictransaction.h"
#include "recharge.h"
#include "transition.h"

OptionsHandler::OptionsHandler(QWidget *parent, QString reg, Bluetooth *connection, QByteArray users) : QDialog(parent), ui(new Ui::OptionsHandler) {
    ui->setupUi(this);
    registration = reg;
    bluetoothConnection = connection;
    QString displayValue(users);
    ui->lcdNumber->display(displayValue);
}

OptionsHandler::~OptionsHandler() {
    delete ui;
}

/*
 * In case of a recharge request, the user is redirect to
 * another window.
 */
void OptionsHandler::on_recharge_clicked() {
    Recharge *rechargeWindow = new Recharge(this, registration, bluetoothConnection);
    rechargeWindow->adjustSize();
    rechargeWindow->showMaximized();
}

/*
 * In case of a historic transaction request, a new write and
 * data request are sent to the board through bluetooth to get
 * the values.
 */
void OptionsHandler::on_historicTransaction_clicked() {
    bluetoothConnection->sendMessage("4"); // this code means that a write request is beeing sent
    bluetoothConnection->sendMessage(registration);
    QByteArray value = bluetoothConnection->readSocket(); // read historic transaction

    HistoricTransaction *historicWindow = new HistoricTransaction(this, value);
    historicWindow->adjustSize();
    historicWindow->showMaximized();
}

/*
 * In case of an access request, the user is redirect to
 * another window.
 */
void OptionsHandler::on_accessRequest_clicked() {
    QString id = "1"; // this id means that a access request was made
    Transition *transitionWindow = new Transition(this, registration, bluetoothConnection, id);
    transitionWindow->adjustSize();
    transitionWindow->showMaximized();
}

/*
 * In case of a leave request, the user is redirect to
 * another window.
 */
void OptionsHandler::on_outRequest_clicked() {
    QString id = "0"; // this id means that a access request was made
    Transition *transitionWindow = new Transition(this, registration, bluetoothConnection, id);
    transitionWindow->adjustSize();
    transitionWindow->showMaximized();
}
