#ifndef YOGA_H
#define YOGA_H

#include "Program.h"
class Yoga : public Program
{
	public:
		Yoga(int pId = 0, string pName = "NONE", int stHour = 0, int stMin = 0, int etHour = 0, int etMin = 0); // Constructor for Yoga
		string getProgramType(); // Return a string to represent the program type
		string getProgramTypeId(); // Return a string to represent the program type ID
};

#endif
