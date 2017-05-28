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

def qSetCredit( conn, student_id, value) :
    print int(value)
    cur = conn.cursor()
    query = "UPDATE students SET credit = "+value+" WHERE id = "+student_id
    print query
    cur.execute( query )
    print 'Checking write...'
    conn.commit()
    #qGetCredit( conn, student_id )


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
    timeout=100
)

while 1:
    print "Waiting for Command.."
    command = ser.read(1)
    if command == 'r': # read
	print 'Command = read.'
	print 'Waiting for id...'
	stud_id = ser.read(2)
	print 'id = '+ stud_id
        try:
	    print 'Connecting to db...'
            readConn = psycopg2.connect( host=hostname, user=username, password=password, dbname=database )
            print 'Quering credit'
	    credit = qGetCredit( readConn, stud_id )
	    print "Seding to msp: ",credit
	    ser.write( str(credit) )
	except:
            print "Error to connection or query"
        finally:
	    print 'Closing db Connection.'
            readConn.close()
    elif command == 'w': #write
        print 'Command = write'
	print 'Waiting for id...'
	stud_id = ser.read(2)
	print 'id = '+ stud_id
        print 'Watigin for new value...'
	new_credit = ser.read(3)
	print 'new credit = '+new_credit
	try:
	    print 'Connecting to db...'
	    writeConn = psycopg2.connect( host=hostname, user=username, password=password, dbname=database )
            print 'Quering credit'
            qSetCredit( writeConn, stud_id, new_credit )
            print "Done."
	except:
	    print "Error while updating table"
	finally:
	    print 'Closing db Connection'
	    writeConn.close()
    else:
	print 'Unknown Command or Serial Timeout'    



    
    
    

