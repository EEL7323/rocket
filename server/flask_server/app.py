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
    username = request.form['username']
    password = request.form['password']
    print username, password
    conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
    query = "SELECT * FROM employees WHERE name = "+ username
    print query
    cur.execute( query )
    uniId, name, _passwd = cur.fetchall().pop()
    if name == username and _passwd == password:
        redirect_page = 'students.html'
    else:
        redirect_page = 'error.html'
    conn.close()
    return render_template(redirect_page)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
