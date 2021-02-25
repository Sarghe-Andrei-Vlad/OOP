#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Student {
private:
	string name;
	float MathG, EngG, HistG;
public:
	void setName(string);
	string getName();
	void setMathGrade(float);
	float getMathGrade();
	void setEngGrade(float);
	float getEngGrade();
	void setHistGrade(float);
	float getHistGrade();
	float getAvgG();
};