#include "modules.h"
#include <ncurses.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int  cursorPos = 1;
    int  i;
    int  opt;
    bool running       = true;
    char options[][32] = {"Matriz de 5x5", "Jairo", "Decir hola a rome",
                          "Salir"};
    int  nElements     = sizeof(options) / sizeof(options[0]);

    initscr();
    keypad(stdscr, true);
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    noecho();
    do
    {
        clear();
        printw("\n\n\n");
        for (i = 0; i < nElements; i++)
        {
            if (i == nElements - 1)
                printw("\n");
            if (i == cursorPos)
            {
                attron(A_BOLD);
                printw(" > ");
                attroff(A_BOLD);
                attron(COLOR_PAIR(01111111));
                printw("   %s\n", options[i]);
                attroff(COLOR_PAIR(01111111));
            }
            else
            {
                printw("   ");
                printw("   %s\n", options[i]);
            }
        }
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
            if (cursorPos == nElements - 1)
                running = false;
            else
                exec_func(cursorPos);

            break;
        }

        if (cursorPos < 0)
            cursorPos = nElements - 1;
        if (cursorPos >= nElements)
            cursorPos = 0;

    } while (running);
    endwin();

    // for (i = 0; i < (sizeof(options)/sizeof(options[0])); ++i) {
    // printf("%s\n", options[i]);
    //}
    return 0;
}
