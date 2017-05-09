#ifndef SECONDINTERFACE_H
#define SECONDINTERFACE_H

#include <QWidget>

namespace Ui {
class SecondInterface;
}

class SecondInterface : public QWidget {
    Q_OBJECT

public:
    explicit SecondInterface(QWidget *parent = 0);
    ~SecondInterface();

private:
    Ui::SecondInterface *ui;
};

#endif // SECONDINTERFACE_H
