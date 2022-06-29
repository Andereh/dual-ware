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
		printf("\n\t11. Suma de pares e impares");
		printf("\n\t13. Siete numeros");
		printf("\n\t15. Pares entre 20 y 40");
		printf("\n\t17. Mostrar la suma de los multiplos de 5");
		printf("\n\t19. Hacer una factura");
		printf("\n\t21. Medir corriente");
		printf("\n\t23. Hacer factura de luz");
		printf("\n\t25. Numeros decrecientes desde el 30");
		printf("\n\t27. Hacer una inversion");
		printf("\n\t29. Medir pulsaciones");
		printf("\n\t31. Suma de impares menores que m");

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
			case 11:
				sumaParesImpares();
				break;
			case 13:
				sieteNumeros();
				break;
			case 15:
				paresEntre20y40();
				break;
			case 17:
				multiplosDe5();
				break;
			case 19:
				hacerUnaFactura();
				break;
			case 21:
				resistencias();
				break;
			case 23:
				facturaDeLuz();
				break;
			case 25:
				numerosInvertidos();
				break;
			case 27:
				invertirCapital();
				break;
			case 29:
				pulsaciones();
				break;
			case 31:
				sumaImpares();
				break;
		}

	} while ( opt >= 1 && opt <= 32 );

	return 0;
}
