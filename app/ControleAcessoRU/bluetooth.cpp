#include "bluetooth.h"
#include <QDebug>

/*
 * Constructor.
 * Responsible to create a bluetooth socket and connect some slots.
 */
Bluetooth::Bluetooth(QObject *parent) : QObject(parent) {
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));

    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    localAdapters = QBluetoothLocalDevice::allDevices();
}

/*
 * This function is responsible to discovery another devices
 * that are available to establish a bluetooth connection.
 * The objective here is discovery the board bluetooth.
 */
void Bluetooth::startDiscovery() {
    discoveryAgent->start();
    qDebug() << "Discovery start";
}

/*
 * When a new bluetooth device is discovered, this function
 * is executed. If the address found is equal to our board address,
 * a connection is realized.
 */
void Bluetooth::deviceDiscovered(const QBluetoothDeviceInfo &device) {
    QString address = device.address().toString();
    qDebug() << "Found new device:" << device.name() << '(' << address << ')';
    if (address == bluetoothAddress) {
        discoveryAgent->stop();

        // Pair devices
        QBluetoothLocalDevice *dev = new QBluetoothLocalDevice(localAdapters.at(0).address());
        dev->requestPairing(device.address(), dev->pairingStatus(localAdapters.at(0).address()));

        QBluetoothServiceInfo m_service;
        m_service.setDevice(device);
        // connect
        socket->connectToService(m_service);
    }
}

/*
 * This function is responsible to send data throught bluetooth
 * to the board.
 */
void Bluetooth::sendMessage(const QString &message) {
    QByteArray text = message.toUtf8() + '\n';
    socket->write(text);
}

/*
 * This function is responsible to read data throught bluetooth
 * from the board.
 */
void Bluetooth::readSocket() {
    if (!socket)
        return;

    while (socket->canReadLine()) {
        QByteArray line = socket->readLine();
    }
}

void Bluetooth::connected() {
    qDebug() << "ConnectToService done";
}

bool Bluetooth::getConnectionStatus() {
    return connectionStatus;
}
