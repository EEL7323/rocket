#include "interface.h"
#include "secondinterface.h"
#include "ui_interface.h"
#include <QPixmap>

Interface::Interface(QWidget *parent) : QWidget(parent), ui(new Ui::Interface) {
    ui->setupUi(this);

    connect(ui->inserirMatButton, SIGNAL(pressed()), this, SLOT(on_inserirMatButton_pressed()));
    // QPixmap pix(":images/ufsc-logo2.png");
    // ui->image->setPixmap(pix);
}

Interface::~Interface() {
    delete ui;
}

void Interface::on_inserirMatButton_pressed() {
    secondWindow = new SecondInterface(this);
    secondWindow->showMaximized();
}
