#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void map(char* Z, void (*F)(char*))
{
    (*F)(Z);
}

