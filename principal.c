#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

int main(void)
{
	int opt;
		printf("Bienvenido\n\n");

	do 
	{
		system("clear");
		printf("\n\t\tMENU\n\n");
		printf("Elija una de las siguientes opciones: \n");
		printf("\n\t1. Promedio de notas");
		printf("\n\t3. Ecuacion cuadratica");
		printf("\n\t5. Operar con tres numeros");
		printf("\n\n\tOtro. salir\n");

		printf("\nOpcion: ");
		do opt = validInt(); 
		while (opt < 1);

		switch (opt) {
			case 1:
				promedioNotas();
				break;
			case 3:
				ecuacionCuadratica();
				break;
			case 5:
				tresNumeros();
				break;
		}

	} while (opt <= 5);

	return 0;
}
