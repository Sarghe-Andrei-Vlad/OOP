#include "Car.h"
#include "Ferrari.h"
#include "Mclaren.h"
#include "Mercedes.h"
#include "Circuit.h"
#include <iostream>
Circuit::Circuit() {}
Circuit::~Circuit() {}
void Circuit::SetLength(float n)
{
	this->length = n;
}

void Circuit::SetWeather(Weather n)
{
	this->weather = n;
}

void Circuit::AddCar(Car* newcar)
{
	Cars.push_back(newcar);
	Cars[Cars.size() - 1]->SetAvgSpeed(Cars[Cars.size() - 1]->GetAvgSpeed() * (100 - 20 * this->weather) / 100);
	Cars[Cars.size() - 1]->SetFuelCons(Cars[Cars.size() - 1]->GetFuelCons() * (100 + 15 * this->weather) / 100);
}

void Circuit::Race()
{
	int n = Cars.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (Cars[i]->GetAvgSpeed() < Cars[j]->GetAvgSpeed())
				std::swap(Cars[i], Cars[j]);
}

void Circuit::ShowFinalRanks()
{
	int p = 1;
	float t;
	for (int i = 0; i < Cars.size(); i++)
		if (Cars[i]->GetFuelCap() / Cars[i]->GetFuelCons() * 100 >= this->length)
		{
			t = this->length / Cars[i]->GetAvgSpeed() * 100;
			std::cout << "Locul " << p++ << ": " << Cars[i]->GetName() << " " << "a terminat cursa in "<< t << " minute" << '\n';
		}
}

void Circuit::ShowConsumptionRanks()
{
	int p = 1;
	int n = Cars.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (Cars[i]->GetFuelCons() > Cars[j]->GetFuelCons())
				std::swap(Cars[i], Cars[j]);
	for (int i = 0; i < Cars.size(); i++)
		std::cout << p++ << " " << Cars[i]->GetName() << " a consumat " << Cars[i]->GetFuelCons() << " l/100km" << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "Nu au terminat cursa: " << "- ";
	for (int i = 0; i < Cars.size(); i++)
		if (Cars[i]->GetFuelCap() / Cars[i]->GetFuelCons() * 100 <= this->length)
			std::cout << Cars[i]->GetName() << "\t";
	std::cout << '\n';
}