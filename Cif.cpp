#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Cif(char* S)
{
    int B[10] = { 1,2,3,4,5,6,7,8,9,0 };
    int flag = 0;
    for (int i = 0; i < 20; i++)
    {
        if (*(S + i) <= '9' && *(S + i) >= '0')
            flag = 1;
    }
    if (flag == 1) return 1; else return 0;
}