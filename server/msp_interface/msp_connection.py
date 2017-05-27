#imports
import psycopg2
import time
import serial

#defines
hostname = 'localhost'
username = 'mfrata'
password = 'sudofrata'
database = 'rocket_server'

#setup serial
uart = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

#setup server

#wait for command
while 1:
    command = uart.read(1)
    if command == 'r': #read
        uart.write('\rread')
        pass
    elif command == 'u': #update
        uart.write('\rupdate')
        pass
    elif command == 'f': #flush
        uart.write('\rflush')
        pass
    elif command == 's': #sinc
        uart.write('\rsinc')
    else
        uart.write('\rError')



#
