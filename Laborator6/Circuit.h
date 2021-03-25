#pragma once
#include "Car.h"
#include <vector>
enum Weather {
	Sunny, Rain, Snow
};
class Circuit
{
private:
	float length;
	Weather weather;
	std::vector<Car*> Cars;
public:
	Circuit();
	~Circuit();
	void SetLength(float);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks(); 
	void ShowConsumptionRanks();
	void ShowWhoDidNotFinish();
};