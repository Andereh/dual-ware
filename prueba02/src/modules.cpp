#include "modules.h"
#include "utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void exec_func(int index)
{
    switch (index)
    {
    case 0:
        matriz5x5();
        break;
    default:
        printw("Aun sin definir");
    }
}

void matriz5x5()
{
    bool running = true;
    int  i, j;
    int  len = 3;
    int  elements[len][len];
    int  rowsArray[len];
    int  colsArray[len];
    int  num;
    clear();
    echo();
    printw("\n\n\tFuncion 01\n\n");
    printw("Entrada: matriz 5x5\n");
    printw("Salida: suma de las filas y columnas de la matriz\n\n");
    printw("Rellena la matriz\n\n");

    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < len; ++j)
        {

            printw("\tValor [%d][%d]: ", i, j);
            num = validInt();

            while (num < 1 || num > 9)
            {
                printw("\nDebe ser un numero entre 1 y 9\n");
                printw("\tValor [%d][%d]: ", i, j);
                num = validInt();
            }

            elements[i][j] = num;
        }
        printw("\n");
    }

    for (i = 0; i < len; ++i)
    {
        rowsArray[i] = sumRows(elements[0], len, i);
        colsArray[i] = sumCols(elements[0], len, i);
    }

    printw("\nSuma de las filas\n\n\t");

    for (i = 0; i < len; ++i)
    {
        if (i != len - 1)
            printw("%d, ", rowsArray[i]);
        else
            printw("%d\n", rowsArray[i]);
    }

    printw("\nSuma de las Columnas\n\n\t");

    for (i = 0; i < len; ++i)
    {
        if (i != len - 1)
            printw("%d, ", colsArray[i]);
        else
            printw("%d\n", colsArray[i]);
    }
}
