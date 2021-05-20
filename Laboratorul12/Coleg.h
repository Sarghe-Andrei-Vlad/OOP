#pragma once
#include "Contact.h"
class Coleg : public Contact
{
protected:
	string PhoneNr, Workplace, Adress;
public:
	void setData(string NewName, string Nr, string Work, string Adr)
	{
		Name = NewName;
		PhoneNr = Nr;
		Workplace = Work;
		Adress = Adr;
	}
	string GetName() { return Name; }
	string GetPhoneNr(string Name) { return PhoneNr; }
	string GetWorkplace(string Name) { return Workplace; }
	string GetAdress(string Name) { return Adress; }
};