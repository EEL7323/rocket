#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include "secondinterface.h"

namespace Ui {
class Interface;
}

class Interface : public QWidget {
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

private slots:
    void on_inserirMatButton_pressed();

private:
    Ui::Interface *ui;
    SecondInterface *secondWindow;
};

#endif // INTERFACE_H
