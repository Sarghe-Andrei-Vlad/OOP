#pragma once
#include "Contact.h"
class Prieten : public Contact
{
protected:
	string BirthDate, PhoneNr, Adress;
public:
	void setData(string NewName, string Date, string Nr, string Adr)
	{
		Name = NewName;
		BirthDate = Date;
		PhoneNr = Nr;
		Adress = Adr;
	}
	string GetName() { return Name; }
	string GetBirthDate(string Name) { return BirthDate; }
	string GetPhoneNr(string Name) { return PhoneNr; }
	string GetAdress(string Name) { return Adress; }
};