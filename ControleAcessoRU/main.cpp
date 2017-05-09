#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Interface w;
    w.showMaximized();

    return a.exec();
}
