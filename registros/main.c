#include "src/routines.h"
#include "src/settings.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Alumno alumnos[]; // la sacamos de routines.c



int main(int argc, char *argv[])
{

    char opcion[32];

    load_ddbb();

    do
    {
        system("clear");
        show_all_alumns(alumnos);
        printf("\n\n\t\t Busqueda ");
        printf("\n\n\tBuscar por ID  -> i");
        printf("\n\tBuscar por cedula  -> c");
        printf("\n\tBuscar por nombre  -> n");
        printf("\n\tBuscar por edad  -> y");
        printf("\n\tConfiguraciones -> f");
        printf("\n\tSalir -> s");

        printf("\n\n Opcion: ");
        fgets(opcion, 10, stdin);

        switch (opcion[0])
        {
        case 'c':
        case 'n':
        case 'y':
        case 'i':
            search(opcion[0]);
            break;
        case 'f':
            settings();
        }

    } while (opcion[0] != 's');

    printf(" Gracias por visitar\n");
    return 0;
}

