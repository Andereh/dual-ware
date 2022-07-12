#include "modules.h"
#include <iostream>

#define green "\x1b[0;32;49m"
#define normal "\x1b[0m"
#define white "\x1b[0;39;47m"

int main(int argc, char* argv[])
{
    int arr[nElementos][nFilas];
    int i;
    int selecc[nFilas] = {1, 3, 2};
    int cursorPos;

    for (i = 0; i < nFilas; ++i)
    {

        rellenarFila(arr[i], i + 1);
        imprimirFila(arr[i]);

        if (hasRepeatedNum(selecc, selecc + 3, i))
            printf("%s X %s", green, normal);

        printf("\n");
        imprimirSeparador(3 + 2);
        printf("\n");
    }

    getc();

    // for (i = 0; i < (max + 1) / 2; ++i)
    //{
    // printf("%d\n", *(*arr + i));
    //}
    return 0;
}
