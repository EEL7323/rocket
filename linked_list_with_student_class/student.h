#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>

class Student
{
	private:
		std::string name;
		std::string registration;
		unsigned int cred;
		bool inside;
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
		void changeInside()
		{
			inside = ~inside;
		}
		
		std::string getName()
		{
			return name;
		}
		
		std::string getRegistration()
		{
			return registration.substr(0, 2);
		}
		
		int getCred()
		{
			return cred;
		}
		void decreaseCred()
		{
			cred--;
		}
		bool getInside()
		{
			return inside;
		}

};


#endif
