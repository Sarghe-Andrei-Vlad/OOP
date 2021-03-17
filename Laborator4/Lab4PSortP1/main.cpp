#include "Sort.h"
#include <iostream>
int main()
{
	//1// 
	//Sort S(5, 10, 20);
	//2//
	/*Nod* root,* x,* y;
	root = new Nod;
	x = new Nod;
	y = new Nod;
	root->val = 15;
	root->urm = x;
	x->val = 3;
	x->urm = y;
	y->val = 8;
	y->urm = nullptr;
	Sort S(root);*/
	//3//
	/*int v[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Sort S(v, 10);*/
	//4//
	//Sort S(5, 1, 2, 3, 4, 5);
	Sort S("1,4,5,3,2");
	S.QuickSort(1);
	S.Print();
	std::cout << S.GetElementsCount() << '\n';
	std::cout << S.GetElementFromIndex(2) << '\n';
	return 0;
}