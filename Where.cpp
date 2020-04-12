#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void where(char* Z, int (*F)(char*))
{
    int B[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 1;
    int n = -1;
    k = (*F)(Z);
    printf("\n");
    for (int j = 0; j < 20; j++)
    {
        if (*(Z + j) >= '0' && *(Z + j) <= '9')
            n = (*(Z + j) - '0');
        for (int i = 0; i < 11; i++)
        {
            if (n == B[i])
                k = 0;
        }
        if (k == 1)
            printf("%c", *(Z + j));
        n = -1;
        k = 1;
    }
}
