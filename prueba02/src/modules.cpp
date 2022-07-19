#include "modules.h"
#include "utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int len = 3;

void diagonales();

void exec_func(int index)
{
    switch (index)
    {
    case 0:
        matriz5x5();
        break;
    case 1:
        diagonales();
        break;
    default:
        printw("Aun sin definir");
    }
}

void matriz5x5()
{
    int  elements[len][len];
    int  rowsArray[len];
    int  colsArray[len];
    int* repeatedArray = (int*)calloc(len * len, sizeof(int));
    int  i, j, counter = 0;
    int  sumRes, producRes;
    int  min, max;

    clear();
    echo();
    printw("\n\n\tFuncion 01\n\n");
    printw("Entrada: matriz 5x5\n");
    printw("\nSalida: \n\t1. Suma de las filas \n\t2. Producto de las columnas "
           "\n\t3. Valores repetidos en la matriz\n\n");

    printw("\n\nPulse cualquier tecla para continuar...");
    getch();

    clear();
    refresh();

    printw("Aqui apareceran los valores de la matriz\n");
    printMatrix(*elements, len);

    for (i = 0; i < len; ++i)
    {
        printRow(elements[i], elements[i] + len);
        for (j = 0; j < len; ++j)
        {
            if (hasRepeated(*elements, &elements[i][j], len))
            {
                if (!hasRepeated(repeatedArray, &elements[i][j], len))
                {
                    *(repeatedArray + counter) = elements[i][j];
                    counter++;
                }
            }
        }
    }

    printw("\nSuma de las filas\n\n\t");

    for (i = 0; i < len; ++i)
    {
        getRow(elements[i], rowsArray, len);
        sumRes = sumArr(rowsArray, rowsArray + len);
        printw("%d", sumRes);
        if (i < len - 1)
            printw(", ");
    }

    printw("\n\nProducto de las Columnas\n\n\t");

    for (i = 0; i < len; ++i)
    {
        getColumn(&elements[0][i], colsArray, len);
        producRes = multArr(colsArray, colsArray + len);
        if (i != len - 1)
            printw("%d, ", producRes);
        else
            printw("%d\n", producRes);
    }

    printw("\nNumeros repetidos\n\n\t");

    for (i = 0; i < len * len; ++i)
    {
        printw("%d", *(repeatedArray + i));
        if (*(repeatedArray + i + 1) == 0)
            break;
        else
            printw(", ");
    }

    printw("\n\nNumeros menores de las filas\n\n\t");
    for (i = 0; i < len; ++i)
    {
        getRow(elements[i], rowsArray, len);
        min = getMin(rowsArray, rowsArray + len);
        printw("%d", min);

        if (i < len - 1)
            printw(", ");
    }

    printw("\n\nNumeros mayores de las columnas\n\n\t");
    for (i = 0; i < len; ++i)
    {
        getColumn(&elements[0][i], colsArray, len);
        max = getMax(colsArray, colsArray + len);
        printw("%d", max);

        if (i < len - 1)
            printw(", ");
    }

    noecho();
}

void diagonales()
{
    int  elements[len][len];
    int  rowsArray[len];
    int  colsArray[len];
    int* repeatedArray = (int*)calloc(len * len, sizeof(int));
    int  i, j, counter = 0;
    int  sumRes, producRes;
    int  min, max;

    clear();
    echo();
    printw("\n\n\tFuncion 01\n\n");
    printw("Entrada: matriz 5x5\n");
    printw("\nSalida: \n\t"
           "1. Numeros en la diagonal principa \n\t"
           "2. Numeros en la diagonal secundaria\n\t"
           "3. Mayor entre los anteriores\n\t"
           "4. Numeros que se repiten en los anteriores\n\t"
           "5. Numeros debajo de la diagonal principal\n\t");

    printw("\n\nPulse cualquier tecla para continuar...");
    getch();

    clear();
    refresh();

    printw("Aqui apareceran los valores de la matriz\n");
    printMatrix(*elements, len);

    for (i = 0; i < len; ++i)
    {
        printRow(elements[i], elements[i] + len);
    }

    printw("\n\nNumeros en la diagonal principal\n\n\t");
    for (i = 0; i < len; ++i)
    {
        rowsArray[i] = elements[i][i];
    }
    printSeparated(rowsArray, rowsArray + len);

    printw("\n\nNumeros en la diagonal secundaria\n\n\t");
    for (i = 0; i < len; ++i)
    {
        colsArray[i] = elements[i][len - i - 1];
    }
    printSeparated(colsArray, colsArray + len);

    max = getMax(rowsArray, rowsArray + len);
    min = getMin(colsArray, colsArray + len);

    printw("\nMayor de la diagonal principal: %d", max);
    printw("\nMenor de la diagonal secundaria: %d", min);

    printw("\n\nNumeros que se repiten en la principal\n\n\t");

    for (i = 0; i < len; ++i)
    {
        if (hasRepeated(rowsArray, rowsArray + len, rowsArray[i]))
        {
            for (j = 0; j < counter; ++j)
            {
                if (!hasRepeated(repeatedArray, repeatedArray + counter,
                                 rowsArray[i]))
                {
                    repeatedArray[counter] = rowsArray[i];
                    counter++;
                }
            }
        }
    }

    printSeparated(repeatedArray, repeatedArray + len);
}
