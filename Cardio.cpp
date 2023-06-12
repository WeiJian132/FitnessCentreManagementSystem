#include "Cardio.h"
Cardio::Cardio(int pId, string pName, int stHour, int stMin, int etHour, int etMin):Program(pId, pName, stHour, stMin, etHour, etMin)
{

}

string Cardio::getProgramType()
{
	return "Cardio";
}

string Cardio::getProgramTypeId()
{
	return "CRD";
}
