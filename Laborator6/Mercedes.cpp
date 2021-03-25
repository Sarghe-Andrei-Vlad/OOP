#define _CRT_SECURE_NO_WARNINGS
#include "Mercedes.h"
#include <stdlib.h>
#include <string>
Mercedes::Mercedes() 
{
	this->Name = (char*)malloc(sizeof(char) * 9);
	strcpy(this->Name, "Mercedes");
	SetFuelCap(50);
	SetFuelCons(20);
	SetAvgSpeed(130);
}

Mercedes::~Mercedes() {}

void Mercedes::SetFuelCap(float n)
{
	this->FuelCap = n;
}
void Mercedes::SetFuelCons(float n)
{
	this->FuelCons = n;
}
void Mercedes::SetAvgSpeed(float n)
{
	this->AvgSpeed = n;
}
float Mercedes::GetFuelCap()
{
	return this->FuelCap;
}
float Mercedes::GetFuelCons()
{
	return this->FuelCons;
}
float Mercedes::GetAvgSpeed()
{
	return this->AvgSpeed;
}
char* Mercedes::GetName()
{
	return this->Name;
}