#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nSpaces;

int  getNumWidth(int n);
void printSpaced(int n);
void printMatrix(int* arr, int len);
void impar(int* matriz, int len);
void doblePar(int* matriz, int len);
void simplePar(int* matriz, int len);

int main(int argc, char* argv[]) // tratare de hacerlo todo en spanish
{
    int *matriz, len;
    printf("Creador de cuadrados magicos (Solo para pares por los momentos)\n");

    printf("\n\nDe que longitud prefieres el cuadrado?: ");
    scanf("%d", &len);

    nSpaces = 4;
    matriz  = (int*)calloc(len * len, sizeof(int));

    if (len % 2 == 0)
    {
        
        if (len % 4 == 0)
            doblePar(matriz, len);
        else
            simplePar(matriz, len);

        printMatrix(matriz, len);
    }
    else
    {
        impar(matriz, len);
        printMatrix(matriz, len);
    }

    return 0;
}

void impar(int* matriz, int len)
{

    int  center   = (len) / 2;
    int  maxIndex = len - 1;
    int  counter  = 1;
    int  y        = center + 1;
    int  x        = center;
    bool hasChanged;

    printf("Modo impar\n\n");

    while (counter <= len * len)
    {
        matriz[y * len + x] = counter;

        counter++;
        if (x == maxIndex && y == maxIndex)
        {
            y = 0;
            x--;
        }

        if (x + 1 > maxIndex)
            x = 0;
        else
            x++; // ahora hacia abajo

        if (y + 1 > maxIndex)
            y = 0;
        else
            y++;

        hasChanged = false;
        if (matriz[(y * len + x)] != 0)
        {
            y += 1;
            if (!hasChanged)
            {
                x--;
                hasChanged = true;
            }

            if (y > maxIndex)
                y = 0;
        }
    }
}

void simplePar(int* matriz, int n)
{
    int i, j;
    printf("Modo simple-par\n\n");
    // filling matrix with its count value
    // starting from 1;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            *(matriz + i * n + j) = (n*i) + j + 1;
     
    for ( i = 0; i < n/4; i++)
        for ( j = 0; j < n/4; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
     
    // Top Right corner of Matrix
    // (order (n/4)*(n/4))
    for ( i = 0; i < n/4; i++)
        for ( j = 3 * (n/4); j < n; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
     
    // Bottom Left corner of Matrix
    // (order (n/4)*(n/4))
    for ( i = 3 * n/4; i < n; i++)
        for ( j = 0; j < n/4; j++)
            *(matriz + i * n + j) = (n*n+1) - *(matriz + i * n + j);
     
    // Bottom Right corner of Matrix
    // (order (n/4)*(n/4))
    for ( i = 3 * n/4; i < n; i++)
        for ( j = 3 * n/4; j < n; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
     
    // Centre of Matrix (order (n/2)*(n/2))
    for ( i = n/4; i < 3 * n/4; i++)
        for ( j = n/4; j < 3 * n/4; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
 
 
}

void doblePar(int* matriz, int n)
{
    int i, j;
    printf("Modo par\n\n");
    for ( i = 0; i<n; i++)
    {
        for ( j = 0; j<n; j++)
            *(matriz + i * n + j) = (n*i) + j + 1;        
    }

    // change value of Array elements 
    // at fix location as per rule 
    // (n*n+1)-*(matriz + i * len + j)
    // Top Left corner of Matrix 
   // (order (n/4)*(n/4))
    for ( i = 0; i<n/4; i++)
    {
        for ( j = 0; j<n/4; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
    }

    // Top Right corner of Matrix 
    // (order (n/4)*(n/4))
    for ( i = 0; i< n/4; i++)
    {
        for ( j = 3* (n/4); j<n; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
    }

    // Bottom Left corner of Matrix 
    // (order (n/4)*(n/4))
    for ( i = 3* n/4; i<n; i++)
    {
        for ( j = 0; j<n/4; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
    }
 
    // Bottom Right corner of Matrix 
   // (order (n/4)*(n/4))
    for ( i = 3* n/4; i<n; i++)
    {
        for ( j = 3* n/4; j<n; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
    }
 
    // Centre of Matrix (order (n/2)*(n/2))
    for ( i = n/4; i<3* n/4; i++)
    {
        for ( j = n/4; j<3* n/4; j++)
            *(matriz + i * n + j) = (n*n + 1) - *(matriz + i * n + j);
    } 
}

int getNumWidth(int n)
{
    int numWidth = 0;

    while (n >= 1)
    {
        numWidth++;
        n /= 10;
    }
    return numWidth;
}

void printSpaced(int n)
{
    int i;
    for (i = 0; i < (nSpaces - getNumWidth(n)) + 1; ++i)
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

