#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* sklei(char s1[10], char s2[10], char s3[20], char* s)
{

    int i, j;
    i = 0;
    j = 0;

    for (i = 0; i < 10; i++)
        s3[i] = s1[i];
    for (j = 0; j < 10; j++)
        s3[j + 10] = s2[j];
    s = s3;
    return s;
}