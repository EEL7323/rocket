#!/usr/bin/python

import time
import serial
import psycopg2


# Simple routine to run a query on a database and print the results:
def qGetCredit( conn, student_id ) :
    cur = conn.cursor()
    query = "SELECT * FROM students WHERE id = "+ student_id
    print query
    cur.execute( query ) 
    id, name, credits = cur.fetchall().pop()
    print id, name, credits 
    return credits 

hostname = 'localhost'
username = 'mfrata'
password = 'sudofrata'
database = 'rocket_server'


ser = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=10
)

while 1:
    command = ser.read(1)
    if command == 'r':
	print 'Command = read.'
	print 'Waiting for id...'
	stud_id = ser.read(2)
	print 'id = '+ stud_id
        try:
	    print 'Connecting to db...'
            myConnection = psycopg2.connect( host=hostname, user=username, password=password, dbname=database )
            print 'Quering credit'
	    credit = qGetCredit( myConnection, stud_id )
	    print "Seding to msp: ",credit
	    ser.write( str(credit) )
	except:
            print "Error to connection or query"
        finally:
	    print 'Closing db Connection.'
            myConnection.close()



    
    
    

