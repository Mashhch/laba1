#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* f8(char* s1, char s[20])
{
    char m[20] = "sad sad sad sad sad";
    for (int i = 0; i < 20; i++)
    {
        s[i] = m[i];
    }
    printf("\n f8 ������: ");
    for (int i = 0; i < 20; i++)
        printf("%c", s[i]);
    s1 = s;

    return s1;
}