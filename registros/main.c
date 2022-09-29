#include "src/routines.h"
#include "src/settings.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Alumno alumnos[]; // la sacamos de routines.c

// Es para mostrar las notas

// Si, guarda las notas :3
// Es solo una prueba probablemente no sea igual al final

int main(int argc, char *argv[])
{

    char opcion[32];

    load_ddbb();

    do
    {
        system("clear");
        show_all_alumns(alumnos, 2);

        printf("\n\n\tBuscar por cedula  -> c");
        printf("\n\tBuscar por nombre  -> n");
        printf("\n\tConfiguraciones -> f");
        printf("\n\tSalir -> s");

        printf("\n\n Opcion: ");
        fgets(opcion, 10, stdin);

        switch (opcion[0])
        {
        case 'c':
        case 'n':
            search(opcion[0]);
            break;
        case 'f':
            settings();
        }

    } while (opcion[0] != 's');

    printf(" Gracias por visitar\n");
    return 0;
}

