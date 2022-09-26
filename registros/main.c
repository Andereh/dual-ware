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

void save_scores(struct Alumno al) 
{

	char score_str[100];
	char line[128],line_showNotes[128];
	char opcion[64];
	char dir_name[64] = "";
	char folder[] = "./calificaciones/";
	char extension[] = ".txt";
	// al.name[strspn(al.name, "l")] = '-'; // cambiamos los espacios por guiones
										 // esto no cambia la base de datos
	strcat(dir_name, folder);
	strcat(dir_name, al.name);
	strcat(dir_name, extension);
	// resultado: ./<algun-nombre>.txt

	FILE *ddbb_scores = fopen(dir_name, "r");

	if (ddbb_scores == NULL)
	{
		printf(" \n %s Aun no aun no tiene calificaciones\n\n", al.name);
		printf(" Te gustaria agregarlas? (Si == s): ");
		scanf("%s", opcion);

		// freopen(dir_name, "w+", ddbb_scores);
		
		if (opcion[0] != 's')
			return;

		printf("\n\n Dir name: %s\n", dir_name);

		printf("\n Ingrese las notas de %s",al.name);
		// reasignamos ddbb_scores
		FILE *ddbb_scores = fopen(dir_name, "w+");

		for (int i = 0; i < 3; i++)
		{
			printf("\n\n\t Trimeste %d\n\n",i+1);

			for (int j = 0; j < 4; j++)
			{
				
				// la notas van de 1-100
				// pd: aja y si saque 0
				float score;
				do {
					printf(" Evaluacion %d: ",j+1);
					scanf("%f",&score);
				} while(score < 0 || score > 100 );

				// gcvt() convierte un float a cadena, 6 es es tamañno maximo de cadena
				// score_str donde sera guardada
				gcvt(score, 6, score_str);
				fputs(score_str, ddbb_scores);
				fputc('\n', ddbb_scores);
				al.trimesters[i].notes[j] = score;

			}
			// fputc('~',ddbb_scores);

		}
		fputc('*',ddbb_scores);
		fclose(ddbb_scores);
	}
	else 
	{

		printf("\n Promedio de %s: \n", al.name);

		int n_trimetres = 1;
		float promTotal = 0;
		while (n_trimetres <= 3) {
			float prom = 0;
			
			for (int i = 0; i < 4; ++i) 
			{
				fgets(line, 120, ddbb_scores); 
				prom += atoi(line) * 0.25;
				
			}
			promTotal += prom; 

			printf("\n\n\t Promedio en el trimestre %d: %.2f", n_trimetres, prom);

			n_trimetres++;
		}
		
		promTotal /= 3;

		printf("\n\n\t Promedio total:             %.2f",promTotal);
		getchar();
		fclose(ddbb_scores);
		
		n_trimetres = 1;//lo reseteo pq lo necesito :3

		//Mostrar todas sus notas

		FILE *show_notes = fopen(dir_name,"r");

		printf("\n\n\n Notas de %s: ",al.name);

		while (n_trimetres <= 3) {
			float prom = 0;

			printf("\n\n\t Notas en el trimestre %d: \n", n_trimetres);

			for (int i = 0; i < 4; ++i) 
			{
				fgets(line_showNotes, 120, show_notes);
				//se mostraban los numeros con un '.' asi que se lo quito
				strtok(line_showNotes,".");
				printf("\n\t\tEvaluacion %d: %s",i+1,line_showNotes);
			}

			n_trimetres++;
		}
		fclose(show_notes);
	}

	// fputc('*',notes_baseData);
}

//Es para mostrar las notas
void infoExtend()
{	
	char opcion[10], guardarN[10];// guardarN sirve para preguntarle al usuario si quiere
								  // guardar las notas del alumno elegido
	int ID;

	printf("\n\n Desea ver mas informacion sobre uno de los alumnos? (Si == s): ");
	fgets(opcion, 10, stdin);

	if (opcion[0] == 's')
	{
		
		printf("\n Elija el ID correspondiente al alumno.\n"
			" ( El ID es el numero a la izquierda del alumno )\n\n");
		

		do {
			printf(" Ingresar ID: "); scanf("%d",&ID);

			//idExtend almacena los ID de las personas que aparezcan en la busqueda
			if(ID < idExtend[0] || ID > idExtend[posFinal])
			printf("\n El ID ingresado no corresponde a ningun alumno en la busqueda\n\n");

		} while(ID < idExtend[0] || ID > idExtend[posFinal]);

		system("clear");

		printf("\n\t\t Informacion detalla de %s\n\n",alumnos[ID-1].name);

		save_scores(alumnos[ID-1]);

		//print_alumno(alumnos[ID-1]);
		printf("\n\n\n");
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
	bool found_at_least_one_al;

	if (mode == 'n')
		strcpy(phase, "el nombre");
	else if (mode == 'c')
		strcpy(phase, "la cedula");


	do {
		found_at_least_one_al = false;

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
				found_at_least_one_al = true;

				// Guardamos los id de los alumnos encontrados 
			    // para luego usarlos
				idExtend[pos] = alumnos[i].id;
				posFinal = pos;//Es para saber cuantos id se guardaron
				pos++;
			}
		}


		if (!found_at_least_one_al) 
			printf(" No se encontro nada con esos valores\n");
		else
			infoExtend();

		printf("\n Seguir buscando? (Si == s): ");
		fgets(opcion, 10, stdin);
	} while (opcion[0] == 's');

}

//Si, guarda las notas :3
//Es solo una prueba probablemente no sea igual al final

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

