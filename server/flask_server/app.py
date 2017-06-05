from flask import Flask
from flask import request, redirect, url_for, render_template
import psycopg2

#defines of database
hostnm = 'localhost'
usernm = 'mfrata'
passwd = 'sudofrata'
db     = 'rocket_server'
user_section = None

app = Flask(__name__)

@app.route("/")
def hello():
    return render_template('index.html')

@app.route('/login', methods=['POST'])
def login():
    conn = None
    atribute = None
    username = request.form['username']
    password = request.form['password']
    uniId = None
    name = None
    _passwd = None
    print username, password
    try:
	    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    except:
	    atribute = "DB Connection Failed"
	    print atribute
    query = "SELECT * FROM employees WHERE name = \'"+username+"\'"
    print query
    try:
    	cur = conn.cursor()
    	cur.execute( query )
    	uniId, name, _passwd = cur.fetchall().pop()
    except:
	    atribute = "User Not Found"
	    print atribute
    if name == username and _passwd == password:
        redirect_page = 'search.html'
        global user_section = username
        atribute = global user_section
    else:
        redirect_page = 'error.html'
	if atribute == None:
	    atribute = "Wrong password"
	    print atribute
    conn.close()
    return render_template(redirect_page, atribute=atribute)

@app.route('/search', methods=['POST'])
def search():
    conn = None
    atribute = None
    uniId = None
    name = None
    credits = None
    userID = request.form['id']
    print type(userID), userID
    try:
	    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    except:
	    atribute = "DB Connection Failed"
	    print atribute
    query = "SELECT * FROM students WHERE id = "+userID
    print query
    try:
    	cur = conn.cursor()
    	cur.execute( query )
    	uniId, name, credits = cur.fetchall().pop()
    except:
        if atribute == None:
	       atribute = "Student Not Found"
	       print atribute
    if atribute != None:
        redirect_page = 'searchfailed.html'
    else:
        redirect_page= 'student.html'
    conn.close()
    return render_template(redirect_page, atribute=atribute, studentName=name,
            studentId=uniId, studentCredits=credits)


@app.route('/updateCredit', methods=['POST'])
def updateCredit():
    pass

@app.route('/returnToSearch')
def returnToSearch():
    return render_template('search.html', atribute=user_section)

@app.route('/logout')
def logout():
    user_section = None
    return render_template('index.html')

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
