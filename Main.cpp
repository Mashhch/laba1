#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int ctest3();
int ctest2();
int ctest1();
char** funcs;
int Cif(char* S);
void where(char* Z, int (*F)(char*));
void map(char* Z, void (*F)(char*));
void ToHigh(char* c);
void ToLower(char* c);
char** fs();
char* sklei(char s1[10], char s2[10], char s3[20], char* s);
char* vvod(char s[10], int m, char* d);
char* f1(char* w, char konech[20]); // конкатенация
char* f2(char* s1, char s[20]);
char* f3(char* s1, char s[20]);
char* f4(char* s1, char s[20]);
char* f5(char* s1, char s[20]);
char* f6(char* s1, char s[20]);
char* f7(char* s1, char s[20]);
char* f8(char* s1, char s[20]);
char* f9(char* s1, char s[20]);

// массив указателей на функции
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
    int n, p;
    char* e[9];
    char t[9][20];
    char vv;
    int (*L)(char* S); //указатель на функцию
    L = &Cif;
    void (*F)(char*); // указатель на функцию
    F = &ToLower;
    // инициализация для передачи в функции
    for (int i = 0; i < 9; i++)
    {
        for(int j=0;j<2;j++)
            t[i][j] = '0';
        e[i] = t[i];
    }
    vv = '0';
    while (vv == '0' || vv == '1' || vv == '2' || vv == '3' || vv == '4')
    {
        rewind(stdin);
        printf("\n0 - Автоматический ввод;\n1 - ввод вручную;\n2 - СиТест функции конкатенации;\n3 - СиТест функции map;\n4 - СиТест функции where;\nВыход - любая другая клавиша;\n");
        vv = getchar();

        if (vv >= '0' && vv <= '9')
        {
            p = (vv - '0');
            if (p == 1 || p == 0)
            {
                if (p == 0)
                {
                    N = rand() % 20 + 10;
                    printf("Колличество элементов в массиве: %d", N);
                    n = (rand() * 7) % 10;
                    printf("\nКолличество функций в массиве(<10):%d", n);
                }
                if (p == 1)
                {
                    printf("введите колличество элементов в массиве:");
                    rewind(stdin);
                    scanf("%d", &N);
                    printf("введите колличество функций в массиве(<10):");
                    rewind(stdin);
                    scanf("%d", &n);
                }
                void** A = (void**)malloc(N * sizeof(void*)); // динамический массив указателей на функции и строки

                            //указатели на функции
                for (int i = 0; i < N; i++)
                    A[i] = fs()[i];


                //массив строк длины 20
                char* a = (char*)malloc((N - n) * 20 * sizeof(char));
                if (p == 0)
                {
                    for (int i = 0; i < N - n; i++)
                    {
                        for (int j = 0; j < 20; j++)
                        {
                            srand(j + i * 12 + (unsigned)time(NULL));
                            set_len = strlen(SET);
                            *(a + i * 20 + j) = SET[rand() % set_len];
                        }
                    }
                }
                if (p == 1)
                {
                    printf("Введите  строки из 20 символов(в случае переполнения учитываются первые 20 введенных символа)");
                    rewind(stdin);
                    for (int i = 0; i < N - n; i++)
                    {
                        printf("\n%d строка:", i + n);
                        for (int j = 0; j < 20; j++)
                            scanf("%c", (a + i * 20 + j));
                        rewind(stdin);
                    }
                }


                //указатели на строки
                for (int i = n; i < N; i++)
                    A[i] = a + (i - n) * 20;

                //Вывод на экран
                printf("\n функции-строки в массиве:");
                for (int i = 0; i < n; i++)
                {
                    (((char* (*)(char*, char k[20])) A[i])) (e[i], t[i]);
                }

                printf("\n Обычные строки в массиве:");
                for (int i = n; i < N; i++)
                {
                    printf("\n %d строка:", i);
                    for (int j = 0; j < 20; j++)
                        printf("%c", *((char*)A[i] + j));
                }

                //функция map
                F = &ToLower;
                printf("\n\nПеревод в строчные буквы функцией map:");
                for (int i = n; i < N; i++)
                {
                    printf("\n");
                    for (int j = 0; j < 20; j++)
                        map((char*)A[i] + j, *F);
                }
                //функция where
                F = &ToHigh;
                printf("\n\nПеревод в прописные буквы функцией map:");
                for (int i = n; i < N; i++)
                {
                    printf("\n");
                    for (int j = 0; j < 20; j++)
                        map((char*)A[i] + j, *F);
                }
                L = &Cif;
                printf("\n\nЕсли в строке есть цифры - исключаем их функцией where:");
                for (int i = n; i < N; i++)
                    where((char*)A[i], *L);

                free(funcs);
                free(a);
                free(A);
            }
        }

        if (vv != '1' && vv != '0' && vv != '2' && vv != '3' && vv != '4')
        {
            printf("Для выхода из программы нажмите enter");
            getchar();
        }

        if (vv >= '0' && vv <= '9')
        {
            p = (vv - '0');
            if (p == 2)
            {
                int uu;
                uu = ctest1();
                if (uu == 1)
                    printf("\nТест1 пройден");
                if (uu == 0)
                    printf("\nТест1 не пройден");
            }
            if (p == 3)
            {
                int uu;
                uu = ctest3();
                if (uu == 1)
                    printf("\nТест2 пройден");
                if (uu == 0)
                    printf("\nТест2 не пройден");
            }
            if (p == 4)
            {
                int uu;
                uu = ctest2();
                if (uu == 1)
                    printf("\nТест3 пройден");
                if (uu == 0)
                    printf("\nТест3 не пройден");
            }
        }
    }
    return 0;
}

