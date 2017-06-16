#include "bluetooth.h"

char receive_buffer[MAX_BUFFER_LENGTH];
int users_inside = 10;
int cred = 10;
short uartdata, i;  
int tamanho;
String registry_str;  // creating an obj
String str2 = "123"; // test const
//std::string str2 = "14101328"; // test const
String uartString;
int access_free = 0;

void Bluetooth::initBluetooth(int baud_rate){
	Serial.begin(baud_rate);
}

short Bluetooth::receiveData() {
  while(Serial.available() <=0);
  uartString = Serial.readString();
  // extrair comando do protocolo de comunicação
  char cmd = uartString.charAt(0);
	uartdata = (short)(cmd)-48;
  // extrair matrícula
  tamanho = uartString.length();
  uartString.remove(0,1);
	switch(uartdata) {
		case 0:	{ // LOGIN
      // str2 vai ser pego fazendo uma varredura na lista
      if(uartString.equals(str2)) {
          access_free = 1;
          String str;
          str = String(users_inside);
          Serial.print("1"+str+"\n");
          //char* command = "1";
          //sprintf(command,"%s%i%",command,users_inside);
          //transmitData(command);
			} else {
          char* command = "0";
          sprintf(command,"%s%i%",command,0);
          transmitData(command);
			}   
	    } break;
		
		case 1: { // ACCESS 
  			if(cred > 0){
          Serial.print("1\n");
  				String captcha = "1234";
          // mostrar captcha nos LEDS
  				label:
  				while(Serial.available() <=0 );
  				String captcha_verify = Serial.readString();
          Serial.print(captcha_verify);
  				if (captcha_verify.equals(captcha)) {
  					 cred--;
             if(users_inside <= MAX_RU_CAPACITY)
  					    users_inside++;
             Serial.print("1\n");
  				} else {
  				    Serial.print("4\n");
  				    goto label; // vai ficar preso aqui se errar? Fazer 3 tentativas e dar break.
  				}
  			} else {
  			  Serial.print("5"); // enviar comando que indica falta de crédito
  			}
        } break;
    
     case 2: { // LEAVE  
          Serial.print("1\n");       
          String captcha = "1234";
          // mostrar captcha nos LEDS
          label2:
          while(Serial.available() <=0 );
          String captcha_verify = Serial.readString();
          Serial.print(captcha_verify);
          if (captcha_verify.equals(captcha)) {
             users_inside--;
             Serial.print("1\n");
          } else {
              Serial.print("4\n");
              goto label2;
          }
          } break;

    case 3: { // RECHARGE
          while(Serial.available() <=0 );
          String rechargeValue = Serial.readString();
          Serial.print(rechargeValue);
          // atulizar credito
          Serial.print("1\n");
          } break;

     case 4: { // HISTORIC
          while(Serial.available() <=0 );
          String var = Serial.readString();
          // pegar ultimas transações feitas
          Serial.print("1\n");
          } break;
  }
}

short Bluetooth::transmitData(char* data){
	Serial.write(data);
}

