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

int producCols(int* arr, int len, int rowPos)
{
    int produc = 1;
    int i;
    for (i = 0; i < len; ++i)
    {
        produc *= *((arr + i * len) + rowPos);
    }

    return produc;
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

void printRow(int* start, int* end)
{
    int* ptr = start;

    while (ptr < end)
    {
        printw(" %d", *ptr);
        if (ptr < end - 1)
            printw(" |");
        ptr++;
    }
    printw(" |\n");
}

void printMatrix(int* arr, int len)
{
    int i, j, a;
    int num = 1;
    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < len; ++j)
        {
            do
            {

                for (a = 0; a < i; ++a)
                {
                    printRow(arr + a * len, arr + a * len + len);
                }
                if (j > 0)
                    printRow(arr + a * len, arr + a * len + j);

                printw("\n");
                if (num < 1 || num > 9)
                    printw("Debe ser un numero entre 1 y 9");

                printw("\n\tValor [%d][%d]: ", i, j);
                num = validInt();

                clear();
                refresh();
            } while (num < 1 || num > 9);
            *(arr + i * len + j) = num;
        }
    }
}

bool hasRepeated(int* arr, int* find, int len)
{
    int i, j;

    for (i = 0; i < len; ++i)
    {
        for (j = 0; j < len; ++j)
        {
            if (*(arr + i * len + j) == *find && (arr + i * len + j) != find)
                return true;
        }
    }

    return false;
}

void getRow(int* arr, int* finalArray, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        *(finalArray + i) = *(arr + i);
    }
}

void getColumn(int* arr, int* finalArray, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        *(finalArray + i) = *(arr + i * len);
    }
}

int sumArr(int* arr, int* end)
{
    int* i;
    int  sum = 0;
    for (i = arr; i < end; ++i)
    {
        sum += *i;
    }
    return sum;
}

int multArr(int* arr, int* end)
{
    int* i;
    int  res = 1;
    for (i = arr; i < end; ++i)
    {
        res *= *i;
    }
    return res;
}

int getMax(int* arr, int* end)
{
    int  max = 0;
    int* i;

    for (i = arr; i < end; ++i)
    {
        if (*i > max)
            max = *i;
    }

    return max;
}

int getMin(int* arr, int* end)
{
    int  min = *arr;
    int* i;

    for (i = arr; i < end; ++i)
    {
        if (*i < min)
            min = *i;
    }

    return min;
}

void printSeparated(int* arr, int* end)
{
    int* i;
    for (i = arr; i < end; ++i)
    {
        printw("%d", *i);
        if (i < end - 1)
            printw(", ");
    }
}
