import flask
import database as db


app = flask.Flask(__name__)

@app.route('/student/<uid>', methods=['GET'])
def student_get(uid):
    student = db.getStudentInfo(uid)
    if student:
        return flask.jsonify(student), 200
    return flask.abort(404)


@app.route("/student/<uid>/<newCredit>", methods=['PUT', 'GET'])
def student_credit_update(uid,newCredit):
    try:
        db.setStudentInfo(uid, newCredit)
        print 'db done'
        student = db.getStudentInfo(uid)
        print student
        return flask.jsonify(student), 201
    except:
        return flask.abort(400)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000, debug=True)
