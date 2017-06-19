#include "bluetooth.h"

Bluetooth bluetooth;
  
void setup() {
  char* teste = "o";
  bluetooth.initBluetooth(9600);
  // bluetooth.transmitData(teste);
}

void loop() {
  bluetooth.receiveData();
}
