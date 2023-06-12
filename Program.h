#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "Time.h"
using namespace std;

class Program
{
	protected:
		int programId; // To hold the ID value
		string programName; // To hold the program name
		Time startTime; // To hold the program start time
		Time endTime; // To hold the program end time
	public:
		Program(int pId = 0, string pName = "NONE", int stHour = 0, int stMin = 0, int etHour = 0, int etMin = 0); // Constructor for Program
		
		void setProgramId(int pId); // Function to set program ID manually
		int getProgramId(); // Function to return program ID in int
		
		void setProgramName(string pName); // Function to set program name manually
		string getProgramName(); // Function to return program name in string
		
		void setProgramStartTime(int h, int m); // Function to set program start time manually
		Time getProgramStartTime(); // Function to return program start time in time
		
		void setProgramEndTime(int h, int m); // Function to set program end time manually
		Time getProgramEndTime(); // Function to return program end time in time
		
		string getProgramFullTime(); // Function to return program start and end time in string
		
		virtual string getProgramType() = 0; // Pure virtual function used for polymorphism for different type of program to return program type in string
		virtual string getProgramTypeId() = 0; // Pure virtual function used for polymorphism for different type of program to return program type ID in string
		
		string getProgramFullId(); // Function used to return program type ID + program ID in string
};

#endif
