#include "Trainer.h"
Trainer::Trainer(string n, int a, string p, string exp, string quali):pd(n, a, p)
{
	experience = exp;
	qualification = quali;
}

void Trainer::setExp(string exp)
{
	experience = exp;
}

string Trainer::getExp()
{
	return experience;
}

void Trainer::setQua(string quali)
{
	qualification = quali;
}

string Trainer::getQua()
{
	return qualification;
}
