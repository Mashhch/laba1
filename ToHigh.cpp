#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ToHigh(char* c)
{
    if ('a' <= *c && *c <= 'z')
        printf("%c", *c + 'A' - 'a');
    else printf("%c", *c);
}