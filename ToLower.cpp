#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ToLower(char* c)
{
    if (*c >= 'A' && *c <= 'Z')
        printf("%c", 'a' + (*c - 'A'));
    else printf("%c", *c);
}