#define _CRT_SECURE_NO_WARNINGS
#include "Mclaren.h"
#include <stdlib.h>
#include <string>
Mclaren::Mclaren()
{
	this->Name = (char*)malloc(sizeof(char) * 8);
	strcpy(this->Name, "Mclaren");
	SetFuelCap(45);
	SetFuelCons(30);
	SetAvgSpeed(150);
}

Mclaren::~Mclaren() {}

void Mclaren::SetFuelCap(float n)
{
	this->FuelCap = n;
}
void Mclaren::SetFuelCons(float n)
{
	this->FuelCons = n;
}
void Mclaren::SetAvgSpeed(float n)
{
	this->AvgSpeed = n;
}
float Mclaren::GetFuelCap()
{
	return this->FuelCap;
}
float Mclaren::GetFuelCons()
{
	return this->FuelCons;
}
float Mclaren::GetAvgSpeed()
{
	return this->AvgSpeed;
}
char* Mclaren::GetName()
{
	return this->Name;
}