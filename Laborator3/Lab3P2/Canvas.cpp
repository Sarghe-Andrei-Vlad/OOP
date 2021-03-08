#include "Canvas.h"
#include <iostream>
using namespace std;
Canvas::Canvas(int pwidth, int pheight) 
{
	width = pwidth;
	height = pheight;
	matrix = new char* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new char[width];
	}
	// initializare cu caracterul 32(ala invizibil)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) 
{
	double pi = 2 * acos(0.0);
	for (double angle = 0; angle < 2 * pi; angle += 0.1)
	{
		double dx = ray * cos(angle);
		double dy = ray * sin(angle);
		if((int)ceil(x + dx)>=0 && (int)ceil(x + dx)< width && (int)ceil(y + dy)>=0 && (int)ceil(y + dy)<height)
			matrix[(int)ceil(x + dx)][(int)ceil(y + dy)] = ch;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			std::cout << matrix[i][j];
		std::cout << '\n';
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) 
{
	int r = ray;
	while (r)
	{
		Canvas::DrawCircle(x, y, r, ch);
		r--;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if(top<=bottom && left<right)
		for (int i = top; i <= bottom; i++)
			for (int j = left; j <= right; j++)
				if(i>=0 && i<=height && j>=0 && j<=width)
					matrix[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		if (i >= 0 && i <= height)
		{
			if (left >= 0 && left <= width)
				matrix[i][left] = ch;
			if (right >= 0 && right <= width)
				matrix[i][right] = ch;
		}
	for (int i = left; i <= right; i++)
		if (i >= 0 && i <= width)
		{
			if (top >= 0 && top <= height)
				matrix[top][i] = ch;
			if (bottom >= 0 && bottom <= height)
				matrix[bottom][i] = ch;
		}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		matrix[x][y] = ch;
}

void Canvas::Clear() // clears the canvas*/
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{

	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		SetPoint(x, y, ch);
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}