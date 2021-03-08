#include "Math.h"

int main()
{
	Math Calcul;
	cout << Math::Add(10, 12) << endl;
	cout << Calcul.Add(10, 12, 14) << endl;
	cout << Calcul.Add(1.5, 2.5) << endl;
	cout << Calcul.Add(1.5, 2.5, 2.7) << endl;
	cout << Calcul.Mul(10, 12) << endl;
	cout << Calcul.Mul(10, 12, 2) << endl;
	cout << Calcul.Mul(1.5, 2.5) << endl;
	cout << Calcul.Mul(1.5, 2.5, 1.4) << endl;
	cout << Calcul.Add(6, 5, 10, 20, 30, 40, 50) << endl ;
	char* rez1 = Math::Add("1", "99");
	cout << rez1 << endl;
	delete[] rez1;
	char* rez2 = Math::Sub("1", "100000");
	cout << rez2 << endl;
	delete[] rez2;
	return 0;
}