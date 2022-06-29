#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

int main(void)
{
	int opt;

	do 
	{
		system("clear");
		printf("\n\t\tMENU\n\n");
		printf("Elija una de las siguientes opciones: \n");
		printf("\n\t1. Promedio de notas");
		printf("\n\t3. Ecuacion cuadratica");
		printf("\n\t5. Operar con tres numeros");
		printf("\n\t7. Operar con dos numeros");
		printf("\n\t9. Area de figuras geometricas");
		printf("\n\n\tOtro. salir\n");

		do {
			printf("\nOpcion: ");
			opt = validInt(); 
		}
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
			case 7:
				dosNumeros();
				break;
			case 9:
				areaDeFiguras();
				break;
			default:
				printf("Aun no definimos esa funcion\n");
		}

	} while (opt <= 9);

	return 0;
}
