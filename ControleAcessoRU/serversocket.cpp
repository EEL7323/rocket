#include "serversocket.h"

ServerSocket::ServerSocket(QObject *parent) : QObject(parent) {

}

/*
 * This function establish the connection between app and
 * server, passing the IP and Port.
 */
void ServerSocket::connectToServer() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.1.60");
    db.setPort(5432);
    db.setDatabaseName("rocket_server");
    db.setUserName("mfrata");
    db.setPassword("sudofrata");

    if(db.open()) {
        serverConnected = true;
    } else {
        qDebug() << "Not connected to database";
    }
}

/*
 * This function is used for update the user credit. This
 * is made writting a request to the server database.
 */
void ServerSocket::updateCredit(QString registration, QString value) {
    QString request = QString("select credit from students where id = %1").arg(registration);
    QSqlQuery queryRead;
    queryRead.exec(request);
    qDebug() << "Query was executed!";
    double credit;
    if(queryRead.first()) {
        qDebug() << "Value read: " << queryRead.value(0).toString();
        credit = queryRead.value(0).toString().toDouble(); // verificar se está certo
        credit += value.toDouble();
        QString val = QString("%1").arg(credit);
        request = QString("update students set credit = %1 where id = %2").arg(val, registration);
        QSqlQuery queryUpdate(request);
    }
}

/*
 * This function is used for read the user historic transaction.
 * This is made writting a request to the server database.
 */
void ServerSocket::requestHistoricTransaction(QString registration) {
    QString request = QString("select * from students where id = %1").arg(registration);
    QSqlQuery query(request);
    // int fieldNo = query.record().indexOf("credit");
    while(query.next()) {
          QString hstTransaction = query.value(0).toString();
          // QSqlQueryModel to model the data received. (Qt 55 - QSqlQueryModel)
    }
}

bool ServerSocket::getStatus() {
    return serverConnected;
}
