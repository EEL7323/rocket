#include "recharge.h"
#include "ui_recharge.h"

Recharge::Recharge(QWidget *parent, QString reg, Bluetooth *connection) : QDialog(parent), ui(new Ui::Recharge) {
    ui->setupUi(this);
    registration = reg;
    bluetoothConnection = connection;
}

Recharge::~Recharge() {
    delete ui;
}

/*
 * The user will insert the value to be recharged in his
 * account. After this, the value is sent to the board
 * through bluetooth.
 */
void Recharge::on_recharge_clicked() {
    bluetoothConnection->sendMessage("3"); // this code means that a recharge request is beeing sent
    bluetoothConnection->sendMessage(registration);
    QString rechargeValue = ui->credit->text();
    bluetoothConnection->sendMessage(rechargeValue);
    QByteArray requestReturn = bluetoothConnection->readSocket();
    if(requestReturn.startsWith("1")) {
        ui->statusArea->append("Créditos atualizados com sucesso.");
    } else {
        ui->statusArea->append("Não foi possível recarregar.");
    }
}

/*
 * Calculates and prints the price that corresponds to the number of
 * credits requested by the user.
 */
void Recharge::on_pushButton_clicked() {
    QString val = ui->credit->text();
    double credit = val.toDouble();
    credit *= 1.5;
    ui->rechargePrice->setText(QString("%1").arg(credit));

}
