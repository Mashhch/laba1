#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
char* sklei(char s1[10], char s2[10], char s3[20], char* s);

int ctest1()
{
    printf("\nТест функции конкатенации: ");
    char konech[20];
    char konech1[20];
    int i;
    char* m3;
    char s1[10], s2[10];
    m3 = s1;
    int flag = 1;
    for (i = 0; i < 20; i++)
         konech[i] = '0';
    printf("Введите 1 строку: ");
    rewind(stdin);
    for (i = 0; i < 10; i++)
        scanf("%c", &s1[i]);
    rewind(stdin);
    printf("\nВведите 2 строку: ");
    rewind(stdin);
    for (i = 0; i < 10; i++)
        scanf("%c", &s2[i]);
    rewind(stdin);
    printf("\nВведите склееную строку: ");
    for (i = 0; i < 20; i++)
        scanf("%c", &konech1[i]);
    rewind(stdin);
    sklei(s1, s2, konech, m3);
    printf("\nСтрока, склеенная функцией: ");
    for (i = 0; i < 20; i++)
    {
        printf("%c", konech[i]);
    }
    for (i = 0; i < 20; i++)
    {
        if (konech1[i] != konech[i])
            flag = 0;
    }

    if (flag == 0) return 0; else return 1;
}
