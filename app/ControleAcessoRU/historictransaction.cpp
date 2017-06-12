#include "historictransaction.h"
#include "ui_historictransaction.h"

HistoricTransaction::HistoricTransaction(QWidget *parent) : QDialog(parent), ui(new Ui::HistoricTransaction) {
    ui->setupUi(this);
}

HistoricTransaction::~HistoricTransaction() {
    delete ui;
}

// Show data received from server
void HistoricTransaction::showData() {
    ui->userHistoric->setText("valores do servidor.");
}
