#include "login.h"
#include "ui_login.h"
#include "bluetooth.h"
#include "optionsHandler.h"
#include "info.h"
#include <QDebug>

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    connect(ui->inserirMatButton, SIGNAL(clicked()), this, SLOT(on_inserirMatButton_pressed()));

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
    bluetoothConnection->sendMessage("0"); // this code means that a write request is beeing sent
    bluetoothConnection->sendMessage(reg);

    QByteArray response;
    response = bluetoothConnection->readSocket(); // read OK response and number of students using RU

    qDebug() << "Response: " << response;

    if(response.startsWith("1")) {
        int size = response.size();
        usersInside = response.left(size - 1);
        usersInside = usersInside.right(usersInside.size() - 1);
        qDebug() << "Users inside: " << usersInside;
        return true;
    } else {
        return false;
    }
}

/*
 * This function is responsible to get the data inserted
 * by the user in a text box. After validate it, the user
 * is allowed to access the second window of the APP where
 * new funcionalities are showed. Otherwise, a error message
 * is showed.
 */
void Login::on_inserirMatButton_clicked() {
    registration = ui->lineEdit->text();
    qDebug() << registration;
    if(bluetoothConnection->getConnectionStatus()) {
        if(registrationValidation(registration)) {
            OptionsHandler *secondWindow = new OptionsHandler(this, registration, bluetoothConnection, usersInside);
            secondWindow->adjustSize();
            secondWindow->showMaximized();
        } else {
            ui->lineEdit->setText("Matrícula inválida!");
        }
    } else {
        ui->lineEdit->setText("Aguarde conexão com a catraca!");
    }
}

void Login::on_pushButton_clicked() {
    Info *infoWindow = new Info(this);
    infoWindow->adjustSize();
    infoWindow->showMaximized();
}
