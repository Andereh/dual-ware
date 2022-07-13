#include "modules.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void matriz5x5();

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
    int  opt;
    int  elements[5][5];
    int  i, j;
    char str[10];
    int  len = 3;
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
                attron(A_BOLD);
                getstr(str);
                attroff(A_BOLD);

                while (hasAChar(str, str + 10))
                {
                    printw("No puedes ingresar caracteres. Intenta de nuevo\n");
                    printw("Valor [%d][%d]: ", i, j);
                    attron(A_BOLD);
                    getstr(str);
                    attroff(A_BOLD);
                }

                elements[i][j] = strtol(str, NULL, 10);
            }
            printw("\n");
        }

    } while (running);
}
