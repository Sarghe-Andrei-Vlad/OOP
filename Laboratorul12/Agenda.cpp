#include "Agenda.h"

Contact* Agenda::search(string name)
{
	for (auto contact : contacte)
	{
		if (contact->GetName() == name)
			return contact;
	}
}

vector<Prieten*> Agenda::listaprieteni()
{
	vector<Prieten*> prieteni;
	for (auto contact : contacte)
	{
		if (typeid(*contact) == typeid(Prieten))
		{
			//cast
			Prieten* p = dynamic_cast<Prieten*>(contact);
			prieteni.push_back(p);
		}
	}
	return prieteni;
}

void Agenda::deleteContact(string name)
{
	for (int i = 0; i < contacte.size(); i++)
		if (contacte[i]->GetName() == name)
			contacte.erase(contacte.begin() + i);
}

void Agenda::addContact(Contact* name)
{
	contacte.push_back(name);
}

void Agenda::show()
{
	for (auto contact : contacte)
		cout << contact->GetName() << " ";
	cout << '\n';
}