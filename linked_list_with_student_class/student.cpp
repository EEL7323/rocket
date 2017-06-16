#include <string>


class Student
{
	private:
		string name;
		string registration;
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
	
		void setName(string s)
		{
			name = s;
		}
		
		void setRegistration(string s)
		{
			registration = s;
		}
		
		void setCred(int c)
		{
			cred = c;
		}
		
		string getName()
		{
			return name;
		}
		
		string getRegistration()
		{
			return registration;
		}
		
		int getCred()
		{
			return cred;
		}
}



