#include "modules.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void sayHello() { printf("Hello\n"); }

void imprimirConRelleno(int n)
{
    int i;
    int spaces = 3;
    int numLen = std::to_string(n).length();

    for (i = 0; i < (spaces - numLen); ++i)
    {
        printf(" ");
    }
    printf("%d |", n);
}

void imprimirSeparador(int spaces)
{
    int i, j;
    for (i = 0; i < nElementos; ++i)
    {
        for (j = 0; j < spaces; ++j)
        {
            printf("-");
        }
    }
}

void imprimirFila(int* arr)
{
    int i;

    for (i = 0; i < (max + 1) / 2; ++i)
    {
        imprimirConRelleno(*(arr + i));
    }
}

void rellenarFila(int* arr, int nFila)
{
    int i;
    if (nFila == 1)
    {
        int num = 1;
        for (i = 0; num <= max; ++i)
        {
            *(arr + i) = num;
            num += 2;
        }
    }
    else
    {
        int firstElement = pow(2, nFila - 1);
        int num          = firstElement;
        int recent       = firstElement;
        int i;

        *(arr) = num;

        for (i = 1; num <= max; ++i)
        {
            if (i % firstElement == 0)
            {
                num    = recent + firstElement * 2;
                recent = num;
            }
            else
                num++;
            *(arr + i) = num;
        }
    }
}


bool hasRepeatedNum(int* ptr, int* end, int n)
{
    while (ptr < end)
    {
        if (*ptr == n)
            return true;
        ptr++;
    }

    return false;
}
