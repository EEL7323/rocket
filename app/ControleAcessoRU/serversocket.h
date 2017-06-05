#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

// This class handle the communication between APP and Server.

class ServerSocket : public QObject {
    Q_OBJECT

public:
    explicit ServerSocket(QObject *parent = 0);

    void connectToServer();
    void updateCredit(QString registration, QString value);
    void requestHistoricTransaction(QString registration);
    bool getStatus();

private:
    bool serverConnected = false;
};

#endif // SERVERSOCKET_H
