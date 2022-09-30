#include "routines.h"
#include "alumno.h"
#include "utils.h"
#include <stdio.h>

int actual_alumns_number = 0, posFinal, idExtend[10];

Alumno alumnos[10]; // arreglo de alumnos

void save_scores(Alumno al)
{

    char score_str[100];
    char line[128], line_showNotes[128];
    char opcion[64];

    char dir_name[64] = "";
    char folder[]     = "./calificaciones/";
    char extension[]  = ".txt";

    strcat(dir_name, folder);
    strcat(dir_name, al.name);
    strcat(dir_name, extension);
    // resultado: ./calificaciones/<algun-nombre>.txt

    FILE *ddbb_scores = fopen(dir_name, "r");

    getchar(); // para limpiar el buffer nada mas
    if (ddbb_scores == NULL)
    {
        printf(" \n %s Aun no aun no tiene calificaciones\n\n", al.name);
        printf(" Te gustaria agregarlas? (Si == s): ");
        scanf("%s", opcion);

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
                float score;
                do
                {
                    printf(" Evaluacion %d: ", j + 1);
                    scanf("%f", &score);
                } while (score < 0 || score > 100);

                // gcvt() convierte un float a cadena, 6 es es tamañno maximo de
                // cadena score_str donde sera guardada
                // esta funcion no existe en la compu de la uni

                /* ---> */ gcvt(score, 6, score_str);

                fputs(score_str, ddbb_scores);
                fputc('\n', ddbb_scores);
                al.trimesters[i].notes[j] = score;
            }
        }
        fputc('*', ddbb_scores);
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
            line[strcspn(line, "\n")] = '\0';

            int score = atoi(line);
            // se mostraban los numeros con un '.' asi que se lo quito
            // strtok(line, ".");

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

void infoExtend()
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

        printf("\n Elija el ID correspondiente al alumno.\n"
               " ( El ID es el numero a la izquierda del alumno )\n\n");


        do
        {
            printf(" Ingresar ID: ");
            scanf("%d", &ID);

            // idExtend almacena los ID de las personas que aparezcan en la
            // busqueda
            if (ID < idExtend[0] || ID > idExtend[posFinal])
                printf("\n El ID ingresado no corresponde a ningun alumno en "
                       "la busqueda\n\n");

        } while (ID < idExtend[0] || ID > idExtend[posFinal]);

        system("clear");

        printf("\n\t\t Informacion detalla de %s\n\n", alumnos[ID - 1].name);

        save_scores(alumnos[ID - 1]);

        // print_alumno(alumnos[ID-1]);
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
    int  pos       = 0;
    bool found_at_least_one_al;

    if (mode == 'n')
        strcpy(phase, "el nombre");
    else if (mode == 'c')
        strcpy(phase, "la cedula");


    do
    {
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
                // pues usalos njd
                idExtend[pos] = alumnos[i].id;
                posFinal      = pos; // Es para saber cuantos id se guardaron
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

void load_ddbb()
{
    int  max_alums = 10; // numero de alumnos maximos
    char line[128];      // aqui se guardan las lineas que se van leyendo

    actual_alumns_number = 0;

    FILE *data_base = fopen("./pseudo_data_base.txt", "r");
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
            if (feof(data_base)) // si encuentra esto significa que estamos en el final del archivo
                return;
        } while (strcmp(line, "\n") == 0);


        strcpy(alumnos[i].name,
               line); // se supone que si salio del bucle es porque la linea no
                      // estaba vacia


        // se copian porque la asignacion directa no es valida en C
        strcpy(alumnos[i].ci,
               fgets(line, 128,
                     data_base)); // ahora si escuentra un espacio nos jodemos
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

