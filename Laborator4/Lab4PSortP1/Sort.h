#pragma once
class Nod {
public:
    int val;
    Nod* urm;
};

class Sort
{
    Nod* rad;
public:
    Sort(int, int, int);
    Sort(Nod*);
    Sort(int [], int);
    Sort(int, ...);
    Sort(const char*);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    //void partitie(int v[], int prim, int ultim, bool ascendent);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
    //void Merge(Sort& s); //interclasare, elemente comune apar de 2 ori...
};