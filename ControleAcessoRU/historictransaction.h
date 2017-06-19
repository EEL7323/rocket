#ifndef HISTORICTRANSACTION_H
#define HISTORICTRANSACTION_H

#include <QDialog>
#include "bluetooth.h"

/*
 * This class is reponsible to show the user historic transaction
 */

namespace Ui {
class HistoricTransaction;
}

class HistoricTransaction : public QDialog {
    Q_OBJECT

public:
    explicit HistoricTransaction(QWidget *parent = 0, QByteArray dt = 0);
    ~HistoricTransaction();

    void showData();

private:
    QByteArray data;
    Ui::HistoricTransaction *ui;
};

#endif // HISTORICTRANSACTION_H
