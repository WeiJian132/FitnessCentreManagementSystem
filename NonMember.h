#ifndef NONMEMBER_H
#define NONMEMBER_H

#include "Customer.h"
#include "Program.h"
#include "Date.h"

class NonMember : public Customer
{
	public:
		NonMember(string n = "NONE", int a = 0, string p = "NONE", int cId = 0, string cFiD = "NMB");
		
		string getStartDate();
		string getExpiredDate();
		string getProgramName();
		string getProgramId();
		
		string getMembership();
};

#endif
