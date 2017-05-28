import serialInterface
import dbInterface

#wait for command
while 1:
    print 'Reading command...'
    command = rxCommand()

    if command == 'read':
        print 'command read'
        student_name = rxName()
        print student_name
        #credit = getCredit(student_name)
        credit = 10
        txInfo(credit)
    elif command == 'update':
        pass
    elif command == 'flush':
        pass
    elif command == 'sinc':
        pass
    else:
        pass



#
