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
    int  len = 2;
    int  elements[len][len];
    int  rowsArray[len];
    int  colsArray[len];
    int  num;
    do
    {
        clear();
        echo();
        printw("\n\nFuncion 01\n");
        printw("Te vamos a dar un array de 5x5 que tendras que rellenar\n");

        for (i = 0; i < len; ++i)
        {
            for (j = 0; j < len; ++j)
            {

                printw("Valor [%d][%d]: ", i, j);
                num = validInt();

                while (num < 1 || num > 9)
                {
                    printw("\nDebe ser un numero entre 1 y 9\n");
                    printw("Valor [%d][%d]: ", i, j);
                    num = validInt();
                }

                elements[i][j] = num;
            }
            printw("\n");
        }

        for (i = 0; i < len; ++i)
        {
            rowsArray[i] = sumRows(&elements[0][0], len, i);
            colsArray[i] = sumCols(&elements[0][0], len, i);
            printw("%d ", rowsArray[i]);
        }

        getch();

    } while (running);
}
