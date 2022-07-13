#include "modules.h"
#include <iostream>
#include <math.h>
#include <ncurses.h>

int main(int argc, char* argv[])
{
    int arr[nElementos][nFilas];
    int i;
    int selecc[nFilas];
    int cursorPos = 1;
    int opt;
    int resp = 0;

    for (i = 0; i < nFilas; i++)
    {
        selecc[i] = 0;
    }

    initscr();

    do
    {
        clear();
        printw("\n\n\n");
        for (i = 0; i < nFilas; ++i)
        {
            rellenarFila(arr[i], i + 1);

            if (i == cursorPos)
            {
                attron(A_BOLD);
                printw(" >");
                attroff(A_BOLD);
            }
            else
                printw("  ");

            if (selecc[i] == 1)
                printw(" X");
            else
                printw("  ");

            imprimirFila(arr[i]);

            // printw("\n");
            // imprimirSeparador(3 + 2);
            printw("\n");
        }

        if (opt == 'q')
        {
            for (i = 0; i < nFilas; ++i)
            {
                if (selecc[i] == 1)
                    resp += pow(2, i);
            }
            printw("\n\nEstas pensando en el %d", resp);
            resp = 0;
        }

        opt = getch();

        if (cursorPos < 0)
            cursorPos = nFilas - 1;
        if (cursorPos > nFilas - 1)
            cursorPos = 0;

        switch (opt)
        {
        case 'w':
            cursorPos--;
            break;
        case 's':
            cursorPos++;
            break;
        }

        refresh();
        if (opt == 'a' || opt == 'd')
        {
            if (selecc[cursorPos] == 1)
                selecc[cursorPos] = 0;
            else
                selecc[cursorPos] = 1;
        }

    } while (opt != '1');

    endwin();

    // for (i = 0; i < (max + 1) / 2; ++i)
    //{
    // printf("%d\n", *(*arr + i));
    //}
    return 0;
}
