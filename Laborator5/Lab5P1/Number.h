#pragma once
#include <string>
#include <iostream>
using namespace std;
class Number
{
	char* value;
	int base, size;
public:

	Number(const char* newValue, int newBase); // where base is between 2 and 16
	Number(const Number& n);
	Number(int);
	~Number();

	void operator=(const Number& n1);
	void operator=(const char* newValue);
	void operator-();
	char& operator[](int index);
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	friend Number operator+=(Number& n1, const Number& n2);
	Number operator|(const Number& n);
	bool operator>(const Number& n1);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};