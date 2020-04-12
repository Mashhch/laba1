#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* vvod(char s[10], int m, char* d)
{
    char SET[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789";
    int i, set_len;
    srand(m);
    set_len = strlen(SET);
    for (i = 0; i < 10; i++)
        s[i] = SET[rand() % set_len];
    printf("\n %d строка: ", m);
    for (i = 0; i < 10; i++)
        printf("%c", s[i]);
    d = s;
    return d;
}