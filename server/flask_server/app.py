from flask import Flask
from flask import request, redirect, url_for, render_template
import psycopg2

#defines of database
hostname = 'localhost'
username = 'mfrata'
password = 'sudofrata'
database = 'rocket_server'

app = Flask(__name__)

@app.route("/")
def hello():
    return render_template('index.html')

@app.route('/login', methods=['GET'])
def login():
    username = request.form['username']
    password = request.form['password']
    print username, password
    try:
        readConn = psycopg2.connect( host=hostname, user=username, password=password, dbname=database )
        redirect_page = 'students'
    except:
        redirect_page = 'error'
    finally:
        readConn.close()
        return redirect(url_for(redirect_page))

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80, debug=True)
