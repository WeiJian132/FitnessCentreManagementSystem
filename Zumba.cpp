#include "Zumba.h"
Zumba::Zumba(int pId, string pName, int stHour, int stMin, int etHour, int etMin):Program(pId, pName, stHour, stMin, etHour, etMin)
{

}

string Zumba::getProgramType()
{
	return "Zumba";
}

string Zumba::getProgramTypeId()
{
	return "ZBA";
}
