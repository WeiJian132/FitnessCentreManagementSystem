#ifndef TRAINER_H
#define TRAINER_H

#include "PersonalDetail.h"

class Trainer
{
	private:
		string experience;
		string qualification;
	public:
		PersonalDetail pd;
		Trainer(string n = "NONE", int a = 0, string p = "NONE", string exp = "NONE", string quali = "NONE");
		
		void setExp(string exp);
		string getExp();
		
		void setQua(string quali);
		string getQua();
};

#endif
