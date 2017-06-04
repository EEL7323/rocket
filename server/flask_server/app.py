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
    try:
        conn = psycopg2.connect( host=hostnm, user=usernm, password=passwd, dbname=db )
        redirect_page = 'students.html'
    except:
        redirect_page = 'error.html'
    finally:
        conn.close()
        return render_template(redirect_page)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
