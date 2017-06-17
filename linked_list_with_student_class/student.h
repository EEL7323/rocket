#include <string>


class Student
{
	private:
		std::string name;
		std::string registration;
		int cred;
	public:
		Student();
		~Student();
		void setName(std::string s);
		void setRegistration(std::string s);
		void setCred(int c);
		std::string getName();
		std::string getRegistration();
		int getCred();
		void decreaseCred();
		void showAllinfo();
};



