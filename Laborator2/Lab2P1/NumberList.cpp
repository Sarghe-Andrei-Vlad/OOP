#include "NumberList.h"

void NumberList::Init()
{
    count = 0;
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;
}

bool NumberList::Add(int x)     
{
    if (count >= 10)
        return false;
    numbers[count] = x;
    count++;
    return true;
}
                     
void NumberList::Sort()
{
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (numbers[j] > numbers[j + 1])
                std::swap(numbers[j], numbers[j + 1]);
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        std::cout << numbers[i] << " ";
}

void NumberList::Setcount(int count)
{
    this->count = count;
}

bool NumberList::Insert(int pozitie, int x)
{
    if (count >= 10)
        return false;
    count++;
    for (int i = count; i > pozitie; i--)
        numbers[i] = numbers[i - 1];
    numbers[pozitie] = x;
    return true;
}

void NumberList::RemoveNumber(int x)
{
    for (int i = 0; i < count; i++)
        while (numbers[i] == x)
        {
            for (int j = i; j < count; j++)
                numbers[j] = numbers[j + 1];
            count--;
        }
}