#include "historictransaction.h"
#include "ui_historictransaction.h"

HistoricTransaction::HistoricTransaction(QWidget *parent, QByteArray dt) : QDialog(parent), ui(new Ui::HistoricTransaction) {
    ui->setupUi(this);
    data = dt;
}

HistoricTransaction::~HistoricTransaction() {
    delete ui;
}

// Show data received from server
void HistoricTransaction::showData() {
    ui->userHistoric->append("valores do usuário.");
}
