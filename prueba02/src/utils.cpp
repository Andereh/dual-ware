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

bool wantToRepeat()
{
    char options[][32] = {"Continuar", "Salir"};
    int  nElements     = sizeof(options) / sizeof(options[0]);
    int  cursorPos     = 0;
    int  opt           = 0;
    int  i;
    int  sizeX, sizeY;

    getmaxyx(stdscr, sizeX, sizeY);
    WINDOW* selecWin = newwin(4, 19, sizeX - 5, sizeY - 20);

    do
    {
        wclear(selecWin);
        refresh();
        wprintw(selecWin, "\n");

        for (i = 0; i < nElements; i++)
        {
            if (i == cursorPos)
            {
                attron(A_BOLD);
                wprintw(selecWin, "  > ");
                attroff(A_BOLD);
                attron(COLOR_PAIR(01111111));
                wprintw(selecWin, "%s\n", options[i]);
                attroff(COLOR_PAIR(01111111));
            }
            else
            {
                wprintw(selecWin, "    ");
                wprintw(selecWin, "%s\n", options[i]);
            }
        }

        box(selecWin, '|', '-');

        touchwin(selecWin);
        wrefresh(selecWin);
        opt = getch();

        switch (opt)
        {
        case KEY_DOWN:
            cursorPos++;
            break;
        case KEY_UP:
            cursorPos--;
            break;
        case '\n':
            delwin(selecWin);
            return cursorPos != nElements - 1;
        }

        if (cursorPos < 0)
            cursorPos = nElements - 1;
        if (cursorPos >= nElements)
            cursorPos = 0;
    } while (true);
}
