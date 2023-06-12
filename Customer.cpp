#include "Customer.h"
Customer::Customer(string n, int a, string p, int cId, string cFiD):pd(n, a, p)
{
	customerId = 1000 + cId;
	customerFullId = cFiD + to_string(customerId);
}

void Customer::setCustomerId(int cId)
{
	customerId = 1000 + cId;
}

int Customer::getCustomerId()
{
	return customerId;
}

void Customer::setCustomerFullId(string cFiD)
{
	customerFullId = cFiD + to_string(customerId);
}

string Customer::getCustomerFullId()
{
	return customerFullId;
}

void Customer::operator+(Trainer *train)
{
	trainer = train;
	trainerPaid = true;
}

Trainer Customer::getTrainer()
{
	return *trainer;
}

bool Customer::getTrainerPaid()
{
	return trainerPaid;
}
