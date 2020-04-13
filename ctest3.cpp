#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ctest3()
{
    int flag = 1;
    int i;
    char s1[20], s2[20], s3[20], k[20];
    printf("\nВведите строку: ");
    rewind(stdin);
    for (i = 0; i < 20; i++)
        k[i] = '0';
    for (i = 0; i < 20; i++)
        scanf("%c", &s1[i]);
    rewind(stdin);
    printf("\nВведите строку строчными буквами: ");
    rewind(stdin);
    for (i = 0; i < 20; i++)
        scanf("%c", &s2[i]);
    rewind(stdin);
    printf("\nВведите строку заглавными буквами: ");
    rewind(stdin);
    for (i = 0; i < 20; i++)
        scanf("%c", &s3[i]);
    rewind(stdin);

    for (i = 0; i < 20; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            k[i] = 'a' + (s1[i] - 'A');
        else k[i] = s1[i];
    }
    printf("\nСтрока, переведенная в строчные буквы функцией: ");
    for (i = 0; i < 20; i++)
    {
        printf("% c", k[i]);
        if (k[i] != s2[i])
            flag = 0;
    }
    printf("\nСтрока, переведенная в заглавные буквы функцией: ");
    for (i = 0; i < 20; i++)
    {
        if ('a' <= s1[i] && s1[i] <= 'z')
            k[i] = s1[i] + 'A' - 'a';
        else k[i] = s1[i];
    }
    for (i = 0; i < 20; i++)
    {
        printf("% c", k[i]);
        if (k[i] != s3[i])
            flag = 0;
    }
    if (flag == 0) return 0; else return 1;
}
