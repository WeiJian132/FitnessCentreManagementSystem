#include "PersonalDetail.h"
PersonalDetail::PersonalDetail(string n, int a, string p)
{
	name = n;
	age = a;
	phone = p;
}

void PersonalDetail::setName(string n)
{
	name = n;
}

string PersonalDetail::getName()
{
	return name;
}

void PersonalDetail::setAge(int a)
{
	age = a;
}

int PersonalDetail::getAge()
{
	return age;
}

void PersonalDetail::setPhone(string p)
{
	phone = p;
}

string PersonalDetail::getPhone()
{
	return phone;
}
