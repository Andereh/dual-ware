#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Alumno 
{
	char name[64];
	char ci[10];
	char year_of_birth[4]; // agno de nacimiento
	int id;
	struct Trimester {
		float notes[4];

	} trimesters[3];
};



void space_and_print(char str[], int len)
{
	str[strlen(str) - 1] = '\0'; // cambiamos el ultimo caracter por el nulo
								 // esto no afecta la variable original
	printf("%s", str);
	int spaces = len - strlen(str);

	while (spaces--) {
		printf(" ");
	}

	printf("| ");

}

void print_alumno(struct Alumno al)
{
	printf("\n #%d | ", al.id);
	space_and_print(al.name, 20);
	space_and_print(al.ci, 9);
	space_and_print(al.year_of_birth, 5);

}

int main(int argc, char *argv[])
{
	int n_alums = 10; // numero de alumnos maximos
	char line[120]; // aqui se guardan las lineas que se van leyendo

	struct Alumno alumnos[n_alums]; // arreglo de alumnos

	FILE* data_base = fopen("./pseudo_data_base.txt", "r"); 
	// abrimos el falsa base de datos

	for (int i = 0; i < n_alums; i++) {
		do {
			fgets(line, 120, data_base); 
		} while (strcmp(line, "\n") == 0);

			if (line[0] == '*') // si encuentra esto significa que estamos en el final del archivo
				return 0;

		strcpy(alumnos[i].name, 
				line); // se supone que si salio del bucle es porque la linea no estaba vacia


		// se copian porque la asignacion directa no es valida en C
		strcpy(alumnos[i].ci, 
				fgets(line, 120, data_base)); // ahora si escuentra un espacio nos jodemos
		strcpy(alumnos[i].year_of_birth, 
				fgets(line, 120, data_base));
		alumnos[i].id = i + 1;

		print_alumno(alumnos[i]);


		//printf(" Alumno %d:\n\n", i + 1);
		//printf("\tNombre: %s", alumnos[i].name);
		//printf("\tCedula: %s", alumnos[i].ci);
		//printf("\tAgnio:  %s\n\n", alumnos[i].year_of_birth);


	}

	return 0;
}

