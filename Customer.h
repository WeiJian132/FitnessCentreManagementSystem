#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PersonalDetail.h"
#include "Trainer.h"

class Customer
{
	private:
		int customerId;
		string customerFullId;
		bool trainerPaid = false;
		Trainer *trainer;
	public:
		PersonalDetail pd;
		Customer(string n = "NONE", int a = 0, string p = "NONE", int cId = 0, string cFiD = "NONE");
		
		void setCustomerId(int cId);
		int getCustomerId();
		
		void setCustomerFullId(string cFiD);
		string getCustomerFullId();
		
		void operator+(Trainer *train);
		Trainer getTrainer();
		bool getTrainerPaid();
};

#endif
