#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <qbluetoothserver.h>
#include <qbluetoothservicediscoveryagent.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothlocaldevice.h>

// This class handle the communication between APP and Board.

class Bluetooth : public QObject {
    Q_OBJECT

public:
    explicit Bluetooth(QObject *parent = 0);

    void startDiscovery();
    bool getConnectionStatus();

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void connected();
    void readyRead();

public slots:
    void sendMessage(const QString &message);
    QByteArray readSocket();

private:
    QString bluetoothAddress = "20:13:07:29:14:44"; // Board bluetooth address
    QBluetoothSocket *socket;
    QList<QBluetoothHostInfo> localAdapters;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    bool connectionStatus = false;
};

#endif // BLUETOOTH_H
