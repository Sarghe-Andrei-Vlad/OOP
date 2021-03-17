#include "Sort.h"
#include <iostream>
int main()
{
	//ios::sync_with_stdio(false);
	//Sort Lista(11, 5, 20);
	//int v[] = { 1515, 24, 43, 5, 643, 3, 2, 1, 43, 100};
	//Sort Lista(10, v);
	//Sort Lista(5, 1, 2, 3, 4, 5);
	//Sort Lista("5,1,2,5,4,5");
	list<int> l = {5,4,5,5,45,4,54,4,5};
	Sort Lista(l);
	Lista.Print();
	cout << Lista.GetElementsCount() << "\n";
	cout << Lista.GetElementFromIndex(2) << '\n';
	return 0;
}