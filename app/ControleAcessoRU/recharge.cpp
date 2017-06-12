#include "recharge.h"
#include "ui_recharge.h"
#include "serversocket.h"

Recharge::Recharge(QWidget *parent, QString reg) : QDialog(parent), ui(new Ui::Recharge) {
    ui->setupUi(this);
    registration = reg;
}

Recharge::~Recharge() {
    delete ui;
}

/*
 * The user will insert the value to be recharged in his
 * account. After this, a connection with the server is
 * established and the value passed by the user updates the database.
 */
void Recharge::on_recharge_pressed() {
    ServerSocket testConnection;
    testConnection.connectToServer();
    if(testConnection.getStatus()) {
        ui->statusArea->append("Conexão com servidor estabelecida.");
        testConnection.updateCredit(registration, ui->lineEdit->text());
        ui->statusArea->append("Créditos atualizados com sucesso.");
    } else {
        ui->statusArea->append("Não foi possível conectar ao servidor. Tente novamente.");
    }
}

void Recharge::on_pushButton_pressed() {
    QString val = ui->lineEdit->text();
    double credit = val.toDouble();
    credit *= 1.5;
    ui->rechargePrice->setText(QString("%1").arg(credit));

}
