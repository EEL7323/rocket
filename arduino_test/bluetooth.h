#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <iostream>
#include <string>

#define MAX_RU_CAPACITY		100
#define BAUD_RATE96			9600
#define BAUD_RATE11			11520
#define MAX_BUFFER_LENGTH 	20
// protocol commands
#define REGISTRY 			0xA0
#define ACCESS 				0xB0


class Bluetooth{
	public:
		Bluetooth();
		//~Bluetooth();
		short receiveData();
		short transmitData();
		void initBluetooth(int baudrate);
	//	short verifyRegistry(short receivedata);
	}
	
	
#endif BLUETOOTH_H_