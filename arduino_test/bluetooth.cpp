#include "bluetooth.h"

char receive_buffer[MAX_BUFFER_LENGTH];
int users_inside = 0;
int cred = 10;
short uartdata, i;  
int tamanho;
//std::string registry_str;  // creating an obj
//std::string str2 = "14101328"; // test const
String registry_str;  // creating an obj
String str2 = "123"; // test const
String uartString;
int access_free = 0;
void Bluetooth::initBluetooth(int baud_rate){
	Serial.begin(baud_rate);
}

short Bluetooth::receiveData(){  
  while(Serial.available() <=0 );
  uartString = Serial.readString();
  char cmd = uartString.charAt(0);
	uartdata = (short)(cmd)-48;
	switch(uartdata){
		case 0:	
      Serial.println("deuuu");
     // uartString = Serial.readString();
      tamanho = uartString.length();
		//	while(Serial.available() <=0 );  
			uartString.remove(tamanho-1,1);
      uartString.remove(0,2);
      Serial.println(uartString);
      
      if(uartString.equals(str2)){
        access_free = 1;
        Serial.write("1\n");
				if(users_inside >= MAX_RU_CAPACITY)
            Serial.println("Max RU Capacity Reached");
				else 
				    Serial.println("Users Inside " +users_inside);
			}
			else {
          Serial.println("0");
				   Serial.println("Registry not found");
			}   
			
		break;
		
		case ACCESS:
    if(access_free==0){
      Serial.println("Login Failed");
      
    }
			if(cred > 0){
				String captcha = "1234";
				label: 
				Serial.println("Captcha" + captcha);
				while(Serial.available() <=0 );
				String captcha_verify = Serial.readString();
				if (captcha_verify.equals(captcha)){
          Serial.println("abriu catraca");
					// openTicket
					 cred--;
					 users_inside++;
				}
				else
				  {
				    Serial.write("Error: Captch Wrong, insert correctly \n");
				    goto label;
				  }
			}
			else Serial.write("Error: you haven't cred");
		break;
	}
}
short Bluetooth::transmitData(char* data){
	Serial.write(data);
}

