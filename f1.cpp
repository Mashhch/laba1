#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sklei(char s1[10], char s2[10], char s3[20], char* s);
char* vvod(char s[10], int m, char* d);

char* f1(char* w, char konech[20])
{

    printf("\nf1: ");
    int i;
    char* m1;
    char* m2;
    char* m3;
    char s1[10], s2[10];
    m1 = s1;
    m2 = s1;
    m3 = s1;
    vvod(s1, 1, m1);
    vvod(s2, 2, m2);
    w = sklei(s1, s2, konech, m3);
    printf("\nf1 Склеенная строка: ");
    for (i = 0; i < 20; i++)
    {
        printf("%c", *(i + w));
    }

    return w;
}
