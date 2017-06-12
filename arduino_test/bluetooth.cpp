#include "bluetooth.h"

char receive_buffer[MAX_BUFFER_LENGTH];
int users_inside = 0;
int cred = 10;
short uartdata, i;
std::string registry_str;  // creating an obj
std::string str2 = "14101328"; // test const

Bluetooth::initBluetooth(int baud_rate){
	Serial.begin(baud_rate);
}

Bluetooth::receiveData(){
	uartdata = Serial.read();
	switch(uartdata){
		case REGISTRY:	
			i = 0;
			while(Serial.avaiable() <=0 );
			while(uartdata != '\n'){
				receive_buffer[i] = (char)(uartdata);		// get registry 
				registry_str.append(receive_buffer[i++]);	// concatenates chars 
			}
			i = 0;
			if(str2 == registry_str){
				users_inside++;
				if(users_inside> MAX_RU_CAPACITY) 
					Serial.write("Max Capacity Reached");
				else {
					Serial.write("Registry OK");
					Serial.write("Users Inside: ");
					Serial.write(users_inside);
				}
			}
			else
				Serial.write("Registry not found");
			
		break;
		
		case ACCESS:
			if(cred > 0){
				int captcha = 1234;
				Serial.write(captcha);
				while(Serial.avaiable() <=0 );
				int captcha_verify = Serial.read(uart_data);
				if (captcha_verify==captcha){
					// openTicket
					 cred--;
					 users_inside++;
				}
				else Serial.write("Error");
			}
			
			else Serial.write("Error");
		break;
	}
}


Bluetooth::transmitData(char data){
	Serial.write(data);
}

