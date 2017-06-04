from flask import Flask
from flask import request, redirect, url_for, render_template
import psycopg2

#defines of database
hostnm = 'localhost'
usernm = 'mfrata'
passwd = 'sudofrata'
db     = 'rocket_server'

app = Flask(__name__)

@app.route("/")
def hello():
    return render_template('index.html')

@app.route('/login', methods=['POST'])
def login():
    conn = None
    error = None
    username = request.form['username']
    password = request.form['password']
    uniId = None
    name = None
    _passwd = None
    print username, password
    try:
	conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    except:
	error = "DB Connection Failed"
	print error	
    query = "SELECT * FROM employees WHERE name = '" +username+"\'"
    print query
    try:
    	cur = conn.cursor()
    	cur.execute( query )
    	uniId, name, _passwd = cur.fetchall().pop()
    except:
	error = "User Not Found"
	print error
    if name == username and _passwd == password:
        redirect_page = 'students.html'
    else:
        redirect_page = 'error.html'
	if error == None:
	    error = "Password or login mismatched"
	    print error
    conn.close()
    return render_template(redirect_page, atribute=error)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
