#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



struct Alumno 
{
	char name[64];
	char ci[10];
	char year_of_birth[4]; // agno de nacimiento
	int id;
	char sex[2];
	struct Trimester {
		float notes[4];

	} trimesters[3];
};

int actual_alumns_number = 0,posFinal,idExtend[10];
struct Alumno alumnos[10]; // arreglo de alumnos


void space_and_print(char str[], int len)
{
	// str[strlen(str) - 1] = '\0'; // cambiamos el ultimo caracter por el nulo
								 // esto no afecta la variable original
	printf("%s", str);
	int spaces = len - strlen(str);

	while (spaces-- > 0) {
		printf(" ");
	}

}

void print_alumno(struct Alumno al)
{
	printf("\n #%d | ", al.id);
	space_and_print(al.name, 20); printf("| ");
	space_and_print(al.ci, 9); printf("| ");
	space_and_print(al.year_of_birth, 5);
	space_and_print(al.sex, 3);

}

//Es para mostrar las notas
void infoExtend()
{	
	char opcion[10];
	int ID;
	printf("\n\n Desea ver mas informacion sobre uno de los alumnos? (Si == s): ");
	fgets(opcion, 10, stdin);

	if (opcion[0] == 's')
	{
		printf("\n Elija el ID correspondiente al alumno.\n"
			" ( El ID es el numero a la izquierda del alumno )\n\n");
		

		do{
			printf(" Ingresar ID: "); scanf("%d",&ID);

			//idExtend almacena los ID de las personas que aparezcan en la busqueda
			if(ID < idExtend[0] || ID > idExtend[posFinal])
			printf("\n El ID ingresado no corresponde a ningun alumno en la busqueda\n\n");

		}while(ID < idExtend[0] || ID > idExtend[posFinal]);

		system("clear");

		printf("\n\t Informacion detalla \n\n");
		print_alumno(alumnos[ID-1]);

		printf("\n\n Notas: \n\n");

		//aun faltaria mostrar las notas
		printf("\tTrimetre 1\tTrimestre 2\tTrimestre 3\n\n");

		system("pause");
	}
}

void search(char mode)
{
	char user_request[64];
	char to_search[64];
	char name_substr[64];
	char opcion[10];
	char phase[10] = "";
	int pos = 0;
	bool found_at_leat_one_al;

	if (mode == 'n')
		strcpy(phase, "el nombre");
	else if (mode == 'c')
		strcpy(phase, "la cedula");


	do {
		found_at_leat_one_al = false;

		printf("\n Ingrese %s a buscar: ", phase);
		fgets(user_request, 64, stdin);
		user_request[strcspn(user_request, "\n")] = '\0';
		// strcspn regresa el indice del caracter que se pasa por parametro


		system("clear");
		printf("\n Busqueda: '%s'\n", user_request);

		for (int i = 0; i < actual_alumns_number; ++i) 
		{
			if (mode == 'n')
				strcpy(to_search, alumnos[i].name);
			else if (mode == 'c')
				strcpy(to_search, alumnos[i].ci);

			// extraemos cuantos caracteres sea la longitud de la busqueda
			// y los asignamos a 'name_substr'
			strncpy(name_substr, to_search, strlen(user_request));

			// strcasecmp no toma en cuenta las mayusculas
			if (strcasecmp(name_substr, user_request) == 0)
			{
				print_alumno(alumnos[i]);
				found_at_leat_one_al = true;

				// Guardamos los id de los alumnos encontrados 
			    // para luego usarlos
				idExtend[pos] = alumnos[i].id;
				posFinal = pos;//Es para saber cuantos id se guardaron
				pos++;
			}
		}


		if (!found_at_leat_one_al) 
			printf(" No se encontro nada con esos valores\n");
		else
			infoExtend();

		printf("\n Seguir buscando? (Si == s): ");
		fgets(opcion, 10, stdin);
	} while (opcion[0] == 's');

}

//lo comento pq es solo un boceto
/*void guardarNotas(struct Alumno al) 
{

	char text[100];


	printf("\n Notas de: %s", al.name);

	for (int i = 0; i < 3; i++)
	{
		printf("\n\n\t Trimeste %d\n\n",i+1);
		for (int j = 0; j < 4; j++)
		{
			printf("\n Evaluacion %d: ",j+1);
			scanf("%f",&al.trimesters[i].notes[j]);
		}
	}
}*/

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
		strcpy(alumnos[i].sex, 
				fgets(line, 128, data_base));
		alumnos[i].id = i + 1;


		// donde encuentre un salto de linea lo elimina
		alumnos[i].name[strcspn(alumnos[i].name, "\n")] = '\0';
		alumnos[i].ci[strcspn(alumnos[i].ci, "\n")] = '\0';
		alumnos[i].year_of_birth[strcspn(alumnos[i].year_of_birth, "\n")] = '\0';
		alumnos[i].sex[strcspn(alumnos[i].sex, "\n")] = '\0';

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
			case 'n':
				search(opcion[0]);
		}

	} while (opcion[0] != 's');

	printf("Gracias por visitar\n");
	return 0;
}

