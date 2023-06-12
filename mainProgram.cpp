#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <fstream>

#include "LibraryCollection.h"
using namespace std;

// Data Acquisition Functions
// Trainers Data Acquisition Function
void getTrainerList(Trainer *&tList, int &size)
{
	fstream inFile("Trainers.txt", ios::in);
	
	if (!inFile)
	{
		cout << "No Existing Trainers' Information!!! Please Add A File With Trainers' Information Included!!!" << endl;
		exit(0); 
	}
	
	inFile >> size;
	inFile.ignore();
	
	tList = new Trainer[size];
	int counter = 0;
	
	while(!inFile.eof())
	{
		if (inFile.eof())
		{
			break;
		}
		
		string tName;
		int tAge;
		string tPhone;
		string tExp;
		string tQua;
		string dispose;
		
		getline(inFile, tName);
		
		if (tName == "")
		{
			break;
		}
		
		inFile >> tAge;
		inFile.ignore();
		getline(inFile, tPhone);
		getline(inFile, tExp);
		getline(inFile, tQua);
		getline(inFile, dispose);
		
		Trainer tempTrainer(tName, tAge, tPhone, tExp, tQua);
		tList[counter++] = tempTrainer;
	}
	
	inFile.close();
}
// Programs Data Acquisition Function
void getProgramList(Program* *&pList, int &size)
{
	fstream inFile("Programs.txt", ios::in);
	
	if (!inFile)
	{
		cout << "No Existing Programs' Information!!! Please Add A File With Programs' Information Included!!!" << endl;
		exit(0);
	}
	
	inFile >> size;
	
	pList = new Program*[size];
	
	int counter = 0;
	
	while(!inFile.eof())
	{
		if (inFile.eof())
		{
			break;
		}
		
		char pType;
		string pName;
		int pId;
		int psthour;
		int pstmin;
		int pethour;
		int petmin;
		string dispose;
		
		inFile >> pType;
		inFile.ignore();
		getline(inFile, pName);
		inFile >> pId;
		inFile >> psthour;
		inFile >> pstmin;
		inFile >> pethour;
		inFile >> petmin;
		inFile.ignore();
		getline(inFile, dispose);
		
		Program *tempProgram;
		
		switch(pType)
		{
			case 'C': tempProgram = new Cardio(pId, pName, psthour, pstmin, pethour, petmin);
					  break;
			case 'Y': tempProgram = new Yoga(pId, pName, psthour, pstmin, pethour, petmin);
					  break;
			case 'Z': tempProgram = new Zumba(pId, pName, psthour, pstmin, pethour, petmin);
					  break;
		}
		
		pList[counter++] = tempProgram;
	}
	
	inFile.close();
}
// Current Member ID Acquisition Function
int getCurrentMemberId()
{
	int temp;
	
	fstream inFile("MID.txt", ios::in);
	
	if (!inFile)
	{
		inFile.close();
		return 1;
	}
	
	inFile >> temp;
	inFile.close();
	
	return temp;
}
// Current Non-Member ID Acquisition Function
int getCurrentNonMemberId()
{
	int temp;
	
	fstream inFile("NMID.txt", ios::in);
	
	if (!inFile)
	{
		inFile.close();
		return 1;
	}
	
	inFile >> temp;
	inFile.close();
	
	return temp;
}
// Current Customer List Number Acquisition Function
int getCurrentListNo()
{
	int temp;
	
	fstream inFile("ListNo.txt", ios::in);
	
	if (!inFile)
	{
		inFile.close();
		return 1;
	}
	
	inFile >> temp;
	inFile.close();
	return temp;
}

// Select Menu & Selection Funtions
// Trainer Select Menu & Selection Function
void selectTrainer(Trainer *tList, int &s, int size)
{
	system("CLS");
	
	cout << "===================================================================================================================" << endl;
	cout << setw(65) << "Trainer Information: " << endl;						//input trainer information
	cout << "===================================================================================================================" << endl;
	cout << left;
	cout << setw(5) << "No" << setw(20) << "Name" << setw(5) << "Age" << setw(20) << "Phone" << setw(30) << "Experience" << setw(30) << "Qualification" << endl;
	
	for (int x = 0; x < size; x++)
	{
		cout << setw(5) << x + 1;
		cout << setw(20) << tList[x].pd.getName();
		cout << setw(5) << tList[x].pd.getAge();
		cout << setw(20) << tList[x].pd.getPhone();
		cout << setw(30) << tList[x].getExp();
		cout << setw(30) << tList[x].getQua() << endl;
	}
	
	cout << "Please choose the available trainer you want from the list above..." << endl;
	
	int counter = -1;
	
	while(counter < 0)
	{
		cin >> s;
		
		if (s <= size)
		{
			counter++;
		}
		else
		{
			cout << "Invalid Input!!! Please Try Again!!!" << endl;
		}
	}
}
// Selected Trainer's Information Display Function
void displayTrainerInformation(Trainer t)
{
	cout << endl;
	cout << "Your trainer's information:" << endl;
	cout << "Name: " << t.pd.getName() << endl;
	cout << "Age: " << t.pd.getAge() << endl;
	cout << "Phone No.: " << t.pd.getPhone() << endl;
	cout << "Experience: " << t.getExp() << endl;
	cout << "Qualification: " << t.getQua() << endl;
	
	cout << endl << "You can contact your trainer for more information" << endl;
	
	system("PAUSE");
}
// Memberpack Select Menu & Selection Function
void selectMemberPack(int &d)
{
	cout << "You made a right choice ^^, now which membership subscription pack do you prefer? " << endl;
	cout << setw(3) << "NO " << "ACTION" << endl;
	cout << setw(3) << 1 << "One Year Pack" << endl;
	cout << setw(3) << 2 << "One Month Pack" << endl;
	cout << setw(3) << 3 << "One Week Pack" << endl;
	
	int counter = -1;
	
	while(counter < 0)
	{
		cin >> d;
		
		switch(d)
		{
			case 1: d = 365;
					counter++;
					break;
			case 2: d = 30;
					counter++;
					break;
			case 3: d = 7;
					counter++;
					break;
			default:cout << "Invalid Input!!! Please Try Again!!!" << endl;
					break;
		}
	}
}
// Program Select Menu & Selection Function
void selectProgram(Program* *pList, Program *&tp, int size)
{
	cout << "===================================================================================================================" << endl;
	cout << right << setw(65) << "Program Available: " << endl;						//input program information
	cout << "===================================================================================================================" << endl;
	cout << left;
	cout << setw(5) << "No" << setw(25) << "Program Name" << setw(25) << "Program Id" << setw(25) << "Program Type" << setw(25) << "Time" << endl;

	for (int x = 0; x < size; x++)
	{
		cout << setw(5) << x + 1;
		cout << left;
		cout << setw(25) << pList[x]->getProgramName();
		cout << setw(25) << pList[x]->getProgramFullId();
		cout << setw(25) << pList[x]->getProgramType();
		cout << setw(25) << pList[x]->getProgramFullTime() << endl;
	}
	
	cout << "Please select the program you want..." << endl;
	
	int select = 0;
	int counter = -1;
	
	while(counter < 0)
	{
		cin >> select;
		
		if (select <= size)
		{
			tp = pList[select - 1];
			counter++;
		}
		else
		{
			cout << "Invalid Input!!! Please Try Again!!!" << endl;
		}
	}
	
	cout << endl;
	cout << "This is the information of the program you chosen..." << endl;
	cout << "Program Name: " << tp->getProgramName() << endl;
	cout << "Program ID: " << tp->getProgramFullId() << endl;
	cout << "Program Type: " << tp->getProgramType() << endl;
	cout << "Program Start Time: " << tp->getProgramStartTime().timeDisplay() << endl;
	cout << "Program End Time: " << tp->getProgramEndTime().timeDisplay() << endl;
	
	system("PAUSE");
}

// Customer Data Storing Functions
// Member Data Storing Function
void outputCustomerData(Member m, int &n)
{
	fstream outFile("CustomerList.txt", ios::app|ios::out);
	
	if (n == 1)
	{
		outFile << "=============================================================================================================================================================================================" << endl;
		outFile << setw(90) << right << "Customer List" << endl;
		outFile << "=============================================================================================================================================================================================" << endl;
		outFile << setw(5) << left << "NO" << setw(20) << "NAME" << setw(10) << "ID" << setw(5) << "AGE" << setw(15) << "PHONE NO." << setw(20) << "TRAINER" << setw(15) << "MEMBERSHIP" << setw(30) << "PROGRAM" << setw(15) << "PROGRAM TIME" << setw(30) << "MEMBERSHIP START DATE" << setw(30) << "MEMBERSHIP EXPIRED DATE" << endl;
	}
	
	outFile << left;
	outFile << setw(5) << n++ << setw(20) << m.pd.getName() << setw(10) << m.getCustomerFullId() << setw(5) << m.pd.getAge() << setw(15) << m.pd.getPhone() << setw(20) << m.getTrainer().pd.getName() << setw(15) << m.getMembership() << setw(30) << m.getProgram()->getProgramName() << setw(15) << m.getProgram()->getProgramFullTime() << setw(30) << m.getStartDate().dateDisplay() << setw(30) << m.getExpiredDate().dateDisplay() << endl;
	outFile.close();
	
	system("CLS");
	
	cout << "Your Information is Stored as Followed:" << endl;
	cout << "Name: " << m.pd.getName() << endl;
	cout << "Customer ID: " << m.getCustomerFullId() << endl;
	cout << "Age: " << m.pd.getAge() << endl;
	cout << "Phone No.: " << m.pd.getPhone() << endl;
	cout << "Trainer's Name: " << m.getTrainer().pd.getName() << endl;
	cout << "Membership: " << m.getMembership() << endl;
	cout << "Program's Name: " << m.getProgram()->getProgramName() << endl;
	cout << "Program Time: " << m.getProgram()->getProgramFullTime() << endl;
	cout << "Membership Start Date: " << m.getStartDate().dateDisplay() << endl;
	cout << "Membership Expired Date: " << m.getExpiredDate().dateDisplay() << endl;
	
	cout << endl;
	cout << "Have a Nice Day :]" << endl;
}
// Non-Member Data Storing Function
void outputCustomerData(NonMember nm, int &n)
{
	fstream outFile("CustomerList.txt", ios::app|ios::out);
	
	if (n == 1)
	{
		outFile << "=============================================================================================================================================================================================" << endl;
		outFile << setw(90) << right << "Customer List" << endl;
		outFile << "=============================================================================================================================================================================================" << endl;
		outFile << setw(5) << left << "NO" << setw(20) << "NAME" << setw(10) << "ID" << setw(5) << "AGE" << setw(15) << "PHONE NO." << setw(20) << "TRAINER" << setw(15) << "MEMBERSHIP" << setw(30) << "PROGRAM" << setw(15) << "PROGRAM TIME" << setw(30) << "MEMBERSHIP START DATE" << setw(30) << "MEMBERSHIP EXPIRED DATE" << endl;
	}
	
	outFile << left;
	outFile << setw(5) << n++ << setw(20) << nm.pd.getName() << setw(10) << nm.getCustomerFullId() << setw(5) << nm.pd.getAge() << setw(15) << nm.pd.getPhone() << setw(20) << nm.getTrainer().pd.getName() << setw(15) << nm.getMembership() << setw(30) << nm.getProgramName() << setw(15) << "NONE" << setw(30) << nm.getStartDate() << setw(30) << nm.getExpiredDate() << endl;
	outFile.close();
	
	system("CLS");
	
	cout << "Your Information is Stored as Followed:" << endl;
	cout << "Name: " << nm.pd.getName() << endl;
	cout << "Customer ID: " << nm.getCustomerFullId() << endl;
	cout << "Age: " << nm.pd.getAge() << endl;
	cout << "Phone No.: " << nm.pd.getPhone() << endl;
	cout << "Trainer's Name: " << nm.getTrainer().pd.getName() << endl;
	cout << "Membership: " << nm.getMembership() << endl;
	cout << "Program's Name: " << nm.getProgramName() << endl;
	cout << "Program Time: " << "NONE" << endl;
	cout << "Membership Start Date: " << nm.getStartDate() << endl;
	cout << "Membership Expired Date: " << nm.getExpiredDate() << endl;
	
	cout << endl;
	cout << "Have a Nice Day :]" << endl;
}
// Update Current Member ID Function
void updateCurrentMemberId(int n)
{
	fstream outFile("MID.txt", ios::out);
	
	outFile << n;
	outFile.close();
}
// Update Current Non-Member ID Function
void updateCurrentNonMemberId(int n)
{
	fstream outFile("NMID.txt", ios::out);
	
	outFile << n;
	outFile.close();
}
// Update Current List Number Function
void updateCurrentListNo(int n)
{
	fstream outFile("ListNo.txt", ios::out);
	
	outFile << n;
	outFile.close();
}

// Main Menu
void menu(Trainer *tList, int tS, Program* *pList, int pS)
{
	time_t now;
	time(&now);
	
	tm *ltm = localtime(&now);
	
	string line(10, '_');
	string cName;
	int cAge;
	string cPhone;
	
	cout << line << line << "WELCOME TO FITNESS CENTRE SELF-REGISTRATION SERVICE FOR NEW CUSTOMER!!!" << line << line << endl;
	cout << setw(3) << " " << line << line << line << line << "YOUR PERSONAL INFORMATION" << line << line << line << line << endl << endl;
	
	cout << "Name: ";
	getline(cin, cName);
	
	cout << "Age: ";
	cin >> cAge;
	cin.ignore();
	
	cout << "Phone No.: ";
	getline(cin, cPhone);
	
	system("CLS");
	
	cout << line << line << "WELCOME TO FITNESS CENTRE SELF-REGISTRATION SERVICE FOR NEW CUSTOMER!!!" << line << line << endl;
	cout << setw(2) << " " << line << line << line << line << "TRAINER ASSIGN & SELECTION" << line << line << line << line << endl << endl;
	
	cout << "Do you want to pay for personal trainer?" << endl << endl;
	cout << left;
	cout << setw(3) << "NO " << "ACTION" << endl;
	cout << setw(3) << 1 << "YES" << endl;
	cout << setw(3) << 2 << "NO" << endl;
	
	int input = 0;
	int counter = -1;

	Trainer *trainer = new Trainer;
	
	while(counter < 0)
	{
		cin >> input;
		
		switch(input)
		{
			case 1: int selection;
					selectTrainer(tList, selection, tS);
					trainer = &tList[selection - 1];
					displayTrainerInformation(*trainer);
					counter++;
					break;
			case 2: counter++;
					break;
			default:cout << "Invalid Input!!! Please Try Again!!!" << endl;
					break;
		}
	}
	
	system("CLS");
	
	cout << line << line << "WELCOME TO FITNESS CENTRE SELF-REGISTRATION SERVICE FOR NEW CUSTOMER!!!" << line << line << endl;
	cout << setw(8) << " " << line << line << line << line << "MEMBERSHIP SELECTION" << line << line << line << line << endl << endl;
	
	cout << "Do you want to become a member?" << endl;
	cout << "With member, you are able to access to our special class, and free to use our gym equipment :) " << endl << endl;
	cout << setw(3) << "NO " << "ACTION" << endl;
	cout << setw(3) << 1 << "YES" << endl;
	cout << setw(3) << 2 << "NO" << endl;
	
	Program *tempProgram;
	int day = 0;
	
	counter = -1;
	
	while(counter < 0)
	{
		cin >> input;
		
		switch(input)
		{
			case 1: selectMemberPack(day);
					selectProgram(pList, tempProgram, pS);
					counter++;
					break;
			case 2: tempProgram = new Yoga;
					counter++;
					break;
			default:cout << "Invalid Input!!! Please Try Again!!!" << endl;
					break;
		}
	}
	
	system("CLS");
	
	int mId = getCurrentMemberId();
	int nmId = getCurrentNonMemberId();
	int lNo = getCurrentListNo();
	
	if (day != 0)
	{
		cout << tempProgram->getProgramStartTime().timeDisplay() << endl << tempProgram->getProgramEndTime().timeDisplay() << endl;
		Member tempMember(cName, cAge, cPhone, mId, "YMB", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, day);
		tempMember + trainer;
		tempMember.assignProgram(tempProgram);
		outputCustomerData(tempMember, lNo);
		mId++;
	}
	else
	{
		NonMember tempNonMember(cName, cAge, cPhone, nmId, "NMB");
		tempNonMember + trainer;
		outputCustomerData(tempNonMember, lNo);
		nmId++;
	}

	updateCurrentMemberId(mId);
	updateCurrentNonMemberId(nmId);
	updateCurrentListNo(lNo);
	
	system("PAUSE");
}

// Main Function
int main()
{
	Trainer *trainerList;
	Program* *programList;
	int tListS = 0;
	int pListS = 0;	

	getTrainerList(trainerList, tListS);
	getProgramList(programList, pListS);
	
	menu(trainerList, tListS, programList, pListS);
}
