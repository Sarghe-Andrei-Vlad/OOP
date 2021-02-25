#include "student.h"

void Student::setName(string Newname)
{
	name = Newname;
}

string Student::getName()
{
	return name;
}

void Student::setMathGrade(float Grade)
{
	if(Grade>=1 && Grade<=10)
		MathG = Grade;
}

float Student::getMathGrade()
{
	return MathG;
}

void Student::setEngGrade(float Grade)
{
	if (Grade >= 1 && Grade <= 10)
		EngG = Grade;
}

float Student::getEngGrade()
{
	return EngG;
}

void Student::setHistGrade(float Grade)
{
	if (Grade >= 1 && Grade <= 10)
		HistG = Grade;
}

float Student::getHistGrade()
{
	return HistG;
}

float Student::getAvgG()
{
	float Avg;
	Avg = (MathG + EngG + HistG) / 3;
	return Avg;
}