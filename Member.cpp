#include "Member.h"
Member::Member(string n, int a, string p, int cId, string cFiD, int sdDay, int sdMonth, int sdYear, int d):Customer(n, a, p, cId, cFiD), startDate(sdDay, sdMonth, sdYear)
{
	setExpiredDate(d);
}

void Member::assignProgram(Program *prog)
{
	program = prog;
}

Program* Member::getProgram()
{
	return program;
}

void Member::setStartDate(int sdDay, int sdMonth, int sdYear)
{
	startDate = Date(sdDay, sdMonth, sdYear);
}

Date Member::getStartDate()
{
	return startDate;
}

void Member::setExpiredDate(int t)
{
	int d = startDate.getDay();
	int m = startDate.getMonth();
	int y = startDate.getYear();
	
	if (t == 365)
	{
		y++;
	}
	if (t == 30)
	{
		int dayLimit;
		
		m++;
		
		if (m > 12)
		{
			y++;
			m -= 12;
		}
		
		if (y % 4 == 0)
		{
			switch(m)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: dayLimit = 31;
						 break;
				case 4:
				case 6:
				case 9:
				case 11: dayLimit = 30;
						 break;
				case 2: dayLimit = 29;
						break;
			}
		}
		else
		{
			switch(m)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: dayLimit = 31;
						 break;
				case 4:
				case 6:
				case 9:
				case 11: dayLimit = 30;
						 break;
				case 2: dayLimit = 28;
						break;
			}
		}
		
		if (d > dayLimit)
		{
			d = dayLimit;
		}
	}
	if (t == 7)
	{		
		int dayLimit;
		int monthLim = 12;
		
		if (y % 4 == 0)
		{
			switch(m)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: dayLimit = 31;
						 break;
				case 4:
				case 6:
				case 9:
				case 11: dayLimit = 30;
						 break;
				case 2: dayLimit = 29;
						break;
			}
			
			if (d + 7 > dayLimit)
			{
				d = d + 7 - dayLimit;
				m++;
				
				if (m > 12)
				{
					m -= 12;
					y++;
				}
			}
			else
			{
				d += 7;
			}
		}
		else
		{
			switch(m)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12: dayLimit = 31;
						 break;
				case 4:
				case 6:
				case 9:
				case 11: dayLimit = 30;
						 break;
				case 2: dayLimit = 28;
						break;
			}
			
			if (d + 7 > dayLimit)
			{
				d = d + 7 - dayLimit;
				m++;
				
				if (m > 12)
				{
					m -= 12;
					y++;
				}
			}
			else
			{
				d += 7;
			}
		}
	}
	
	expiredDate = Date(d, m, y);
}

Date Member::getExpiredDate()
{
	return expiredDate;
}

string Member::getMembership()
{
	return "Member";
}
