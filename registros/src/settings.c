#include "settings.h"
#include "routines.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int actual_year = 2022;

void add_user()
{
    FILE *ddbb;
    ddbb = fopen("./pseudo_data_base.txt", "a");

    if (ddbb == NULL)
    {
        printf("Problemas al abrir la base de datos\n");
        exit(0);
    }

    Alumno temp;


    /*Campo nombre*/

    printf(" Nombre: ");
    fgets(temp.name, 120, stdin);

    while (strlen(temp.name) < 4)
    {
        printf("\n El nombre debe tener al menos 4 caracteres\n");
        printf(" Nombre: ");
        fgets(temp.name, 64, stdin);
    }

    /*Campo cedula*/

    printf(" Cedula: ");
    fgets(temp.ci, 10, stdin);

    while (strlen(temp.ci) == 1) // siempre se guarda el enter
    {
        printf("\n Este campo no puede estar vacio\n"
               " Cedula: ");
        fgets(temp.ci, 10, stdin);
    }

    /*Fecha de nacimiento*/

    printf(" Año de nacimiento: ");
    fgets(temp.year_of_birth, 6, stdin);

    while (strtol(temp.year_of_birth, NULL, 10) > actual_year)
    {
        printf("\n Debido a que las maquinas del tiempo aun no se inventan las "
               "personas no pueden nacer en el futuro\n"
               " Año de nacimiento: ");
        fgets(temp.year_of_birth, 6, stdin);
    }

    /*Campo sexo*/

    printf("\n Indique el sexo del estudiante\n"
           "\tMasculino = m\n"
           "\tFemenino = f\n"
           "\n\tSexo: ");

    fgets(temp.sex, 3, stdin);

    if (temp.sex[0] >= 'a' && temp.sex[0] <= 'z')
        temp.sex[0] -= 32;

    erase_enter(temp.sex);

    while (strcmp(temp.sex, "M") && strcmp(temp.sex, "F"))
    {
        printf(" Lamentablemente no aceptamos personas con generos raros. Por "
               "favor no se ofenda\n");
        printf("\n\tMasculino = m\n"
               "\tFemenino = f\n"
               "\n\tSexo: ");

        fgets(temp.sex, 2, stdin);
        if (temp.sex[0] >= 'a' && temp.sex[0] <= 'z')
            temp.sex[0] -= 32;

        erase_enter(temp.sex);
    }

    if (temp.name[0] >= 'a' && temp.name[0] <= 'z')
        temp.name[0] -= 32;

    fprintf(ddbb, "%s", temp.name);
    fprintf(ddbb, "%s", temp.ci);
    fprintf(ddbb, "%s", temp.year_of_birth);
    fprintf(ddbb, "%s\n\n", temp.sex);

    /*fputs(temp.ci, ddbb);           */
    /*fputs(temp.year_of_birth, ddbb);*/
    /*fputs(temp.sex, ddbb);          */

    /*fputs("\n\n", ddbb);*/
    fclose(ddbb);
    load_ddbb();
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

        printf("\n\n\t1. Agregar un nuevo usuario\n");
        printf("Opcion: ");
        fgets(opcion, 32, stdin);

        switch (opcion[0])
        {
        case '1':
            add_user();
        }


    } while (strcmp(opcion, "s\n") != 0);
}
