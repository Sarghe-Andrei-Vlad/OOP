#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdarg>
#include <string>

//1
Sort::Sort(int n, int min, int max)
{
	count = n;
	int x = min - 1;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		while (x < min)
			x = rand() % max + 1;
		List.push_back(x);
		x = min - 1;
	}
}

//2
Sort::Sort(list<int> l)
{
	count = l.size();
	list <int> ::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
		List.push_back(*it);
}

//3
Sort::Sort(int n, int v[])
{
	count = n;
	for (int i = 0; i < n; i++)
		List.push_back(v[i]);
}

//4
Sort::Sort(int nrelem, ...)
{
	count = nrelem;
	va_list L;
	va_start(L, nrelem);
	for (int i = 0; i < nrelem; i++)
		List.push_back(va_arg(L, int));
	va_end(L);
}

int SCHIMBA(char nr[])
{
	int x = 0;
	int dim = strlen(nr);
	for (int i = 0; i < dim; i++)
		x = x * 10 + nr[i] - '0';
	return x;
}

//5
Sort::Sort(const char* ss)
{
	count = 0;
	char s[100];
	int x;
	strcpy(s, ss);
	char* nr = strtok(s, ",");
	while (nr != NULL)
	{
		x = SCHIMBA(nr);
		List.push_back(x);
		count++;
		nr = strtok(NULL, ",");
	}
}

/*inline int max(int a, int b)
{
	return a > b ? a : b;
}*/

void Sort::Print()
{
	list <int> ::iterator it;
	for (it = List.begin(); it != List.end(); ++it)
		cout << *it << " -> ";
	cout << "NULL";
	cout << '\n';
}
int  Sort::GetElementsCount()
{
	return count;
}
int  Sort::GetElementFromIndex(int index)
{
	int x = 0;
	list <int> ::iterator it;
	for (it = List.begin(); it != List.end(); ++it)
	{
		x++;
		if (x == index)
			return *it;
	}
	return -1;
}

//true->crescator
//false->descrescator
void Sort::InsertSort(bool ascendent = false)
{
	list <int> ::iterator it, jt;
	int i, key, j;
	for (it = List.begin(); it != List.end(); ++it)
	{
		key = *it;
		jt = *(it - 1);
		while (jt != List.begin && *jt > key)
		{
			*(jt+1) = *jt;
			jt = jt - 1;
		}
		*(jt+1) = key;
	}
}


//void Sort::QuickSort(bool ascendent = false);
//void Sort::BubbleSort(bool ascendent = false);