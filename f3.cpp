#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* f3(char* s1, char s[20])
{
    printf("\n f3 строка: ");
    char m[20] = "this is a string kk";
    for (int i = 0; i < 20; i++)
    {
        s[i] = m[i];
    }
    for (int i = 0; i < 20; i++)
        printf("%c", s[i]);
    s1 = s;

    return s1;
}
