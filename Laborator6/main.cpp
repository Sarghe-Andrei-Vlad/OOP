#include "Circuit.h"
#include "Mercedes.h"
#include "Ferrari.h"
#include "Mclaren.h"
#include "Car.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Ferrari());
	c.AddCar(new Mclaren());
	c.AddCar(new Mercedes());
	c.Race();
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish();
	c.ShowConsumptionRanks();
	return 0;
}