#include "utils.h"
#include <ncurses.h>
#include <stdlib.h>

bool hasAChar(char* strStart, char* strEnd) // Para validar que una
                                            // cadena no tenga caracteres
{
    char* ptr = strStart;
    if (*ptr == '-')
        ptr++;
    while (ptr <= strEnd && *ptr != '\0')
    {
        if ((*ptr < 48 || *ptr > 57))
            return true;
        if (*(++ptr) == '\n')
            *ptr = '\0';
    }

    return false;
}
int validInt() // Te retorna un int.
               // La uso para no validar cada
               // que necesitamos ingresar algo
{
    char str[10];
    int  num, i;

    getstr(str);

    while (hasAChar(str, str + 10))
    {
        printw("No puede usar caracteres. Intente de nuevo: ");
        getstr(str);
    }

    return (int)strtol(str, NULL, 10);
}

int sumRows(int* arr, int len, int colPos)
{
    int sum = 0;
    int i;
    for (i = 0; i < len; ++i)
    {
        sum += *((arr + colPos * len) + i);
    }

    return sum;
}

int sumCols(int* arr, int len, int rowPos)
{
    int sum = 0;
    int i;
    for (i = 0; i < len; ++i)
    {
        sum += *((arr + i * len) + rowPos);
    }

    return sum;
}
