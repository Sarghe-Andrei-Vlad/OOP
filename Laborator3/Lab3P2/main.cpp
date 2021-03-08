#include "Canvas.h"

int main()
{
	Canvas Matrix(75,75);
	Matrix.DrawCircle(25, 25, 10, '#');
	Matrix.FillCircle(50, 50, 5, '#');
	Matrix.FillRect(-2, -10, 5, 5, '#');
	Matrix.DrawRect(15, -2, 20, 10, '#');
	Matrix.SetPoint(70, 70, '#');
	Matrix.DrawLine(55, 65, 60, 70, '#');
	//Matrix.Clear();
	Matrix.Print();
	return 0;
}