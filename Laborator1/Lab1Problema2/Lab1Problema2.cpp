#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
int main() {
    FILE* f = fopen("In.txt", "r");
    char c[101];
    int sum = 0;
    int nr = 0;
    while (fscanf(f, "%s", c) != EOF) {
        int dim = strlen(c);
        nr = 0;
        int i = 0;
        bool testneg = false;
        if (c[i] == '-') {
            i = 1;
            testneg = true;
        }
        for (; i < dim; i++)
            nr = nr * 10 + (c[i] - '0');
        if (testneg == true)
            nr = -nr;
        sum += nr;
    }
    printf("%d", sum);
}