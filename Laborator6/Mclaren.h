#pragma once
#include "Car.h"
class Mclaren :public Car
{
public:
	Mclaren();
	~Mclaren();
	void SetFuelCap(float);
	void SetFuelCons(float);
	void SetAvgSpeed(float);
	float GetFuelCap();
	float GetFuelCons();
	float GetAvgSpeed();
	char* GetName();
};