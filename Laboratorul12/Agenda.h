#pragma once
#include "Contact.h"
#include "Prieten.h"
#include <vector>
class Agenda {
	vector<Contact*> contacte;
public:
	Contact* search(string);
	vector<Prieten*> listaprieteni();
	void deleteContact(string);
	void addContact(Contact*);
	void show();
};