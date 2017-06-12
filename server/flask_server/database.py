from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String, update
from sqlalchemy.orm import sessionmaker

engine = create_engine('postgresql://mfrata:sudofrata@localhost:5432/rocket_server', echo=False)
Base = declarative_base()

class Student(Base):
    __tablename__ = 'students'
    id = Column(Integer, primary_key=True)
    name = Column(String)
    credit = Column(Integer)
    def __repr__(self):
       return "<User(id='%s', name='%s', credits='%i')>" % (
                            self.id, self.name, self.credit)


Session = sessionmaker(bind=engine)
session = Session()

def getStudentInfo(studentId):
    print studentId
    keys = ['id', 'name', 'credit']
    info = session.query(Student.id, Student.name, Student.credit).filter_by(
            id=studentId).all().pop()
    return {k:v for k,v in zip(keys,info)}

def setStudentInfo(studentId ,studentCredit):
    print studentId, studentCredit
    session.query(Student).filter_by(
            id=studentId).update({Student.credit: studentCredit})
    session.commit()
