#!/usr/bin/python

hostname = 'localhost'
username = 'mfrata'
password = 'sudofrata'
database = 'rocket_server'

# Simple routine to run a query on a database and print the results:
def doQuery( conn ) :
    cur = conn.cursor()
    list = []
    cur.execute( "SELECT * FROM students" )

    for id, name, credits in cur.fetchall() :
        print id, name, credits


print 'psycopg2'
import psycopg2
try:
    myConnection = psycopg2.connect( host=hostname, user=username, password=password, dbname=database )
    doQuery( myConnection )
    print 'connected with psycopg2'
except:
    print "did not work on psyco"
finally:
    myConnection.close()
