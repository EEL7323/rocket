import serial
import dbInterface

uart = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)


def rxCommand():
    command = None
    rxBuffer = uart.read()
    if rxBuffer == 'r':
        command = 'read'
    elif rxBuffer == 'u':
        command = 'update'
    elif rxBuffer == 'f':
        command = 'flush'
    elif rxBuffer == 's':
        command = 'sinc'
    return command

def rxName():
    name = ''
    while 1:
        rxBuffer = uart.read()
        if rxBuffer == '\r':
            break
        name.join(rxBuffer)
    return name

def txInfo(info):
    if type(info) == str:
        uart.send(info)
    elif type(info) == list:
        #todo implement list return
        pass
