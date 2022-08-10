#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void printSpaced(int n)
{
    int i;
    int nSpaces = 5 - to_string(n).length();

    for (i = 0; i < nSpaces; ++i)
    {
        printf(" ");
    }

    printf("%d", n);
}

void printMatrix(int* arr, int len)
{
    int i, j;
    int suma;
    for (i = 0; i < len; ++i)
    {
        suma = 0;
        for (j = 0; j < len; ++j)
        {
            if (*(arr + (i * len) + j) == 0)
            {
                *(arr + (i * len) + j) = (len * len) - (i * len + j);
            }
            suma += *(arr + (i * len) + j);
            printSpaced(*(arr + i * len + j));
        }
        printf(" = %d\n", suma);
    }
}

int main(int argc, char* argv[]) // tratare de hacerlo todo en spanish
{
    int  len, i, j;
    int* matriz;
    printf("Creador de cuadrados magicos (Solo para pares por los momentos)\n");

    printf("\n\nDe que longitud prefieres el cuadrado?: ");
    scanf("%d", &len);
    matriz = (int*)calloc(len * len, sizeof(int));

    if (len % 2 == 0)
    {
        printf("Modo par\n\n");
        for (i = 0; i < len; ++i)
        {
            for (j = 0; j < len; ++j)
            {
                if (i == j || j == (len - i - 1))
                {
                    *(matriz + (i * len) + j) = i * len + j + 1;
                }
            }
        }

        printMatrix(matriz, len);
    }
    else
    {
        int center   = (len) / 2;
        int maxIndex = len - 1;
        int counter  = 1;
        int y        = center;
        int x        = center;

        printf("Modo impar\n\n");
        matriz[y * len + x] = len * len;
        y++;
        x--;

        while (counter < len)
        {
            matriz[y * len + x] = counter;
            counter++;
            y += 2;
            if (x < 0)
                x = maxIndex;
            else
                x--; // ahora hacia abajo
            if (y >= maxIndex)
                y = 0;

            printf("%d --- %d\n", x, y);
        }

        printMatrix(matriz, len);
    }

    return 0;
}
