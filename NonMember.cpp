#include "NonMember.h"
NonMember::NonMember(string n, int a, string p, int cId, string cFiD):Customer(n, a, p,cId, cFiD)
{
	
}

string NonMember::getStartDate()
{
	return "NONE";
}

string NonMember::getExpiredDate()
{
	return "NONE";
}

string NonMember::getProgramName()
{
	return "NONE";
}

string NonMember::getProgramId()
{
	return "NONE";
}

string NonMember::getMembership()
{
	return "Non-Member";
}
