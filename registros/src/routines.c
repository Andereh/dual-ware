#include "routines.h"
#include "alumno.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int actual_alumns_number = 0, posFinal, idExtend[10];

// lo declaro global pq no funcinaba en la funcion search()
int  yearOld = 0, actualYear = 2022;
char str_id[2], str_yearOld[5], aux[64];

Alumno alumnos[10]; // arreglo de alumnos

void save_scores_id(int id) { save_scores(alumnos[id]); }

void save_scores(Alumno al)
{

    char score_str[100];
    char line[128], line_showNotes[128];
    char opcion[64];

    char dir_name[64] = "";
    char folder[]     = "./calificaciones/";
    char extension[]  = ".txt";

    char temp[10];

    strcat(dir_name, folder);
    strcat(dir_name, al.name);
    strcat(dir_name, extension);
    // resultado: ./calificaciones/<algun-nombre>.txt

    FILE *ddbb_scores = fopen(dir_name, "r");

    /*char c;                                    */
    /*while ((c = getchar()) != '\n' && c != EOF)*/
    /*    ;                                      */
    if (ddbb_scores == NULL)
    {
        printf(" \n %s Aun no aun no tiene calificaciones\n\n", al.name);
        printf(" Te gustaria agregarlas? (Si == s): ");
        fgets(opcion, 10, stdin);

        // freopen(dir_name, "w+", ddbb_scores);

        if (opcion[0] != 's')
            return;

        printf("\n Ingrese las notas de %s", al.name);
        // reasignamos ddbb_scores
        FILE *ddbb_scores = fopen(dir_name, "w+");

        for (int i = 0; i < 3; i++)
        {
            printf("\n\n\t Trimeste %d\n\n", i + 1);

            for (int j = 0; j < 4; j++)
            {
                int score;
                do
                {
                    printf(" Evaluacion %d: ", j + 1);
                    fgets(temp, 10, stdin);
                    score = atoi(temp);
                } while (score < 0 || score > 100);

                /*
                    Pase el valor a entero y
                    Cambie gcvt() por sprintf()
                */

                /* ---> */ sprintf(score_str, "%d", score);

                fputs(score_str, ddbb_scores);
                fputc('\n', ddbb_scores);
                al.trimesters[i].notes[j] = score;
            }
        }

        fclose(ddbb_scores);
        return;
    }

    int   n_trimetres = 1;
    float promTotal   = 0;

    n_trimetres = 1; // lo reseteo pq lo necesito :3

    printf("\n\n\n Notas de %s:\n\n", al.name);
    printf("\t\033[30;47m Trimestre");

    for (int i = 0; i < 4; ++i)
    {
        printf(" | ");
        space_and_printr("25%", 3);
    }

    printf(" | Prom  \n\033[0m");

    while (n_trimetres <= 3)
    {
        float prom = 0;

        printf("\t");
        space_and_printr("", strlen("Trimestre") - 1);
        printf("#%d", n_trimetres);
        printf(" | ");
        // printf("\t #%d | ", n_trimetres);

        for (int i = 0; i < 4; ++i)
        {
            fgets(line, 120, ddbb_scores);
            erase_enter(line);
            int score = atoi(line);

            space_and_printr(line, 3);
            printf(" | ");
            prom += score * 0.25f; // 25%
        }

        if (prom >= 75.0)
            printf("\033[32;1m"); // verde
        else if (prom >= 60.0)
            printf("\033[93;1m"); // amarillo
        else
            printf("\033[31;1m"); // rojo

        printf("%.2f\n", prom);
        printf("\033[0m");
        n_trimetres++;
    }
    fclose(ddbb_scores);

    // fputc('*',notes_baseData);
}


void infoExtend(int alumnos_ids[], int num_of_ids)
{
    char opcion[10],
        guardarN[10]; // guardarN sirve para preguntarle al usuario si quiere
                      // guardar las notas del alumno elegido
    int ID;


    printf(
        "\n\n Desea ver mas informacion sobre uno de los alumnos? (Si == s): ");
    fgets(opcion, 10, stdin);

    if (opcion[0] == 's')
    {


        bool is_in_list = false;
        do
        {
            system("clear");

            if (num_of_ids == 1)
            {
                ID = alumnos_ids[0];
                break;
            }
            else
            {
                printf("\n\n");
                for (int i = 0; i < num_of_ids; ++i)
                    print_alumno(alumnos[alumnos_ids[i] - 1]);

                printf("\n\n\n Elija el ID correspondiente al alumno.\n"
                       " ( El ID es el numero a la izquierda del alumno )\n\n");
                printf(" Ingresar ID: ");
                scanf("%d", &ID);
                getchar();
            }

            
            for (int i = 0; i < num_of_ids; ++i)
                if (ID == alumnos_ids[i])
                    is_in_list = true;

            if (!is_in_list)
                printf(" Respecto a la busqueda. No hay ningun alumno con ese "
                       "ID\n");

        } while (!is_in_list);

        system("clear");

        printf("\n\t\t Informacion detalla de %s\n\n", alumnos[ID - 1].name);

        save_scores(alumnos[ID - 1]);

        // print_alumno(alumnos[ID-1]);
        printf("\n\n\n");
    }
}

void search(char mode)
{
    char user_request[64];
    char to_search[64];
    char search_substr[64];
    char opcion[10];
    char phase[10] = "";
    int  pos       = 0;
    int  num_of_founded_ids;

    if (mode == 'n')
        strcpy(phase, "el nombre");
    else if (mode == 'c')
        strcpy(phase, "la cedula");
    else if (mode == 'i')
        strcpy(phase, "el ID");
    else if (mode == 'y')
        strcpy(phase, "la edad");

    do
    {
        int founded_ids[actual_alumns_number];
        num_of_founded_ids = 0;

        fflush(stdin);

        printf("\n Ingrese %s a buscar: ", phase);
        fgets(user_request, 64, stdin);
        erase_enter(user_request);

        if (mode == 'y')
            strcpy(aux, user_request); // guardamos el valor ingresado
                                       // para despues darselo de vuelta


        system("clear");
        printf("\n Busqueda: '%s'\n", user_request);

        for (int i = 0; i < actual_alumns_number; ++i)
        {


            if (mode == 'n')
                strcpy(to_search, alumnos[i].name);
            else if (mode == 'c')
                strcpy(to_search, alumnos[i].ci);
            else if (mode == 'y')
            {
                yearOld = atoi(user_request); // pasamos la edad entero

                yearOld =
                    actualYear - yearOld; // restamos el año actual con la edad

                sprintf(str_yearOld, "%d",
                        yearOld); // pasamos a cadena de nuevo :V

                strcpy(user_request,
                       str_yearOld); // Guardamos el año para comparar

                strcpy(to_search, alumnos[i].year_of_birth);
            }
            else if (mode == 'i')
            {
                // pasar el id a cadena
                sprintf(str_id, "%d", alumnos[i].id);
                strcpy(to_search, str_id);
            }

            // extraemos cuantos caracteres sea la longitud de la busqueda
            // y los asignamos a 'name_substr'
            strncpy(search_substr, to_search, strlen(user_request));
            search_substr[strlen(user_request)] = '\0';
            // Casualmente esta funcion no coloca el \0 al final de la cadena

            // strcasecmp no toma en cuenta las mayusculas
            if (strcasecmp(search_substr, user_request) == 0)
            {
                print_alumno(alumnos[i]);

                // Guardamos los id de los alumnos encontrados
                // para luego usarlos
                // pues usalos njd
                idExtend[pos] = alumnos[i].id;
                posFinal      = pos; // Es para saber cuantos id se guardaron
                pos++;
                founded_ids[num_of_founded_ids] = alumnos[i].id;
                num_of_founded_ids++;
            }

            if (mode == 'y')
                strcpy(user_request,
                       aux); // reasignamos el valor de user_request
        }


        if (num_of_founded_ids == 0)
            printf(" No se encontro nada con esos valores\n");
        else
            infoExtend(founded_ids, num_of_founded_ids);

        printf("\n Seguir buscando? (Si == s): ");
        fgets(opcion, 10, stdin);
    } while (opcion[0] == 's');
}

void load_ddbb()
{
    int  max_alums = 10; // numero de alumnos maximos
    char line[128];      // aqui se guardan las lineas que se van leyendo

    actual_alumns_number = 0;

    FILE *data_base = fopen("./pseudo_data_base.txt", "r");
    printf("Load\n");
    // abrimos el falsa base de datos

    if (data_base == NULL)
    {
        printf("Problemas al abrir la base de datos\n");
        exit(0);
    }

    for (int i = 0; i < max_alums; i++)
    {
        do
        {
            fgets(line, 120, data_base);
            if (feof(data_base)) // si encuentra esto significa que estamos en
                                 // el final del archivo
                return;
        } while (strcmp(line, "\n") == 0);


        strcpy(alumnos[i].ci, line); // se supone que si salio del bucle es
                                     // porque la linea no estaba vacia
        strcpy(alumnos[i].name,
               fgets(line, 128,
                     data_base)); // ahora si escuentra un espacio nos jodemos


        // se copian porque la asignacion directa no es valida en C
        strcpy(alumnos[i].year_of_birth, fgets(line, 128, data_base));
        strcpy(alumnos[i].sex, fgets(line, 128, data_base));
        alumnos[i].id = i + 1;


        // donde encuentre un salto de linea lo elimina
        erase_enter(alumnos[i].name);
        erase_enter(alumnos[i].ci);
        erase_enter(alumnos[i].year_of_birth);
        erase_enter(alumnos[i].sex);

        actual_alumns_number++;
    }

    fclose(data_base);
}

