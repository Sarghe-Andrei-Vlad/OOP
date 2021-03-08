#include "Math.h"

int Math::Add(int v1, int v2)
{
	return v1 + v2;
}

int Math::Add(int v1, int v2, int v3)
{
	return v1 + v2 + v3;
}

int Math::Add(double v1, double v2)
{
	return v1 + v2;
}

int Math::Add(double v1, double v2, double v3)
{
	return v1 + v2 + v3;
}

int Math::Mul(int v1, int v2)
{
	return v1 * v2;
}

int Math::Mul(int v1, int v2, int v3)
{
	return v1 * v2 * v3;
}

int Math::Mul(double v1, double v2)
{
	return v1 * v2;
}

int Math::Mul(double v1, double v2, double v3)
{
	return v1 * v2 * v3;
}

int Math::Add(int count, ...) // sums up a list of integers
{
	va_list List;
	va_start (List,count);
	int sum = 0;
	for (int i = 1; i <= count; i++)
		sum += va_arg(List, int);
	va_end(List);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
    char* rez = new char[100];
    int i,carry = 0;
    char nra[20], nrb[20];
    strcpy_s(nra,strlen(s1)+1 , s1); 
    strcpy_s(nrb,strlen(s2)+1, s2);
    _strrev(nra);
    _strrev(nrb);
    for (i = 0; i < min(strlen(nra), strlen(nrb)); i++)
    {
        int sum = (int)nra[i] - '0' + (int)nrb[i] - '0';
        if (sum + carry >= 10)
        {
            rez[i] = (char)((sum + carry) % 10 + '0');
            carry = sum / 10;
        }
        else
            rez[i] = (char)sum + carry + '0';
    }
    for (; i < max(strlen(nra), strlen(nrb)); i++)
    {
        if (nra[i] >= '0' && nra[i] <= '9')
        {
            rez[i] = (nra[i] - '0' + carry) % 10 + '0';
            carry = (nra[i] - '0' + carry) / 10;
        }
        if (nrb[i] >= '0' && nrb[i] <= '9')
        {
            rez[i] = (nrb[i] - '0' + carry) % 10 + '0';
            carry = (nrb[i] - '0' + carry) / 10;
        }
    }
    if (carry > 0)
        rez[i] = carry + '0';
    rez[i+1] = '\0';
    _strrev(rez);
    return rez;
}

char* Math::Sub(const char* s1, const char* s2)
{
    char* rez = new char[100];
    int i,carry = 0;
    char nra[20], nrb[20];
    if (strlen(s1) > strlen(s2))
    {
        strcpy_s(nra, strlen(s1) + 1, s1);
        strcpy_s(nrb, strlen(s2) + 1, s2);
    }
    else
    {
        strcpy_s(nrb, strlen(s1) + 1, s1);
        strcpy_s(nra, strlen(s2) + 1, s2);
    }
    _strrev(nra);
    _strrev(nrb);
    for (i = 0; i < min(strlen(nra), strlen(nrb)); i++)
    {
        int sub = (int)nra[i] - '0' - (int)nrb[i] + '0';
        if (sub - carry < 0)
        {
            rez[i] = 10 + ((int)nra[i] - '0') - carry - ((int)nrb[i] - '0') + '0';
            carry = 1;
        }
        else
            rez[i] = (char)sub - carry + '0';
    }
    for (; i < max(strlen(nra), strlen(nrb)); i++)
    {
        if (nra[i] >= '0' && nra[i] <= '9')
        {
            int sub = (int)nra[i] - '0';
            if (sub - carry < 0)
            {
                rez[i] = 10 + ((int)nra[i] - '0') - carry + '0';
                carry = 1;
            }
            else
                rez[i] = (char)sub - carry + '0';
        }
        if (nrb[i] >= '0' && nrb[i] <= '9')
        {
            int sub = (int)nrb[i] - '0';
            if (sub - carry < 0)
            {
                rez[i] = 10 + ((int)nrb[i] - '0') - carry + '0';
                carry = 1;
            }
            else
                rez[i] = (char)sub - carry + '0';
        }
    }
    rez[i] = '\0';
    _strrev(rez);
    if (rez[0] == '0')
    {
        for (int i = 1; i < strlen(rez); i++)
            rez[i - 1] = rez[i];
        rez[i-1] = '\0';
    }
    if (strlen(s1) < strlen(s2))
    {
        for (int i = strlen(rez); i > 0; i--)
            rez[i] = rez[i - 1];
        rez[0] = '-';
        rez[max(strlen(s1),strlen(s2))+1] = '\0';
    }
    return rez;
}