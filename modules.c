#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "modules.h"

#define CLS system("clear")

int i;
// Aqui van todas las definiciones de funciones

// Funciones recurrentes, tendremos que repetir cosas 34 veces
// asi que no cae mal unas funciones para evitar eso

bool hasAChar(char *strStart, char *strEnd) // Para validar que una 
											// cadena no tenga caracteres
{
	char *ptr = strStart;
	if (*ptr == '-') ptr++;
	while (ptr <= strEnd && *ptr != '\0')
	{
		if ((*ptr < 48 || *ptr > 57)) return true;
		if (*(++ptr) == '\n') *ptr = '\0';
	}
	
	return false;
}
// Funcio
bool hasACharf(char *strStart, char *strEnd) // Para validar que una 
											// cadena no tenga caracteres
{
	char *ptr = strStart;
	if (*ptr == '-') ptr++;
	while (ptr <= strEnd && *ptr != '\0')
	{
		if (*ptr == '.') ptr++;
		if ((*ptr < 48 || *ptr > 57)) return true;
		if (*(++ptr) == '\n') *ptr = '\0';
	}
	
	return false;
}
bool wantToRepeat() // Para repetir el bucle
{
	int opt;

	printf("\n\n\t\tOPCIONES\n");
	printf("\n\t1. Continuar\n");
	printf("\tOtro. Volver al menu\n");
	printf("\nOpcion: ");
	opt = validInt();

	return opt == 1;
}

int validInt() // Te retorna un int. 
			   // La uso para no validar cada 
			   // que necesitamos ingresar algo
{
	char str[10];
	int num, i;

	fgets(str, 10, stdin);

	while (hasAChar(str, str + 10))
	{
		printf("Caracteres detectados. Intente de nuevo: ");
		fgets(str, 10, stdin);
	}

	return (int)strtol(str, NULL, 10);
}

float validFloat() // Te retorna un int. 
			   // La uso para no validar cada 
			   // que necesitamos ingresar algo
{
	char str[10];
	int num, i;

	fgets(str, 10, stdin);

	while (hasACharf(str, str + 10))
	{
		printf("Caracteres detectados. Intente de nuevo: ");
		fgets(str, 10, stdin);
	}

	return (float)strtod(str, NULL);
}

// Fin de las funciones recurrentes

void promedioNotas() // 01. Ronald
{
	int sumaTotal, nNotas, puntaje, opt; // nNotas: cantidad de notas a evaluar
	float res; // resultado
	char str[10];

	do 
	{
		CLS;
		
		sumaTotal = 0;
		printf("\n\t\tPROMEDIO DE NOTAS\n\n");
		printf("Cantidad de notas a evaluar: "); nNotas = validInt();

		while (nNotas <= 1)
		{ 
			printf("\nIngrese al menos 2 notas\n");
			printf("Notas a evaluar: "); nNotas = validInt();
		}
		
		printf("Ingrese los datos\n\n");

		for (i = 1; i <= nNotas; ++i) 
		{
			printf("\tNota #%d/%d: ", i, nNotas);
			puntaje = validInt();

			sumaTotal += puntaje;
		}
		
		res = sumaTotal/(float)nNotas;
		
		if (res <= 2.5f)  printf("Quedo en transcision\n");
		else if (res < 3) printf("Perdio la materia\n"); // Asi dice en el PDF
		else			  printf("\nPaso la materia\n");
			
		printf("\nPromedio total: %f\n", res);

	} while (wantToRepeat());

}

void ecuacionCuadratica() // 03. Ronald 
{
	int a, b, c;
	float resPos, resNeg;

	do 
	{

	CLS;
	printf("\n\t\tECUACION CUADRATICA\n\n");

	printf("Introduzca los valores\n\n");
	printf("\tValor de A: "); a = validInt();
	printf("\tValor de B: "); b = validInt();
	printf("\tValor de C: "); c = validInt();

	resPos = (-b) + sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));
	resNeg = (-b) - sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));

	resPos /= 2*a;
	resPos /= 2*a;

	printf("\nResultado (+): %f\n", resPos);
	printf("Resultado (-): %f\n", resNeg);

	} while (wantToRepeat());

}

void tresNumeros() // 05. Ronald
{
	int nums[3];
	int mayor = 0, menor = 0, nPares = 0, aux;
	int opt;
	float prom = 0; // Promedio
	
	do {
		CLS;
		prom = 0;
		
		printf("\n\tOPERACIONES CON TRES NUMEROS\n");

		printf("\nElija una opcion\n\n");

		printf("\t1. Calcular el promedio\n");
		printf("\t2. Encontrar el mayor\n");
		printf("\t3. Encontrar el menor\n");
		printf("\t4. Identificar cuantos pares e impares hay\n");
		printf("\n\tOtro. Volver al menu\n");

		printf("\nOpcion: ");
		opt = validInt();

		if (opt < 1 || opt > 4) break;

		CLS;

		switch (opt) {
			case 1:
				printf("\n\tCALCULAR EL PROMEDIO\n");
				printf("\nIngrese los valores\n\n");
				for (i = 1; i <= 3; ++i) {
					printf("\tValor #%d: ", i);
					prom += validInt();
				}

				prom /= 3;
				printf("\nEl promedio es: %f\n", prom);
				break;
			case 2:
				printf("\n\tENCONTRAR EL MAYOR\n");
				for (i = 1; i <= 3; ++i) {
					printf("\tValor #%d: ", i);
					aux = validInt();
					if (aux > mayor) mayor = aux;
				}

				printf("\nEl mayor es: %d\n", mayor);
				break;
			case 3:
				printf("\n\tENCONTRAR EL MENOR\n");
				for (i = 1; i <= 3; ++i) {
					printf("\tValor #%d: ", i);
					aux = validInt();
					if (aux < menor) menor = aux;
				}

				printf("\nEl menor es: %d\n", menor);
				break;
			case 4:
				printf("\n\tDETERMINAR CUANTOS PARES E IMPARES HAY\n");
				for (i = 1; i <= 3; ++i) {
					printf("\tValor #%d: ", i);
					aux = validInt();

					if (aux%2 == 0) nPares++;
				}

				printf("\nHay %d pares\n", nPares);
				printf("Hay %d impares\n", 3 - nPares);
		}

	} while (wantToRepeat());

}


void dosNumeros() // 07. Ronald
{
	int a, b;

	do 
	{
		CLS;
		printf("\n\tOPERACIONES CON DOS NUMEROS\n\n");

		printf("Ingresara dos enteros y le mostraremos su suma, \n   resta, "
				"producto y cociente\n");

		printf("\nIngrese los datos\n\n");
		printf("\tValor #1: "); a = validInt();
		printf("\tValor #2: "); b = validInt();

		printf("\n    Suma: %d + %d = %d\n", a, b, a + b);
		printf("   Resta: %d - %d = %d\n", a, b, a - b);
		printf("Producto: %d * %d = %d\n", a, b, a * b);
		printf("Cociente: %d / %d = %f\n", a, b, a / (float)b);

	} while (wantToRepeat());
}

void areaDeFiguras() // 09. Ronald
{
	float base, altura, baseMayor, baseMenor, area;
	int opt;

	do 
	{
		CLS;
		printf("\n\tCALCULAR EL AREA DE FIGURAS\n"
				"\t     GEOMETRICAS\n");

		printf("\n\nElija una de las siguientes opciones calcular\n");
		printf("\n\t1. Area de un rectangulo\n");
		printf("\t2. Area de un triangulo\n");
		printf("\t3. Area de un trapecio\n");
		printf("\n\tOtro. Salir\n\n");

		printf("Opcion: ");
		opt = validInt();

		if (opt < 1 || opt > 3) break;

		CLS;
		switch (opt) {
			case 1:
				printf("\n\t\"CALCULAR AREA DE UN RECTANGULO\"\n");
				printf("Ingrese los datos\n");
				printf("\n\tBase: "); base = validFloat();
				printf("\tAltura: "); altura = validFloat();

				area = base * altura;

				printf("\nArea: %f", area);
				break;

			case 2:
				printf("\n\t\"CALCULAR AREA DE UN TRIANGULO\"\n");
				printf("\n\tBase: "); base = validFloat();
				printf("\tAltura: "); altura = validFloat();

				area = (base * altura) / 2;

				printf("\nArea: %f", area);
				break;
			case 3:
				printf("\n\t\"CALCULAR AREA DE UN TRAPECIO\"\n");
				printf("\n\tBase menor: "); baseMenor = validFloat();
				printf("\tBase mayor: "); baseMayor = validFloat();
				printf("\tAltura: "); altura = validFloat();

				area = ((baseMenor + baseMayor) * altura) / 2;

				printf("\nArea: %f", area);
				break;
		}
	} while (wantToRepeat());
}

void sumaParesImpares()
{
	int sumPares, sumImpares, n;

	do 
	{
		sumPares = 0;
		sumImpares = 0;

		CLS;
		printf("\n\tSUMA DE PARES E IMPARES\n");

		printf("\nIngresara un entero n y le mostraremos la suma de\n    "
				"los numeros pares e impares inferiores a n\n");


		printf("\n\nIngrese n: "); n = validInt();

		while (n < 1) {
			printf("No admitimos numeros negativos. Intente de nuevo\n");
			printf("\n\nIngrese n: "); n = validInt();
		}

		for (i = 0; i < n; ++i) {
			if (i%2 == 0)   sumPares += i;
			else		  sumImpares += i;
		}

		printf("\n\tLa suma de los pares es: %d\n", sumPares);
		printf("\tLa suma de los impares es: %d\n", sumImpares);

	} while (wantToRepeat());
}

