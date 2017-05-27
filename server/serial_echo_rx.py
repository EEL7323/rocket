import time
import serial

ser = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

while 1:
    data = ser.read(1)
    ser.write('\rReceived: ')
    ser.write(data)
    
    
    
