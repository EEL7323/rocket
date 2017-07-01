#include "transition.h"
#include "ui_transition.h"

Transition::Transition(QWidget *parent, QString reg, Bluetooth *connection, QString id) : QDialog(parent), ui(new Ui::Transition) {
    ui->setupUi(this);
    registration = reg;
    bluetoothConnection = connection;
    identification = id;
}

Transition::~Transition() {
    delete ui;
}

/*
 * That functions sends the captcha value inserted by the user
 * to the board, witch is responsible to compare this value to
 * that was generated on the board routine.
 */
void Transition::sendOpenCommand() {
    QString captcha = ui->captchaInserted->text();
    bluetoothConnection->sendMessage(captcha); // request to open the turnstile
    bluetoothConnection->sendMessage(registration);
    QByteArray requestReturn = bluetoothConnection->readSocket();
    if(requestReturn.startsWith("1")) {
        ui->textBrowser->append("Catraca liberada.");
    } else {
        ui->textBrowser->append("Captcha errado.");
    }
}

/*
 * This function requests a new captcha value to the board.
 */
void Transition::on_requestCaptcha_clicked() {
    if(identification == "1") {
        bluetoothConnection->sendMessage("1"); // this code means that a access request is beeing sent
        bluetoothConnection->sendMessage(registration);
        ui->requestCaptcha->setEnabled(false);
        QByteArray requestReturn = bluetoothConnection->readSocket();
        if(requestReturn.startsWith("1")) {
            ui->textBrowser->append("Captcha solicitado.");
        } else {
            ui->textBrowser->append("Você não tem créditos.");
        }
        ui->verifyCaptcha->setEnabled(true);
    } else {
        bluetoothConnection->sendMessage("2"); // this code means that a leave request is beeing sent
        bluetoothConnection->sendMessage(registration);
        ui->requestCaptcha->setEnabled(false);
        QByteArray requestReturn = bluetoothConnection->readSocket();
        if(requestReturn.startsWith("1")) {
            ui->textBrowser->append("Captcha solicitado.");
        }
        ui->verifyCaptcha->setEnabled(true);
    }
}

void Transition::on_verifyCaptcha_clicked() {
    sendOpenCommand();
}
