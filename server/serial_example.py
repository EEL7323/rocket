import serial
ser = serial.Serial ("/dev/ttyAMA0")    #Open named port 

ser.baudrate = 115200                     #Set baud rate to 9600
print 'reading 10 chars'
data = ser.read(10)                     #Read ten characters from serial port to data
print 'sending hello wolrd'
ser.write('Hello world')                  #Send back the received data

print 'sending 10 readed chars'
ser.write(data)

ser.close()        

