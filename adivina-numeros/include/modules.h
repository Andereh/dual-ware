#define _MODULES_H

static int max        = 31;
static int nElementos = (max + 1) / 2;
static int nFilas     = 5;

void sayHello();
void rellenarFila(int* arr, int nFila);
void imprimirFila(int* arr);
bool hasRepeatedNum(int*, int*, int);
void imprimirSeparador(int);
