#define _CRT_SECURE_NO_WARNINGS
#include "Ferrari.h"
#include <stdlib.h>
#include <string>
Ferrari::Ferrari()
{
	this->Name = (char*)malloc(sizeof(char) * 8);
	strcpy(this->Name, "Ferrari");
	SetFuelCap(40);
	SetFuelCons(35);
	SetAvgSpeed(165);
}

Ferrari::~Ferrari() {}

void Ferrari::SetFuelCap(float n)
{
	this->FuelCap = n;
}
void Ferrari::SetFuelCons(float n)
{
	this->FuelCons = n;
}
void Ferrari::SetAvgSpeed(float n)
{
	this->AvgSpeed = n;
}
float Ferrari::GetFuelCap()
{
	return this->FuelCap;
}
float Ferrari::GetFuelCons()
{
	return this->FuelCons;
}
float Ferrari::GetAvgSpeed()
{
	return this->AvgSpeed;
}
char* Ferrari::GetName()
{
	return this->Name;
}