#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "Arduino.h"

#define MAX_RU_CAPACITY		100
#define BAUD_RATE96			9600
#define BAUD_RATE11			11520
#define MAX_BUFFER_LENGTH 	20

// protocol commands
#define REGISTRY 			0x30
#define ACCESS 				0x31


class Bluetooth{
	public:
		// Bluetooth();
		// ~Bluetooth();
		short receiveData();
		short transmitData(char* data);
		void initBluetooth(int baudrate);
	  // short verifyRegistry(short receivedata);
	};
	
	
#endif BLUETOOTH_H_
