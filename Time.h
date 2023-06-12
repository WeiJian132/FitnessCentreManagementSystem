#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;
class Time
{
	private:
		int hour;
		int minute;
	public:
		Time(int h = 0, int m = 0);
		
		void setHour(int h);
		int getHour();
		
		void setMinute(int m);
		int getMinute();
		
		string timeDisplay();
};

#endif
