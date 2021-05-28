#pragma once
#include <iostream>
using namespace std;
template <class T,int size>

class Vector {
	int n;
	T* v;
public:
	Vector()
	{
		v = new T[size];
	}
	~Vector()
	{
		delete[] v;
	}
	void Push(const T& elem)
	{
		v[n] = elem;
		n++;
	}
	T Pop()
	{
		n--;
		T x=v[n];
		return x;
	}
	void Tempdelete(int poz)
	{
		for (int i = poz; i < n; i++)
			v[i] = v[i + 1];
		n--;
	}
	void Insert(int poz, T elem) 
	{
		n++;
		for (int i = n; i > poz; i--)
			v[i] = v[i-1];
		v[poz] = elem;
	}
	void Print()
	{
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
			cout << '\n';
	}

};
