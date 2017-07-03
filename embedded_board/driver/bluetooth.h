#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <string>
#include "uart.h"
#include "msp430f5529_hal.h"
#include <msp430.h>
#include <stdint.h>
#include <stdio.h>
#include "dataManagement.h"

#define MAX_RU_CAPACITY		999
#define BAUD_RATE96			9600
#define BAUD_RATE11			11520
#define MAX_BUFFER_LENGTH 	20
// protocol commands
#define REGISTRY 			0x30
#define ACCESS 				0x31


class Bluetooth{
	public:
		//Bluetooth();
		//~Bluetooth();
		void receiveData(dataManagement &Manager);
		void transmitData(uint8_t* data);
		void initBluetooth(int baudrate);
	//	short verifyRegistry(short receivedata);
	};
	
	
#endif
