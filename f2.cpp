#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* f2(char* s1, char s[20])
{
    s[20];
    char SET[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789";
    int i, set_len;
    srand((unsigned)time(NULL));
    set_len = strlen(SET);
    for (i = 0; i < 20; i++)
        s[i] = SET[rand() % set_len];
    printf("\n f2 строка: ");
    for (i = 0; i < 20; i++)
        printf("%c", s[i]);
    s1 = s;
    return s1;
}