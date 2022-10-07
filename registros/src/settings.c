#include "settings.h"
#include "alumno.h"
#include "routines.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int           actual_year = 2022;
extern int    actual_alumns_number;
extern Alumno alumnos[];

void add_user()
{
    char opcion[10];

    Alumno temp;

    do
    {

        //Lo puse dentro del while pq cuando se repitia no guardaba mas usuarios :3

        FILE *ddbb;
        ddbb = fopen("./pseudo_data_base.txt", "a");

         if (ddbb == NULL)
        {
            printf("Problemas al abrir la base de datos\n");
            exit(0);
        }


        system("clear");


        /*Campo nombre*/

        printf(" Nombre: ");
        fgets(temp.name, 120, stdin);

        while (strlen(temp.name) < 4 || only_characters(temp.name))
        {

            if (strlen(temp.name) < 4)
            {
                printf("\n El nombre debe tener al menos 4 caracteres\n");
                printf(" Nombre: ");
                fgets(temp.name, 64, stdin);
            }
            

            if (only_characters(temp.name))
            {
                printf("\n Estamos seguros que ningun nombre contiene un numero.\n Nombre: ");
                fgets(temp.name,64,stdin);
            }
        }

        /*Campo cedula*/
        

        printf(" Cedula (Si es extranjero ingrese su N\167 pasaporte): ");
        fgets(temp.ci, 10, stdin);

        while (strlen(temp.ci) == 1 || only_numbers(temp.ci) ) // siempre se guarda el enter
        {

            if (strlen(temp.ci) == 1)
            {
                printf("\n Este campo no puede estar vacio\n"
                   ". Intenta de nuevo: ");
                fgets(temp.ci, 10, stdin);
            }
            //para que solo ingrese numeros (una cedula en venezuela con letras lol :u)
            if (only_numbers(temp.ci))
            {
                printf("\n Solamente puede contener numeros. Intenta de nuevo: ");
                fgets(temp.ci, 10, stdin);
            }
            
            if (strlen(temp.ci) > 9)
            {
                printf("\n No puede tener mas de 8 digitos. Intenta de nuevo: ");
                fgets(temp.ci,10,stdin);
            }
        }

        bool has_repeated;
        do
        {
            has_repeated = false;

            for (int i = 0; i < actual_alumns_number; ++i)
            {
                erase_enter(temp.ci);
                if (strcmp(alumnos[i].ci, temp.ci) == 0)
                {
                    printf(" Este numero de cedula ya esta registrado\n");
                    printf(" Intenta de nuevo: ");
                    fgets(temp.ci, 10, stdin);

                    while (strlen(temp.ci) == 1) // siempre se guarda el enter
                    {
                        printf("\n Este campo no puede estar vacio\n"
                               " Cedula: ");
                        fgets(temp.ci, 10, stdin);
                    }
                    i = 0;

                    has_repeated = true;
                }
            }

        } while (has_repeated);

        fflush(stdin);//limpiar el buffer

        /*Fecha de nacimiento*/

        printf(" Año de nacimiento: ");
        fgets(temp.year_of_birth, 6, stdin);

        while (strtol(temp.year_of_birth, NULL, 10) > actual_year)
        {
            printf("\n Debido a que las maquinas del tiempo aun no se inventan "
                   "las "
                   "personas no pueden nacer en el futuro\n"
                   " Año de nacimiento: ");
            fgets(temp.year_of_birth, 6, stdin);
        }

        /*Campo sexo*/

        printf("\n\t( Masculino = m / Femenino = f )\n\tSexo: ");
        fgets(temp.sex, 3, stdin);

        if (temp.sex[0] >= 'a' && temp.sex[0] <= 'z')
            temp.sex[0] -= 32;

        erase_enter(temp.sex);

        while (strcmp(temp.sex, "M") && strcmp(temp.sex, "F"))
        {
            printf(
                " Lamentablemente no aceptamos personas con generos raros. Por "
                "favor no se ofenda\n");
            printf("\n\t( Masculino = m / Femenino = f )\n\tSexo: ");

            fgets(temp.sex, 2, stdin);
            if (temp.sex[0] >= 'a' && temp.sex[0] <= 'z')
                temp.sex[0] -= 32;

            erase_enter(temp.sex);
        }

        if (temp.name[0] >= 'a' && temp.name[0] <= 'z')
            temp.name[0] -= 32;

        fprintf(ddbb, "%s\n", temp.ci);
        fprintf(ddbb, "%s", temp.name);
        fprintf(ddbb, "%s", temp.year_of_birth);
        fprintf(ddbb, "%s\n\n", temp.sex);

        fclose(ddbb);

        load_ddbb();
        // actual_alumns_number++;
        save_scores_id(actual_alumns_number - 1);


        printf("\n Quieres seguir agregando alumnos?: ");
        fgets(opcion, 10, stdin);
    } while (opcion[0] == 's' || opcion[0] == 'S');
}

void remove_user(int user_id)
{
    FILE *ddbb      = fopen("./pseudo_data_base.txt", "r");
    FILE *temp_file = fopen("./calificaciones/temp.txt", "w");
    char  line[120];

    if (ddbb == NULL)
    {
        printf(" Problemas al abrir la base de datos\n");
        exit(0);
    }

    while (!feof(ddbb))
    {
        fgets(line, 120, ddbb);
        erase_enter(line);

        if (strcmp(alumnos[user_id].ci, line) == 0)
            for (int i = 0; i < 3; ++i)
                fgets(line, 120, ddbb);
        else
        {
            if (has_a_enter(line))
                fprintf(temp_file, "%s", line);
            else
                fprintf(temp_file, "%s\n", line);
        }
    }
    fclose(ddbb);
    fclose(temp_file);

    ddbb      = fopen("./pseudo_data_base.txt", "w");
    temp_file = fopen("./calificaciones/temp.txt", "r");

    rewind(temp_file);
    while (!feof(temp_file))
    {
        fgets(line, 120, temp_file);

        if (has_a_enter(line))
            fprintf(ddbb, "%s", line);
        else
            fprintf(ddbb, "%s\n", line);
    }
    char dir[128];
    sprintf(dir, "./calificaciones/%s.txt", alumnos[user_id].name);

    remove(dir);
    fclose(ddbb);
    fclose(temp_file);
}

void settings()
{
    char user[32];
    char passw[32];
    char opcion[32];
    int  attemps = 0;


    do
    {
        system("clear");
        printf(" Estas accediendo a la configuracion del programa\n");
        printf("\n\nNecesitas iniciar sesion como SuperUsuario\n");

        printf("\n\n\tUsuario: ");
        fgets(user, 32, stdin);
        printf("\tClave: ");
        fgets(passw, 32, stdin);

        erase_enter(user);
        erase_enter(passw);

        if (attemps == 3)
        {
            printf("\n\n\tDemasiados intentos.\n");
            printf("Regresando al menu\n");
            return;
        }

    } while (strcmp(user, "Admin") && strcmp(passw, "1234"));

    do
    {
        system("clear");

        printf("\n\n\t1. Agregar un nuevo alumno\n");
        printf("\t2. Eliminar un nuevo alumno\n");
        printf("\n\tSalir == s");
        printf("\n\n Opcion: ");
        fgets(opcion, 32, stdin);

        switch (opcion[0])
        {
        case '1':
            add_user();
            break;
        case '2':
        {
            char user_text[10];
            int  alumn_id;

            system("clear");
            printf("\n\n");
            show_all_alumns(alumnos);

            printf("\n Elije el ID del alumno a eliminar: ");
            fgets(user_text, 10, stdin);

            alumn_id = atoi(user_text);

            while (alumn_id < 1 || alumn_id > actual_alumns_number)
            {
                printf("\n Este ID aun no esta registrado. Intenta de nuevo\n");

                printf("\n Elije el ID del alumno a eliminar: ");
                fgets(user_text, 10, stdin);

                alumn_id = atoi(user_text);
            }

            printf("\n Estas seguro que quieres eliminar a '%s' del sistema?: ",
                   alumnos[alumn_id - 1].name);
            fgets(user_text, 10, stdin);

            if (user_text[0] != 's' && user_text[0] != 'S')
                return;

            printf(" Totalmente seguro?: ");
            fgets(user_text, 10, stdin);

            if (user_text[0] != 's' && user_text[0] != 'S')
                return;

            remove_user(alumn_id - 1);
            load_ddbb();
        }
        }


    } while (strcmp(opcion, "s\n") != 0);
}
