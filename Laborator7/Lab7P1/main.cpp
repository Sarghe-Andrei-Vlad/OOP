#include <iostream>

float operator"" _Kelvin(unsigned long long c) { return c + 273.15; }

float operator"" _Fahrenheit(unsigned long long c) { return (c * 1.8) + 32; }

int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	std::cout << a << " " << b;
	return 0;
}