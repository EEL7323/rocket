#include "bluetooth.h"

char receive_buffer[MAX_BUFFER_LENGTH];
int users_inside = 0;
int cred = 10;
short uartdata, i;
//std::string registry_str;  // creating an obj
//std::string str2 = "14101328"; // test const
String registry_str;  // creating an obj
String str2 = "14101328"; // test const
String uartString;
int access_free = 0;
void Bluetooth::initBluetooth(int baud_rate){
	Serial.begin(baud_rate);
}

short Bluetooth::receiveData(){  
  while(Serial.available() <=0 );
	uartdata = Serial.read();
	switch(uartdata){
		case REGISTRY:	
			i = 0;
     Serial.println("\n Please insert your registry");
			while(Serial.available() <=0 );
		//	while(uartdata != '\n'){
	//			receive_buffer[i] = (char)(uartdata);		// get registry 
		//		registry_str.concat(uartdata);	// concatenates chars 
   //  Serial.println("ta lendo");
		//	}

    uartString = Serial.readString();
   	i = 0;
    if(uartString.equals(str2)){  
        Serial.println(uartString);
        access_free = 1;
		//	if(str2 == registry_str){
				if(users_inside> MAX_RU_CAPACITY) 
					Serial.println("Max Capacity Reached");
				else {
					Serial.println("Registry OK");
					Serial.println("Users Inside: ");
					Serial.println(users_inside);
				}
			}
			else
				Serial.println("Registry not found");
			
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
      // while(Serial.read()!= "\n")
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

