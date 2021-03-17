#pragma once
#pragma once
#include <list>
using namespace std;
class Sort
{
    list<int> List;
    int count;
public:
    Sort(int n, int min, int max);
    Sort(int n, int v[]);
    Sort(int nrelem, ...);
    Sort(const char*);
    Sort(list<int>);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};