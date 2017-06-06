#include "bluetooth.h"
#include <QDebug>

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");

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
        qDebug() << "Board found!";
        discoveryAgent->stop();

        // Pair devices
        QBluetoothLocalDevice *dev = new QBluetoothLocalDevice(localAdapters.at(0).address());
        if(!dev->pairingStatus(device.address())) {
            qDebug() << "Pairing...";
            dev->requestPairing(device.address(), QBluetoothLocalDevice::Paired);
        } else {
            qDebug() << "Device already paired.";
        }

        QBluetoothServiceInfo m_service;
        m_service.setDevice(device);
        // connect
        socket->connectToService(device.address(), QBluetoothUuid(serviceUuid));
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
bool Bluetooth::readSocket() {
    if (!socket)
        return false;

    QByteArray line;
    while (socket->canReadLine()) {
        line = socket->readLine();
    }
    if(line.at(0) == '1')
        return true;
    else
        return false;
}

void Bluetooth::connected() {
    qDebug() << "ConnectToService done";
    connectionStatus = true;
}

bool Bluetooth::getConnectionStatus() {
    return connectionStatus;
}
