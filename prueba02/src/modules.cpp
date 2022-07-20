#include "modules.h"
#include "utils.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int len = 4;

void diagonales();
void ejer5();
void ejer2();

void exec_func(int index)
{
    switch (index)
    {
    case 0:
        matriz5x5();
        break;
    case 1:
        ejer2();
        break;
    case 2:
        diagonales();
        break;
    case 3:
        ejer5();
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
            if (hasRepeated(*elements + i, elements[i][j], len))
            {
                if (!hasRepeated(repeatedArray, elements[i][j], len))
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

void ejer2()
{
    int elements[len][len];
    int tempRow[len];
    int rowsArray[len];
    int rowsNoRepeat[len];

    int tempCol[len];
    int colsArray[len];
    int colsNoRepeat[len];
    int i, j, min, max, lenRows, lenCols;
    // pre
    for (i = 0; i < len; ++i)
    {
        colsArray[i] = 1; // para el producto
        rowsArray[i] = 0; // para la suma
    }

    clear();
    echo();
    printw("\n\n\tFuncion 02\n");
    printw("\nEntrada:\n\tmatriz 5x5\n");
    printw("\nSalida:\n\t"
           "1. Suma de los numeros pares de cada fila\n\t"
           "2. Producto de los impares de cada columna\n\t"
           "3. Numero mayor de las filas y menor de las columnas\n\t"
           "4. Numeros no repetidos en las filas y columasn\n\t"
           "5. Suma, resta y producto de los numeros de cada vector\n\t");

    printw("\n\nPulse cualquier tecla para continuar...");
    getch();

    clear();
    refresh();

    printw("Aqui apareceran los valores de la matriz\n");
    printMatrix(*elements, len);

    // Re imprimimos la matriz
    for (i = 0; i < len; ++i)
    {
        printRow(elements[i], elements[i] + len);
    }

    // computo de resultados
    for (i = 0; i < len; ++i)
    {
        getRow(*(elements + i), tempRow, len);
        getColumn(*elements + i, tempCol, len);
        for (j = 0; j < len; ++j)
        {
            if (tempRow[j] % 2 == 0)
                rowsArray[i] += tempRow[j];

            if (tempCol[j] % 2 == 1)
                colsArray[i] *= tempCol[j];
        }
    }

    printw("\nSuma de los numeros pares de cada fila\n\n\t");
    printSeparated(rowsArray, rowsArray + len);
    printw("\n\nProducto de los numeros impares de cada columna\n\n\t");
    printSeparated(colsArray, colsArray + len);

    max = getMax(rowsArray, rowsArray + len);
    min = getMin(colsArray, colsArray + len);

    printw("\n\n    El mayor del vector fila: %d\n"
           "El menor del vector columna: %d",
           max, min);

    printw("\n\nNumeros no repetidos en el vector fila\n\n\t");
    getNoRepeatedNums(rowsArray, rowsNoRepeat, &lenRows, len);
    printSeparated(rowsNoRepeat, rowsNoRepeat + lenRows);

    printw("\n\nNumeros no repetidos en el vector columna\n\n\t");
    getNoRepeatedNums(colsArray, colsNoRepeat, &lenCols, len);
    printSeparated(colsNoRepeat, colsNoRepeat + lenCols);

    printw("\nSuma, resta y producto de los vectores fila y columna\n\n");
    for (i = 0; i < len; ++i)
    {
        printw("\t");
        printSpaced(colsArray[i]);
        printw(" + ");
        printSpaced(rowsArray[i]);
        printw(" = ");
        printSpaced(colsArray[i] + rowsArray[i]);
        printw("  |  ");

        printSpaced(colsArray[i]);
        printw(" - ");
        printSpaced(rowsArray[i]);
        printw(" = ");
        printSpaced(colsArray[i] - rowsArray[i]);
        printw("  |  ");

        printSpaced(colsArray[i]);
        printw(" * ");
        printSpaced(rowsArray[i]);
        printw(" = ");
        printSpaced(colsArray[i] * rowsArray[i]);
        printw("\n");
    }
}

void diagonales()
{
    int  elements[len][len];
    int  rowsArray[len];
    int  colsArray[len];
    int* repeatedArray = (int*)calloc(len * len, sizeof(int));
    int  i, counter = 0;
    int  min, max;

    clear();
    echo();
    printw("\n\n\tFuncion 03\n\n");
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

    printw("\n\nMayor de la diagonal principal: %d", max);
    printw("\nMenor de la diagonal secundaria: %d", min);

    printw("\n\nNumeros que se repiten en la principal\n\n\t");

    for (i = 0; i < len; ++i)
    {
        if (hasRepeated(rowsArray, *(rowsArray + i), len))
        {
            if (!appearInArr(repeatedArray, *(rowsArray + i), counter + 1))
            {
                repeatedArray[counter] = rowsArray[i];
                counter++;
            }
        }
    }
    if (counter == 0)
        printw("No se repiten numeros\n");

    printSeparated(repeatedArray, repeatedArray + counter);
    counter = 0;
    printw("\n\nNumeros que se repiten en la secundaria\n\n\t");

    for (i = 0; i < len; ++i)
    {
        if (hasRepeated(colsArray, *(colsArray + i), len))
        {
            if (!appearInArr(repeatedArray, *(colsArray + i), counter + 1))
            {
                repeatedArray[counter] = colsArray[i];
                counter++;
            }
        }
    }

    if (counter == 0)
        printw("\tNo se repiten numeros\n");
    printSeparated(repeatedArray, repeatedArray + counter);

    printw("\n\nNumeros por debajo de la diagonal principal\n\n");

    for (i = 1; i < len; ++i)
    {
        printw("\t");
        printRow(elements[i], elements[i] + i);
    }
}

void ejer5()
{
    int elements[len][len];
    int rowsArray[len];
    int colsArray[len];
    int i;
    int sumRes;

    clear();
    echo();
    printw("\n\n\tFuncion 05\n\n");
    printw("Entrada: matriz 5x5\n");
    printw("\nSalida: \n\t"
           "1. Numeros de las filas por su valor de la principal\n\t"
           "2. Numeros de las columnas por su valor de la secundaria\n\t"
           "3. Numeros debajo de la diagonal principal\n\t");

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

    printw("\nSuma de las filas multiplicadas por su valor de la diagonal "
           "principal\n\n\t");
    for (i = 0; i < len; ++i)
    {
        getRow(elements[i], rowsArray, len);
        sumRes = sumArr(rowsArray, rowsArray + len);
        sumRes *= elements[i][i];

        printw("%d", sumRes);

        if (i < len - 1)
            printw(", ");
    }
    printw("\n\nProducto de las columnas sumadas por su valor de la "
           "diagonal secundaria\n\n\t");
    for (i = 0; i < len; ++i)
    {
        getColumn(elements[0] + i, colsArray, len);
        sumRes = multArr(colsArray, colsArray + len);
        sumRes += elements[i][len - i - 1];

        printw("%d", sumRes);

        if (i < len - 1)
            printw(", ");
    }

    printw("\n\nNumeros por arriba de la diagonal secundaria\n\n");
    for (i = 0; i < len - 1; ++i)
    {
        printw("\t");
        printRow(elements[i], elements[i] + (len - i - 1));
    }
}
