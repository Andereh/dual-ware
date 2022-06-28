#include <stdio.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "modules.h"

// Aqui van todas las definiciones de funciones

bool hasAChar(char *strStart, char *strEnd)
{
	char *ptr = strStart;
	
	while (ptr <= strEnd && *ptr != '\n') {
		if (*ptr >= 65 && *ptr <= 90) return true;
		ptr++;
	}
	
	return false;
}

void sayHello()  // prueba
{
	printf("Hello\n");
}

void promedioNotas() // 01. Ronald
{
	int i, sumaTotal, nNotas; // nNotas: cantidad de notas a evaluar
	char str[10];
	
	printf("Notas a evaluar: ");
	scanf("%s", str);

	printf("%s\n", str);

	if (hasAChar(str, str + 10)) printf("Has a char\n");


	while (nNotas <= 1 || hasAChar(str, str + 10))
	{
		if (hasAChar(str, str + 10)) printf("Has a char\n");
		__fpurge(stdin);
		printf("\nIngrese al menos 2 notas. Intente de nuevo\n");
		printf("Notas a evaluar: ");
		scanf("%d", &nNotas);
	}
}
