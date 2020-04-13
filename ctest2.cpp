#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Cif(char* S);

int ctest2()
{
    char s[20];
    char* s1;
    s1 = s;
    int t;
    int flag = 1;
    printf("Тест функции where:");
    printf("\nВведите строку с цифрами:");
    rewind(stdin);
    for (int i = 0; i < 20; i++)
        scanf("%c", &s[i]);
    rewind(stdin);
    t = Cif(s1);
    printf("Введите строку без цифр(дополнив строку до 20 символов нулями:  ");
    for (int i = 0; i < 20; i++)
        scanf("%c", &s[i]);
    printf("Строка, которую выведет функция where:  ");
    int m = 0;
    if (t == 1)
        for (int j = 0; j < 20; j++)
        {
            if (*(s1 + j) > '9' || *(s1 + j) < '0')
            {
                printf("%c", *(s1 + j));
                if (s[m] != *(s1 + j))
                    flag = 0;
                m++;
            }
        }
    if (flag == 0) return 0; else return 1;
}

