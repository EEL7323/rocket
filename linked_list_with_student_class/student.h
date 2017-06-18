#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>

class Student
{
	private:
		std::string name;
		std::string registration;
		int cred;
	public:
		Student()
		{
			name = "";
			registration = "";
			cred = 0;
		}
		~Student(){	
		}
	
		void setName(std::string s)
		{
			name = s;
		}
		
		void setRegistration(std::string s)
		{
			registration = s;
		}
		
		void setCred(int c)
		{
			cred = c;
		}
		
		std::string getName()
		{
			return name;
		}
		
		std::string getRegistration()
		{
			return registration;
		}
		
		int getCred()
		{
			return cred;
		}
		void decreaseCred()
		{
			cred--;
		}
/*		
		void showAllinfo()
		{
			cout << "\n Name: " << name << endl;
			cout << "\n Registration: " << registration << endl;
			cout << "\n Credit: " << cred << endl;
		}
		*/
};


#endif
