#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include <math.h>
#include "modules.h"

// Aqui van todas las definiciones de funciones

bool hasAChar(char *strStart, char *strEnd)
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

int validInt()
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

void sayHello()  // prueba
{
	printf("Hello\n");
}

void promedioNotas() // 01. Ronald
{
	int i, sumaTotal = 0, nNotas, puntaje, opt; // nNotas: cantidad de notas a evaluar
	float res; // resultado
	char str[10];
	
	printf("Modo: Promedio de notas\n\n");
	printf("Notas a evaluar: ");
	nNotas = validInt();

	while (nNotas <= 1) 
	{ // Si se introdujeron caracteres
		printf("\nIngrese al menos 2 notas. Intente de nuevo\n");
		printf("Notas a evaluar: ");
		nNotas = validInt();
	}
	
	printf("\n");

	for (i = 0; i < nNotas; ++i) 
	{
		printf("Nota %d/%d: ", i + 1, nNotas);
		puntaje = validInt();

		sumaTotal += puntaje;
	}
	
	res = sumaTotal/(float)nNotas;
	
	if (res <= 2.5f) printf("Quedo en transcision\n");
	else if (res < 3) printf("Perdio la materia\n");
	else printf("Paso la materia\n");
		
	printf("\nPromedio total: %f\n", res);
}

void ecuacionCuadratica()
{
	int a, b, c;
	float resPos, resNeg;

	printf("Modo: ecuacion cuadratica\n\n");
	printf("Valor de A: ");
	a = validInt();
	printf("Valor de B: ");
	b = validInt();
	printf("Valor de C: ");
	c = validInt();

	resPos = (-b) + sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));
	resNeg = (-b) - sqrt( fabs ( (pow(b, 2) - (4*a*c) ) ));

	resPos /= 2*a;
	resPos /= 2*a;

	printf("Resultado (+): %f\n", resPos);
	printf("Resultado (-): %f\n", resNeg);

}
