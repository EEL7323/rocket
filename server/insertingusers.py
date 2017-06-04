import psycopg2

#defines of database
hostnm = 'localhost'
usernm = 'mfrata'
passwd = 'sudofrata'
db     = 'rocket_server'

try:
    print 'Connecting to db...'
    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    print 'creating query
    cur = conn.cursor()
    query = "insert into employees values (default, 'mfrata', 'sudofrata');"
    print query
    cur.execute( query )
    conn.commit()
except:
    print "Error to connection or query"
finally:
	print 'Closing db Connection.'
    conn.close()


try:
    print 'Connecting to db...'
    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    print 'creating query
    cur = conn.cursor()
    query = "insert into employees values (default, 'ufsc', 'sudoufsc');"
    print query
    cur.execute( query )
    conn.commit()
except:
    print "Error to connection or query"
finally:
	print 'Closing db Connection.'
    conn.close()
