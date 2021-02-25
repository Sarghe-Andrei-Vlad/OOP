#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
using namespace std;
struct words
{
    int length;
    char cuv[101];
}word[101];

int main()
{
    int c = 0;
    int calf = 0;
    char prop[101];
    gets_s(prop);
    char* p = strtok(prop, " ,.-");
    while (p != NULL)
    {
        strcpy(word[c].cuv, p);
        word[c].length = strlen(p);
        p = strtok(NULL, " ,.-");
        c++;
    }
    for (int i = 0; i < c - 1; i++)
        for (int j = i + 1; j < c; j++)
            if (word[i].length < word[j].length)
            {
                words aux = word[i];
                word[i] = word[j];
                word[j] = aux;
            }else
                if (word[i].length == word[j].length)
                {
                    calf = strcmp(word[i].cuv, word[j].cuv);
                        if (calf > 0)
                        {
                            words aux = word[i];
                            word[i] = word[j];
                            word[j] = aux;
                        }
                }
    for (int i = 0; i < c; i++)
        printf("%s\n", word[i].cuv);
}