#include "student.h"
#include "Global.h"

int main()
{
	Student Vlad,Alin;
	Vlad.setName("Sarghe Andrei Vlad");
	Vlad.setMathGrade(9.85);
	Vlad.setHistGrade(2.12);
	Vlad.setEngGrade(10);
	Alin.setName("Ciulin Alexandru-Alin");
	Alin.setMathGrade(9.95);
	Alin.setHistGrade(2.02);
	Alin.setEngGrade(10);
	cout << Vlad.getName() << " ";
	cout << Vlad.getMathGrade() << " ";
	cout << Vlad.getEngGrade() << " ";
	cout << Vlad.getHistGrade() << " ";
	cout << Vlad.getAvgG()<< " "<< "\n" ;
	cout << Alin.getName() << " ";
	cout << Alin.getMathGrade() << " ";
	cout << Alin.getEngGrade() << " ";
	cout << Alin.getHistGrade() << " ";
	cout << Alin.getAvgG() << " " << "\n";
	cout << compareName(Vlad, Alin) << " ";
	cout << compareMathGrade(Vlad, Alin) << " ";
	cout << compareEngGrade(Vlad, Alin) << " ";
	cout << compareHistGrade(Vlad, Alin) << " ";
	cout << compareAvgGrade(Vlad, Alin) << " " << "\n" ;
	return 0;
}