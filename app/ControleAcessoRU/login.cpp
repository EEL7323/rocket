#include "login.h"
#include "ui_login.h"
#include "bluetooth.h"
#include "optionsHandler.h"
#include <QDebug>

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    connect(ui->inserirMatButton, SIGNAL(pressed()), this, SLOT(on_inserirMatButton_pressed()));

    // fazer teste sem usar ponteiro
    bluetoothConnection = new Bluetooth(this);
    bluetoothConnection->startDiscovery();
}

Login::~Login() {
    delete ui;
}

/*
 * This function is responsible to validate the registration
 * inserted by the user. To do that, a bluetooth connection
 * with the board is realized and the registration is sent.
 */
bool Login::registrationValidation(QString reg) {
    if(reg == "1")
        return true;
    else
        return false;
    /*
    if(bluetoothConnection->getConnectionStatus()) {
        bluetoothConnection->sendMessage("06"); // this code means that a write request is beeing sent
        bluetoothConnection->sendMessage(reg);
        bluetoothConnection->readSocket(); // read OK response and number of students using RU
    }
    */
}

/*
 * This function is responsible to get the data inserted
 * by the user in a text box. After validate it, the user
 * is allowed to access the second window of the APP where
 * new funcionalities are showed. Otherwise, a error message
 * is showed.
 */
void Login::on_inserirMatButton_pressed() {
    registration = ui->lineEdit->text();
    qDebug() << registration;
    if(registrationValidation(registration)) {
        OptionsHandler *secondWindow = new OptionsHandler(this, registration);
        secondWindow->adjustSize();
        secondWindow->showMaximized();
    } else {
        ui->lineEdit->setText("Matrícula inválida!");
    }
}
