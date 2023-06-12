#include "Yoga.h"
Yoga::Yoga(int pId, string pName, int stHour, int stMin, int etHour, int etMin):Program(pId, pName, stHour, stMin, etHour, etMin)
{

}

string Yoga::getProgramType()
{
	return "Yoga";
}

string Yoga::getProgramTypeId()
{
	return "YGA";
}
