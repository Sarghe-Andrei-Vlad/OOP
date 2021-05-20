#pragma once
#include <iostream>
#include <string>
using namespace std;
class Contact 
{
protected:
	string Name;
public:
	virtual string GetName() = 0;
};