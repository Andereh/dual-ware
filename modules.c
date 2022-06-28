#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "modules.h"

// Aqui van todas las definiciones de funciones

// Funciones recurrentes, tendremos que repetir cosas 34 veces
// asi que no cae mal unas funciones para evitar eso

bool hasAChar(char *strStart, char *strEnd) // Para validar que una 
											// cadena no tenga caracteres
{
	char *ptr = strStart;
	
	while (ptr <= strEnd && *ptr != '\0')
	{
		if (*ptr < 48 || *ptr > 57) return true;
		ptr++;
		if (*ptr == '\n') *ptr = '\0';
	}
	
	return false;
}

bool wantToRepeat() // Para repetir el bucle
{
	char opt[10];

	printf("\n\t1. Continuar\n");
	printf("\tOtro. Volver al menu\n");
	printf("\nOpcion: ");
	fgets(opt, 10, stdin);

	return opt[0] == '1';
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

// Fin de las funciones recurrentes

void promedioNotas() // 01. Ronald
{
	int i, sumaTotal = 0, nNotas, puntaje, opt; // nNotas: cantidad de notas a evaluar
	float res; // resultado
	char str[10];

	do 
	{
		system("clear");
		
		printf("Modo: Promedio de notas\n\n");
		printf("Notas a evaluar: "); nNotas = validInt();

		while (nNotas <= 1)
		{ 
			printf("\nIngrese al menos 2 notas. Intente de nuevo\n");
			printf("Notas a evaluar: ");
			nNotas = validInt();
		}
		
		printf("Ingrese las notas\n\n");

		for (i = 0; i < nNotas; ++i) 
		{
			printf("Nota #%d/%d: ", i + 1, nNotas);
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

void ecuacionCuadratica()
{
	int a, b, c;
	float resPos, resNeg;

	do 
	{

	system("clear");

	printf("Modo: ecuacion cuadratica\n\n");
	printf("Valor de A: "); a = validInt();
	printf("Valor de B: "); b = validInt();
	printf("Valor de C: "); c = validInt();

	resPos = (-b) + sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));
	resNeg = (-b) - sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));

	resPos /= 2*a;
	resPos /= 2*a;

	printf("\nResultado (+): %f\n", resPos);
	printf("Resultado (-): %f\n", resNeg);

	} while (wantToRepeat());

}
