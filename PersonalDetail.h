#ifndef PERSONALDETAIL_H
#define PERSONALDETAIL_H

#include <iostream>
using namespace std;

class PersonalDetail
{
	private:
		string name;
		int age;
		string phone;
	public:
		PersonalDetail(string n = "NONE", int a = 0, string p = "NONE");
		
		void setName(string n);
		string getName();
		
		void setAge(int a);
		int getAge();
		
		void setPhone(string p);
		string getPhone();
};

#endif
