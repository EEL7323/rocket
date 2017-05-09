#ifndef INTERFACE2_H
#define INTERFACE2_H
#include "interface.h"

namespace Ui {
class Interface2;
}

class Interface2 : public QWidget {
    Q_OBJECT
public:
    explicit Interface2(QWidget *parent = 0);
    // ~Interface2();

private:
    Interface* mainWindow;
    Ui::Interface *ui;

signals:

public slots:
};

#endif // INTERFACE2_H
