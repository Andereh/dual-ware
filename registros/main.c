#include "src/routines.h"
#include "src/settings.h"
#include "src/utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Alumno alumnos[]; // la sacamos de routines.c

int actual_alumns_number;

int main(int argc, char *argv[])
{

    char opcion[32];

    do
    {
        actual_alumns_number = load_ddbb();
        system("clear");
        show_all_alumns(alumnos);
        printf("\n\n\t\t Menu \n\n");

        printf("\n\t Menu de busqueda -> b");
        printf("\n\t Mostrar notas de todos los alumnos -> t");
        printf("\n\t Configuraciones -> f");
        printf("\n\t Salir -> s");

        printf("\n\n Opcion: ");
        fgets(opcion, 10, stdin);

        switch (opcion[0])
        {
        case 'b':
            do{
                system("clear");
                printf("\n\t Menu de busqueda\n");
                printf("\n\n\tBuscar por ID  -> i");
                printf("\n\tBuscar por cedula  -> c");
                printf("\n\tBuscar por nombre  -> n"); 
                printf("\n\tBuscar por edad  -> y");
                printf("\n\n Opcion: "); fgets(opcion,10,stdin);

                if (only_characters(opcion))
                {
                    printf("\n\n Caracter invalido");
                    system("pause");
                }

            }while (only_characters(opcion) || strlen(opcion) > 2);   
            search(opcion[0]);
            break;
        case 'f':
            settings();
            break;
        case 't':
            show_all_scores();
            break;
        case 'p':

            system("clear");
            printf("\n\t\t Promedio por Trimestre \n\n\n ");
            space_and_printl("Alumno", 15); printf(" | ");
            space_and_printl("Trimestre", 11); 

            for (int i = 1; i <= 3; ++i)
            {
                char intenger[10];
                printf(" | ");
                sprintf(intenger,"%d",i);
                space_and_printl(intenger, 6);
            }
            //space_and_printr("",6);
            printf(" | \n\n");

            for (int i = 0; i < actual_alumns_number; i++)
            {
                show_all_promedy(alumnos[i]);
                
                
            }

            printf("\n\n");
            system("pause");
        }

    } while (opcion[0] != 's');

    printf(" \n\n Gracias por visitar\n");
    return 0;
}

