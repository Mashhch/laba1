#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

char** funcs;
int Cif(char* S);
void where(char* Z, int (*F)(char*));
void map(char* Z, void (*F)(char*));
void ToHigh(char* c);
void ToLower(char* c);
char** fs();
char* sklei(char s1[10], char s2[10], char s3[20], char* s);
char* vvod(char s[10], int m, char* d);
char* f1(char* w, char konech[20]); // ������������
char* f2(char* s1, char s[20]);
char* f3(char* s1, char s[20]);
char* f4(char* s1, char s[20]);
char* f5(char* s1, char s[20]);
char* f6(char* s1, char s[20]);
char* f7(char* s1, char s[20]);
char* f8(char* s1, char s[20]);
char* f9(char* s1, char s[20]);

// ������ ���������� �� �������
char** fs() {

    char** funcs = (char**)malloc(9 * sizeof(char*));
    for (int i = 0; i < 9; i++)
        funcs[i] = (char*)malloc(sizeof(char*));
    funcs[0] = (char*)(&f1);
    funcs[1] = (char*)(&f2);
    funcs[2] = (char*)(&f3);
    funcs[3] = (char*)(&f4);
    funcs[4] = (char*)(&f5);
    funcs[5] = (char*)(&f6);
    funcs[6] = (char*)(&f7);
    funcs[7] = (char*)(&f8);
    funcs[8] = (char*)(&f9);

    return funcs;
}

int main()
{
    system("chcp 1251");
    system("cls");
    char SET[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm123456789";
    int set_len;
    srand((unsigned)time(NULL));
    int N;
    int n;
    char* e[9];
    char t[9][20];

    // ������������� ��� �������� � �������
    for (int i = 0; i < 9; i++)
    {
        for(int j=0;j<2;j++)
            t[i][j] = '0';
        e[i] = t[i];
    }


    N = rand() % 20 + 10;
    printf("����������� ��������� � �������: %d", N);
    n = (rand() * 7) % 10;
    printf("\n����������� ������� � �������(<10):%d", n);

    void** A = (void**)malloc(N * sizeof(void*)); // ������������ ������ ���������� �� ������� � ������

    //��������� �� �������
    for (int i = 0; i < N; i++)
    {
        A[i] = fs()[i];
    }

    //������ ����� ����� 20
   char* a = (char*)malloc((N-n) * 20 * sizeof(char));
    for (int i = 0; i < N-n; i++)  
    {
        for (int j = 0; j < 20; j++) 
        {
            srand(j+i*12+ (unsigned)time(NULL));
            set_len = strlen(SET);
            *(a + i * 20 + j) = SET[rand() % set_len];
        }
    }

    //��������� �� ������
    for (int i = n; i < N; i++)
        A[i] = a + (i - n) * 20;

    //����� �� �����
    printf("\n �������-������ � �������:");
    for (int i = 0; i < n; i++)
    {
        (((char* (*)(char*, char k[20])) A[i])) (e[i], t[i]);
    }

    printf("\n ������� ������ � �������:");
    for (int i = n; i < N; i++)
    {
        printf("\n %d ������:", i);
        for (int j = 0; j < 20; j++)
            printf("%c", *((char*)A[i] + j));
    }

    //������� map
    void (*F)(char*); // ��������� �� �������
    F = &ToLower;
    printf("\n\n������� � �������� ����� �������� map:");
    for (int i = n; i < N; i++)
    {
        printf("\n");
        for (int j = 0; j < 20; j++)
            map((char*)A[i] + j, *F);
    }
    //������� where
    F = &ToHigh;
    printf("\n\n������� � ��������� ����� �������� map:");
        for (int i = n; i < N; i++)
        {
            printf("\n");
            for (int j = 0; j < 20; j++)
                map((char*)A[i] + j, *F);
        }
     int (*L)(char* S); //��������� �� �������
     L = &Cif;
     printf("\n\n���� � ������ ���� ����� - ��������� �� �������� where:");
     for (int i = n; i < N; i++)
             where((char*)A[i], *L);

     free(funcs);
     free(a);
     free(A);

        return 0;
}

