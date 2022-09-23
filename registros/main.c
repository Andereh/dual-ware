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

int actual_alumns_number = 0;
struct Alumno alumnos[10]; // arreglo de alumnos


void space_and_print(char str[], int len)
{
	str[strlen(str) - 1] = '\0'; // cambiamos el ultimo caracter por el nulo
								 // esto no afecta la variable original
	printf("%s", str);
	int spaces = len - strlen(str);

	while (spaces--) {
		printf(" ");
	}


}

void print_alumno(struct Alumno al)
{
	printf("\n #%d | ", al.id);
	space_and_print(al.name, 20); printf("| ");
	space_and_print(al.ci, 9); printf("| ");
	space_and_print(al.year_of_birth, 5);

}

void search_by_ci()
{
	char cedula[10];
	printf("\n Ingrese la cedula a buscar: ");
	fgets(cedula, 10, stdin);


	for (int i = 0; i < actual_alumns_number; ++i) 
	{
		if (strcmp(alumnos[i].ci, cedula) == 0)
		{
			print_alumno(alumnos[i]);
			break;
		}
	}
	printf("\n\nNo encontrado\n");
}


void search_by_name()
{
	char name[64];
	char opcion[10];
	do {

		printf("\n Ingrese el nombre a buscar: ");
		fgets(name, 64, stdin);

		name[strlen(name) - 1] = '\0';

		for (int i = 0; i < actual_alumns_number; ++i) 
		{
			if (strcmp(alumnos[i].name, name) == 0)
			{
				print_alumno(alumnos[i]);
				break;
			}
		}

		printf("Busqueda: '%s'\n", name);
		printf("Alunmo nose '%s'\n", alumnos[1].name);

		printf("Seguir buscando? (Si == s): ");
		fgets(opcion, 10, stdin);
	} while (opcion[0] == 's');

	printf("\n\nNo encontrado\n");
}


int main(int argc, char *argv[])
{
	int max_alums = 10; // numero de alumnos maximos
	char line[128]; // aqui se guardan las lineas que se van leyendo
	char opcion[32];

	FILE* data_base = fopen("./pseudo_data_base.txt", "r"); 
	// abrimos el falsa base de datos

	for (int i = 0; i < max_alums; i++) {
		do {
			fgets(line, 120, data_base); 
		} while (strcmp(line, "\n") == 0);

		if (line[0] == '*') // si encuentra esto significa que estamos en el final del archivo
			break;

		strcpy(alumnos[i].name, 
				line); // se supone que si salio del bucle es porque la linea no estaba vacia


		// se copian porque la asignacion directa no es valida en C
		strcpy(alumnos[i].ci, 
				fgets(line, 128, data_base)); // ahora si escuentra un espacio nos jodemos
		strcpy(alumnos[i].year_of_birth, 
				fgets(line, 128, data_base));
		alumnos[i].id = i + 1;

		alumnos[i].name[strcspn(alumnos[i].name, "\n")] = '\0';
		alumnos[i].ci[strcspn(alumnos[i].ci, "\n")] = '\0';
		alumnos[i].year_of_birth[strcspn(alumnos[i].year_of_birth, "\n")] = '\0';

		actual_alumns_number++;

		//printf(" Alumno %d:\n\n", i + 1);
		//printf("\tNombre: %s", alumnos[i].name);
		//printf("\tCedula: %s", alumnos[i].ci);
		//printf("\tAgnio:  %s\n\n", alumnos[i].year_of_birth);


	}

	do {

		system("clear");
		for (int i = 0; i < actual_alumns_number; ++i) 
			print_alumno(alumnos[i]);

		printf("\n\n\tBuscar por cedula  -> c");
		printf("\n\tBuscar por nombre  -> n");
		printf("\n\tSalir -> s");

		printf("\n\n Opcion: ");
		fgets(opcion, 10, stdin);

		switch (opcion[0]) {
			case 'c':
				search_by_ci();
				break;
			case 'n':
				search_by_name();
		}

	} while (opcion[0] != 's');

	printf("Gracias por visitar\n");
	return 0;
}

