#ifndef MEMBER_H
#define MEMBER_H

#include "Customer.h"
#include "Program.h"
#include "Date.h"

class Member : public Customer
{
	private:
		Program *program;
		Date startDate;
		Date expiredDate;
	public:
		Member(string n = "NONE", int a = 0, string p = "NONE", int cId = 0, string cFiD = "YMB", int sdDay = 0, int sdMonth = 0, int sdYear = 0, int d = 0);
		
		void assignProgram(Program *prog);
		Program* getProgram();
		
		void setStartDate(int sdDay, int sdMonth, int sdYear);
		Date getStartDate();
		
		void setExpiredDate(int t);
		Date getExpiredDate();
		
		string getMembership();
};

#endif
