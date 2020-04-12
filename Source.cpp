#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Cif(char* S)
{
    int k = 0;
    int n = -1;
    int B[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int j = 0; j < 20; j++)
    {
        if (*(S + j) >= '0' && *(S + j) <= '9')
            n = (*(S + j) - '0');
        for (int i = 0; i < 11; i++)
        {
            if (n == B[i])
                k = 1;
        }
        n = -1;
    }
    if (k == 1) return 1; else return 0;
}
