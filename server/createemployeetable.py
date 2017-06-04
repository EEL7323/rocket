import psycopg2

#defines of database
hostnm = 'localhost'
usernm = 'mfrata'
passwd = 'sudofrata'
db     = 'rocket_server'

try:
    print 'Connecting to db...'
    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    print 'creating table'
    cur = conn.cursor()
    query = "create table employees(id serial, name text, passwd text)"
    cur.execute( query )
    conn.commit()
except:
    print "Error to connection or query"
finally:
	print 'Closing db Connection.'
    conn.close()
