#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void where(char* Z, int (*F)(char*))
{
    int B[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 1;
    int t;
    int n = -1;
    t = (*F)(Z);
    if (t == 1)
    {
        printf("\n");
        for (int j = 0; j < 20; j++)
        {
            if (*(Z + j) > '9' || *(Z + j) < '0')
                printf("%c", *(Z + j));
        }
    }
}



