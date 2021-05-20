#pragma once
#include "Contact.h"
class Cunoscut: public Contact
{
protected:
	string PhoneNr;
public:
	void setData(string NewName, string Nr)
	{
		Name = NewName;
		PhoneNr = Nr;
	}
	string GetName() { return Name; }
	string GetTelefon(string _name) { return PhoneNr; }
};