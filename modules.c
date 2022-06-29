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

	return strtof(str, NULL);
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

void sumaParesImpares() // 11. Ronald
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

void sieteNumeros() // 12 + 1. Ronald
{
	int nums[7], nPares;

	do 
	{
		CLS;

		nPares = 0;

		printf("\n\tSIETE NUMEROS\n");

		printf("\nDigite siete numeros y le diremos cuantos pares hay\n\n");

		printf("Ingrese los datos\n\n");

		for (i = 0; i < 7; ++i) {
			printf("\tNumero #%d/7: ", i+1);
			nums[i] = validInt();

			while (nums[i] < 1) {
				printf("\n\tDebe ser mayor que cero\n");
				printf("\tNumero #%d/7: ", i+1);
				nums[i] = validInt();
			}

			if (nums[i]%2 == 2) nPares++;
		}
		
		printf("\nIngreso %d pares\n", nPares);
		printf("\nNumeros ingresados: ");
		printf("%d", nums[0]);
		for (i = 1; i < 7; ++i) {
			printf("-%d", nums[i]);	
		}

	} while (wantToRepeat());
}

void paresEntre20y40()
{
	do 
	{
		CLS;
		printf("\n\tVER LOS PARES ENTRE 20 Y 40\n");

		printf("\nLos pares entre 20 y 40 son: \n");
		printf("\n\t20");
		for (i = 22; i <= 40; i += 2) {
			printf("-%d", i);
		}

	} while (wantToRepeat());
}

void multiplosDe5()
{
	int n, suma;

	do 
	{
		suma = 0;
		CLS;
		printf("\n\tSUMAR LOS NUMEROS MULTIPLOS DE 5\n"
				"\t      MENORES QUE N\n");

		printf("\nIngrese n: "); n = validInt();

		while (n < 1) {
			printf("Debe ser un numero positivo\n");
			printf("\nIngrese n: "); n = validInt();
		}

		for (i = 5; i <= n; i += 5) {
			suma += i;
		}

		printf("\nLa suma de los muliplos de 5 menores que n es: %d", suma);

	} while (wantToRepeat()) ;
}

void hacerUnaFactura()
{
	float precio, iva = .16f, precioFinal;

	do 
	{
		CLS;
		printf("\n\tHACER UNA FACTURA\n");
		printf("\nIngrese el valor del producto a comprar: ");
		precio = validFloat();

		while (precio < 1)
		{
			printf("No puedes tener una factura negativa\n\n");
			printf("Ingrese el valor del producto a comprar: ");
			precio = validFloat();
		}

		printf("\n\tPrecio: %f\n", precio);
		printf("\t   Iva: %f\n", precio * iva);

		if (precio > 200000) 
		{
			printf("     Descuento: %f\n", precio * .05);
			precio *= .95;
		}
		precioFinal = precio * (1 + iva);

		printf("  Precio final: %f\n", precioFinal);

	} while (wantToRepeat());
}

void resistencias()
{
	float voltios, resist, sumResist, corriente;
	int nResist;

	do 
	{
		sumResist = 0;

		CLS;
		printf("\n\tCALCULAR LA CORRIENTE SEGUN N RESISTENCIAS\n");

		printf("\nIngrese los datos\n");

		printf("\n\tVoltaje : ");
		voltios = validFloat();
		printf("\nNumero de resistencias en serie: ");
		nResist = validInt();

		printf("\n");
		for (i = 0; i < nResist; ++i) {
			printf("\tValor de la resistencia %d/%d: ", i+1, nResist);
			resist = validFloat();

			sumResist += resist;
		}

		corriente = voltios / sumResist;

		printf("\nLa corriente que alimenta el circuito es de: %f "
			   "amperios\n",
			   corriente);
        } while (wantToRepeat());
}

void facturaDeLuz()
{
	float Kwh, factura;

	do 
	{
		CLS;

		printf("\n\tCALCULAR LA FACTURA DE LUZ\n");

		printf("\nIngrese los datos\n");

		printf("\n\tKwH consumidos: ");
		Kwh = validFloat();

		
		while (Kwh < 0) {
			printf("No puede tener una factura negativa\n");
			printf("\n\tKwH consumidos: ");
			Kwh = validFloat();
		}

		if (Kwh < 40) factura = Kwh * 180;
		else if (Kwh < 80) factura = Kwh * 185;
		else factura = Kwh * 189;

		printf("\nEl total a pagar es: %f\n", factura);
	} while (wantToRepeat());
}

void numerosInvertidos() // 25. Ronald
{
	do 
	{
		CLS;
		printf("\n\tNUMEROS INVERTIDOS\n");
		printf("\n\nLos numeros del 30 al 1 son: ");
		printf("\n\n\t30");
		for (i = 29; i > 0; --i) {
			if (i%10 == 0) printf("\n\t");
			else printf("-");
			if (i < 10) printf("0");
			printf("%d", i);
		}
	} while (wantToRepeat());
}

void invertirCapital()
{
	float capital;
	do 
	{
		CLS;
		printf("\n\tCALCULAR UNA INVERSION\n");
		printf("\nLuego de una ganacia del %s mensual calcular el "
			   "beneficio luego de 12 meses\n", "2%");

		printf("\n\tIngrese el capital: ");
		capital = validFloat();

		while (capital < 0)
		{
			printf("No puedes tener un capital negativo\n");
			printf("\n\tIngrese el capital: ");
			capital = validFloat();
		}

		for (i = 0; i < 12; ++i) {
			capital *= 1.02;
		}

		printf("\nObtendra %f al final de la inversion\n", capital);
	} while (wantToRepeat());
	
}

void pulsaciones()
{
	int edad;
	float pulsaciones;

	do 
	{
		CLS;
		printf("\n\tCALCULAR LAS PULSASIONES DE UNA PERSONA\n");
		printf("\nCalcular el numero de pulsaciones de una persona por "
			   "cada 10sg de ejercicio\n");

		printf("\nIngrese su edad: ");
		edad = validInt();

		while (edad < 1) {
			printf("No puedes tener una edad = 0\n");
			printf("\nIngrese su edad: ");
			edad = validInt();
		}

		pulsaciones = (220 - edad) / 10.0;

		printf("Deberia tener %f pulsaciones por minuto\n", pulsaciones);

	} while (wantToRepeat());
}

void sumaImpares()
{
	int suma, m;

	do 
	{
		CLS;


		printf("\n\tSUMA DE NUMEROS IMPARES MENORES QUE M\n");
		printf("\nIngrese el valor de m: ");
		m = validInt();

		while (m < 1) 
		{
			printf("Debe ser un valor mayor que 0");
			printf("\nIngrese el valor de m: ");
			m = validInt();
		}

		suma = 0;
		for (i = 1; i <= m; i += 2) {
			if (i%10 == 1) printf("\n\t");
			else printf("-");;
			if (i < 10) printf("0");
			printf("%d", i);
			suma += i;
		}


		printf("\n\nLa suma es: %d\n", suma);
	} while (wantToRepeat());
}
