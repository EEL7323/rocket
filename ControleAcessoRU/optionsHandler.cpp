#include "optionsHandler.h"
#include "ui_optionsHandler.h"
#include "historictransaction.h"
#include "serversocket.h"
#include "recharge.h"

OptionsHandler::OptionsHandler(QWidget *parent, QString reg) : QDialog(parent), ui(new Ui::OptionsHandler) {
    ui->setupUi(this);
    registration = reg;
}

OptionsHandler::~OptionsHandler() {
    delete ui;
}

/*
 * In case of a recharge request, the user is redirect to
 * another window.
 */
void OptionsHandler::on_recharge_pressed() {
    Recharge *rechargeWindow = new Recharge(this, registration);
    rechargeWindow->adjustSize();
    rechargeWindow->showMaximized();
}

/*
 * In case of an historic transaction request, a new object of
 * ServerSocket class is created and connected to the server.
 * If the connection was realized with success, the data read
 * from the server is showed for the user in another window.
 */
void OptionsHandler::on_historicTransaction_pressed() {
    ServerSocket testConnection;
    testConnection.connectToServer();
    if(testConnection.getStatus()) {
        testConnection.requestHistoricTransaction(registration);
        HistoricTransaction *historicWindow = new HistoricTransaction(this);
        historicWindow->adjustSize();
        historicWindow->showMaximized();
        historicWindow->showData();
    } else {
        qDebug() << "Not connected to server.";
    }
}

/*
 * In case of a request for access, this function
 * establish a connection whit the board using bluetooth.
 * A new code is asked for unlock the turnstile.
 */
void OptionsHandler::on_accessRequest_pressed() {

}

/*
 * In case of a request for leave RU, this function
 * establish a connection whit the board using bluetooth.
 * A new code is asked for unlock the turnstile.
 */
void OptionsHandler::on_outRequest_pressed() {

}
