#include "secondinterface.h"
#include "ui_secondinterface.h"

SecondInterface::SecondInterface(QWidget *parent) : QWidget(parent), ui(new Ui::SecondInterface) {
    ui->setupUi(this);
}

SecondInterface::~SecondInterface() {
    delete ui;
}
