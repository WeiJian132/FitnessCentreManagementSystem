#include "Program.h"
Program::Program(int pId, string pName, int stHour, int stMin, int etHour, int etMin):startTime(Time(stHour, stMin)), endTime(Time(etHour, etMin))
{
	programId = pId;
	programName = pName;
}

void Program::setProgramId(int pId)
{
	programId = pId;
}

int Program::getProgramId()
{
	return programId;
}

void Program::setProgramName(string pName)
{
	programName = pName;
}

string Program::getProgramName()
{
	return programName;
}

void Program::setProgramStartTime(int h, int m)
{
	startTime = Time(h, m);
}

Time Program::getProgramStartTime()
{
	return startTime;
}

void Program::setProgramEndTime(int h, int m)
{
	endTime = Time(h, m);
}

Time Program::getProgramEndTime()
{
	return endTime;
}

string Program::getProgramFullTime()
{
	string temp = getProgramStartTime().timeDisplay() + " - " + getProgramEndTime().timeDisplay();
	return temp;
}

string Program::getProgramFullId()
{
	string temp = getProgramTypeId() + to_string(programId);
	return temp;
}
