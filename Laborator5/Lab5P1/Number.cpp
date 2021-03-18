#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

int todeci(char* str, int base)
{
    int len = strlen(str);
    int pow = 1;
    int num = 0;
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }
        num += val(str[i]) * pow;
        pow = pow * base;
    }
    return num;
}

char* fromdeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    _strrev(res);
    return res;
}

Number::Number(const char* newValue, int newBase)
{
    size = strlen(newValue);
    value = new char[32];
    strcpy(value, newValue);
    base = newBase;
}

Number::Number(const Number& n) 
{
    size = n.size;
    base = n.base;
    value = new char[32];
    memcpy(value, n.value, 32);
}

Number::Number(int x)
{
    value = new char[32];
    int aux = x, nrc = 0;
    sprintf(value, "%d", aux);
    base = 10;
    size = strlen(value);
}

Number::~Number()
{
    delete[] value;
}

void Number::operator=(const Number& n)
{
    Number x(n.value, n.base);
    x.SwitchBase(base);
    size = x.size;
    base = x.base;
    value = new char[32];
    memcpy(value, x.value, 32);
}

void Number::operator=(const char* newValue)
{
    size = strlen(newValue);
    value = new char[32];
    memcpy(value, newValue, 32);
}

void Number::operator-()
{
    int aux = atoi(value);
    aux = aux * (-1);
    _itoa(aux, value, base);
}

char& Number::operator[](int index)
{
    return value[index];
}

Number operator+(const Number& n1, const Number& n2)
{
    int Add, AddBase;
    char str[32];
    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);
    a.SwitchBase(10);
    b.SwitchBase(10);
    Add = atoi(a.value) + atoi(b.value);
    sprintf(str, "%d", Add);
    AddBase = max(a.base, b.base);
    Number rez(str, 10);
    rez.SwitchBase(AddBase);
    return rez;
}

Number Number::operator|(const Number& n)
{
    int pipe, pipeBase;
    char str[64];
    Number a(value, base);
    pipeBase = max(a.base, n.base);
    Number b(n.value, n.base);
    if (a.base < b.base)
    {
        a.SwitchBase(b.base);
    }
    else {
        b.SwitchBase(a.base);
    }
    strcpy(str, a.value);
    strcat(str, b.value);
    Number rez(str, pipeBase);
    return rez;
}

Number operator-(const Number& n1, const Number& n2)
{
    int Dif, DifBase;
    char str[10];
    Number a(n1.value, n1.base);
    Number b(n2.value, n2.base);
    a.SwitchBase(10);
    b.SwitchBase(10);
    Dif = atoi(a.value) - atoi(b.value);
    sprintf(str, "%d", Dif);
    DifBase = max(a.base, b.base);
    Number rez(str, 10);
    rez.SwitchBase(DifBase);
    return rez;
}

bool Number::operator>(const Number& n1)
{
    bool G=0;
    Number a(value, base);
    Number b(n1.value, n1.base);
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (atoi(a.value) > atoi(b.value))
        G = 1;
    return G;
}

Number operator+=(Number& n1, const Number& n2)
{
    n1 = n1 + n2;
    return n1;
}

void Number::SwitchBase(int newBase)
{
    int z;
    z = todeci(value, base);
    fromdeci(value, newBase, z);
    base = newBase;
    size = strlen(value);
}

void Number::Print()
{
    cout << value << '\n';
}

int  Number::GetDigitsCount()
{
    return size;
}

int  Number::GetBase()
{
    return base;
}

