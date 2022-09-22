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
	str[strlen(str) - 1] = '\0';
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
	int n_alums = 10;
	char line[120];
	struct Alumno alumnos[n_alums];

	FILE* data_base = fopen("./pseudo_data_base.txt", "r");

	for (int i = 0; i < n_alums; i++) {
		do {
			strcpy(alumnos[i].name, 
					fgets(line, 120, data_base));

		} while (strcmp(line, "\n") == 0);
			if (line[0] == '*')
				return 0;

		strcpy(alumnos[i].ci, 
				fgets(line, 120, data_base));
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

