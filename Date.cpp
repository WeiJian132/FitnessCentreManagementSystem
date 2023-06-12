#include "Date.h"
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::setDay(int d)
{
	day = d;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int m)
{
	month = m;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int y)
{
	year = y;
}

int Date::getYear()
{
	return year;
}

string Date::dateDisplay()
{
	string tempDate;
	tempDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	return tempDate;
}
