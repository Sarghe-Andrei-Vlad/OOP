#pragma once
#include "Car.h"
class Mercedes:public Car
{
public:
	Mercedes();
	~Mercedes();
	void SetFuelCap(float);
	void SetFuelCons(float);
	void SetAvgSpeed(float);
	float GetFuelCap();
	float GetFuelCons();
	float GetAvgSpeed();
	char* GetName();
};