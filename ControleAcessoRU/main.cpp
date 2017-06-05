#include "login.h"
#include <QApplication>

// Make all this work together

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Login w;
    w.showMaximized();

    return a.exec();
}
