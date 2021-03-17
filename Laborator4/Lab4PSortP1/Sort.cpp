#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;

//1//

Sort::Sort(int n, int min, int max)
{
	rad = new Nod;
	srand(time(NULL));
	int r = rand() % (max - min + 1) + min;
	rad->val = r;
	rad->urm = NULL;
	Nod* temp = rad;
	for (int i = 1; i < n; i++) {
		r = rand() % (max - min + 1) + min;
		Nod* x = new Nod;
		x->val = r;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
	}
}

//2//

Sort::Sort(Nod* listh)
{
	Nod* temp;
	if (listh == NULL) {
		return;
	}
	temp = listh;
	rad = new Nod;
	rad->val = temp->val;
	temp = temp->urm;
	rad->urm = temp;
}

//3//

Sort::Sort(int v[], int n)
{
	rad = new Nod;
	int i = 0;
	int r = v[i++];
	rad->val = r;
	rad->urm = NULL;
	Nod* temp = rad;
	for (; i < n; i++) {
		r = v[i];
		Nod* x = new Nod;
		x->val = r;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
	}
}

//4//

Sort::Sort(int nrelem, ...)
{
	va_list L;
	va_start(L, nrelem);
	rad = new Nod;
	rad->val = va_arg(L, int);
	rad->urm = NULL;
	Nod* temp = rad;
	for (int i=1; i < nrelem; i++)
	{
		Nod* x = new Nod;
		x->val = va_arg(L, int);
		x->urm = NULL;
		temp->urm = x;
		temp = temp-> urm;
	}
	temp->urm = NULL;
	va_end(L);
}

//5//

int SCHIMBA(char nr[])
{
	int x = 0;
	int dim = strlen(nr);
	for (int i = 0; i < dim; i++)
		x = x * 10 + nr[i] - '0';
	return x;
}

Sort::Sort(const char* ss)
{
	char s[100];
	int val;
	strcpy(s, ss);
	char* nr = strtok(s, ",");
	val = SCHIMBA(nr);
	rad = new Nod;
	rad->val = val;
	rad->urm = NULL;
	Nod* temp = rad;
	nr = strtok(NULL, ",");
	while (nr != NULL)
	{
		val = SCHIMBA(nr);
		Nod* x = new Nod;
		x->val = val;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
		nr = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent)
{
	int v[100],i=0,key,j,n;
	n = GetElementsCount();
	Nod* temp = rad;
	while (temp)
	{
		v[i] = temp->val;
		i++;
		temp = temp->urm;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ascendent) {
				if (v[i] > v[j]) 
					swap(v[i], v[j]);
			}
			else {
				if (v[i] < v[j])
					swap(v[i], v[j]);
			}
		}
	}
	i = 0;
	rad = new Nod;
	int r = v[i++];
	rad->val = r;
	rad->urm = NULL;
	temp = rad;
	for (i=1; i < n; i++){
		r = v[i];
		Nod* x = new Nod;
		x->val = r;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int v[100], i = 0, key, j, n;
	n = GetElementsCount();
	Nod* temp = rad;
	while (temp)
	{
		v[i] = temp->val;
		i++;
		temp = temp->urm;
	}
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (ascendent) {
				if (v[j] > v[j + 1])
					swap(v[j],v[j + 1]);
			}
			else
				if (v[j] < v[j + 1])
					swap(v[j], v[j + 1]);
	i = 0;
	rad = new Nod;
	int r = v[i++];
	rad->val = r;
	rad->urm = NULL;
	temp = rad;
	for (i = 1; i < n; i++) {
		r = v[i];
		Nod* x = new Nod;
		x->val = r;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
	}
}

void partitie(int v[], int prim, int ultim, bool ascendent) 
{
	if (prim < ultim) 
	{
		int pivot = (prim + ultim) / 2;
		int aux = v[prim];
		v[prim] = v[pivot];
		v[pivot] = aux;
		int i = prim, j = ultim, b = 0;
		while (i < j) {
			if (ascendent) 
			{
				if (v[i] > v[j]) 
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					b = 1 - b;
				}
			}
			else 
			{
				if (v[i] < v[j]) 
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					b = 1 - b;
				}
			}

			i += b;
			j -= 1 - b;
		}
		partitie(v, prim, i - 1, ascendent);
		partitie(v, i + 1, ultim, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	int v[100], i = 0, key, j, n;
	n = GetElementsCount();
	Nod* temp = rad;
	while (temp)
	{
		v[i] = temp->val;
		i++;
		temp = temp->urm;
	}
	partitie(v, 0, n - 1, ascendent);
	i = 0;
	rad = new Nod;
	int r = v[i++];
	rad->val = r;
	rad->urm = NULL;
	temp = rad;
	for (i = 1; i < n; i++) {
		r = v[i];
		Nod* x = new Nod;
		x->val = r;
		x->urm = NULL;
		temp->urm = x;
		temp = temp->urm;
	}
}

/*void Sort::Merge(Sort& s)
{
	int a[100], b[100], c[100], i = 0, key, j, n, m;
	n = GetElementsCount();
	m = s.GetElementsCount();
	//c = new Sort();
	//this.rad = c;
	s.QuickSort(1);
	Nod* temp = rad;
	while (temp)
	{
		a[i] = temp->val;
		i++;
		temp = temp->urm;
	}
	Nod* temp = s.rad;
	while (temp)
	{
		b[i] = temp->val;
		i++;
		temp = temp->urm;
	}
	......
	.
	.
	.
	.
	.
}*/

void Sort::Print()
{
	Nod* temp = rad;
	while (temp)
	{
		cout << temp->val;
		if (temp->urm)
			cout << " -> ";
		temp = temp->urm;
	}
	cout << '\n';
}

int  Sort::GetElementsCount()
{
	int count=0;
	Nod* temp = rad;
	while (temp)
	{
		count++;
		temp = temp -> urm;
	}
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	int count=0;
	Nod* temp = rad;
	while (temp)
	{
		count++;
		if (count == index)
			return temp->val;
		temp = temp->urm;
	}
	return -1;
}