#ifndef DATE_H
#define DATE_H

class Date
{
	private:
		int day;
		int month;
		int year;
	public:
		Date(int d = 0, int m = 0, int y = 0);
		
		void setDay(int d);
		int getDay();
		
		void setMonth(int m);
		int getMonth();
		
		void setYear(int y);
		int getYear();
		
		string dateDisplay();
};

#endif
