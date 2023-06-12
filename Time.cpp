#include "Time.h"
Time::Time(int h, int m)
{
	hour = h;
	minute = m;
}

void Time::setHour(int h)
{
	hour = h;
}

int Time::getHour()
{
	return hour;
}

void Time::setMinute(int m)
{
	minute = m;
}

int Time::getMinute()
{
	return minute;
}

string Time::timeDisplay()
{
	string tempHour;
	string tempMinute;
	string tempDisplay;
	
	if (hour < 10)
	{
		tempHour = "0" + to_string(hour);
	}
	else
	{
		tempHour = to_string(hour);
	}
	
	if (minute < 10)
	{
		tempMinute = "0" + to_string(minute);
	}
	else
	{
		tempMinute = to_string(minute);
	}
	
	tempDisplay = tempHour + ":" + tempMinute;
	return tempDisplay;
}
