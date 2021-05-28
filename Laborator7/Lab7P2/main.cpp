#include "classtemplate.h"
#include <iostream>
//using namespace std;

int main()
{
    Vector<int, 10> v;
    v.Push(6);
    v.Print();
    v.Push(2);
    v.Print();
    v.Push(5);
    cout << "Vectorul este: ";
    v.Print();
    cout << "Elementul scos din vector este: " << v.Pop() << endl;
    v.Print();
    //v.Remove(1);
    //v.Print();
    v.Insert(1, 11);
    v.Print();
}