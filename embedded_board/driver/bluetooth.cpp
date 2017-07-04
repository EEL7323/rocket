#include "bluetooth.h"

uart uartHandler(USCI_A1_BASE, 9600);
char receive_buffer[MAX_BUFFER_LENGTH];
uint8_t users_inside = 10;
uint8_t cred = 10;
uint8_t uartdata;
short i;
int tamanho;
std::string registry_str;  // creating an obj
std::string str2; // test const
std::string uartString;
std::string recharge;
int access_free = 0;
uint8_t ID_int;
std::string::size_type sz;   // alias of size_t


void Bluetooth::initBluetooth(int baud_rate){
    //  Serial.begin(baud_rate);
}

void Bluetooth::receiveData(dataManagement &Manager)
{
    __delay_cycles(4000000);
    uartString =  uartHandler.getBuffer();
    uartHandler.clear_A1_string();
    // extrair comando do protocolo de comunicação
    char cmd = uartString.at(0);
    uartdata = (uint8_t)(cmd)-48;
    // extrair matrícula
    tamanho = uartString.length();
    if(cmd != '3'){
        uartString.erase(0,1);
    }else{
        recharge = uartString.at(3);
        uartString.erase(0,1);
        uartString.erase(2,1);
    }

    //  ID_int = std::stoi(uartString, &sz);
    sscanf(uartString.c_str(), "%hhu", &ID_int);

    switch(uartdata) {
    case 0: { // LOGIN
        // str2 vai ser pego fazendo uma varredura na lista
        if(Manager.existRegisteredPeopleList(uartString))
        {
            access_free = 1;
            users_inside =  Manager.getPeopleInRu();
            transmitData((uint8_t*)("1")); // valor decimal do numero 1 em ascii
            char users_inside_str[3];
            sprintf(users_inside_str, "%d", users_inside);
            transmitData((uint8_t*)users_inside_str);
            transmitData((uint8_t*)("\n")); // \n in ascii
        }
        else {
            transmitData((uint8_t*)"0");
            transmitData((uint8_t*)"\n");
        }
    } break; // ok

    case 1: { // ACCESS
        if(Manager.hasEnoughCredit(ID_int)){

            transmitData((uint8_t*)("1\n"));
            std::string captcha = "3";
            __delay_cycles(40000000);
            std::string captcha_verify =  uartHandler.getBuffer();
            uartHandler.clear_A1_string();
            if (!(captcha_verify.compare(0,1, captcha, 0, 1))) {
                Manager.subtractCredit(ID_int); //cred--;
                if(users_inside <= MAX_RU_CAPACITY){
                    Manager.insertInRU(&Manager.getFromRegisteredPeopleList(ID_int));
                    Manager.increaseTotalPeopleInRU();
                }
                transmitData((uint8_t*)("1\n"));
            }
        }
        else {
            transmitData((uint8_t*)("4\n")); // enviar comando que indica falta de crédito
        }
        break;
    }
    case 2: { // LEAVE
        transmitData((uint8_t*)("1\n"));
        std::string captcha = "8";
        // mostrar captcha nos LEDS
        __delay_cycles(40000000);
        std::string captcha_verify =  uartHandler.getBuffer();
        uartHandler.clear_A1_string();
        // transmitData(captcha_verify);
        if (!(captcha_verify.compare(0,1, captcha, 0, 1))) {
            Manager.decreaseTotalPeopleInRU();  //users_inside--;
            transmitData((uint8_t*)("1\n"));
        }
        else {
            transmitData((uint8_t*)("4\n"));
        }
        break;
    }


    case 3: { // RECHARGE
        uint8_t credi;// = std::stoi(recharge,&sz);
        sscanf(recharge.c_str(), "%hhu", &credi);
        Manager.rechargeCredit(ID_int, credi);
        // atulizar credito
        // chamar na lista, atualizar credito
        transmitData((uint8_t*)("1\n"));
        break;
    }


    } // switch
} // receiveData

void Bluetooth::transmitData(uint8_t* data){
    uartHandler.transmit(data);
}
