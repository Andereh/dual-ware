/*
    DOCUMENTACION:

    Este programa es un intento de base de datos

    Hecho por
                Jose Flores
                Ronald Hernandez

    Principalmente hecho para ver, modificar, eliminar y añandir, tanto nuevos alumnos
    como cada una de las notas de los alumnos. Ademas de un basico menu de busqueda para
    encontrar cualquier alumno mediante ciertos parametros

    Esta divido en 9 Archivos fijos (Podras ver los demas archivos en la carpera /src) 
    mas los archivos variables (dentro de /Calificaciones) dependiendo del numero de
    alumnos que se ingresen 
*/


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
        printf("\n\t Mostrar promedio de cada Trimestre -> p");
        printf("\n\t Salir -> s");

        printf("\n\n Opcion: ");
        fgets(opcion, 10, stdin);

        switch (opcion[0])
        {
        case 'b':
            do{
                system("clear");
                printf("\n\t Menu de busqueda\n");
                printf("\n\n\t Buscar por ID      -> i");
                printf("\n\t Buscar por cedula  -> c");
                printf("\n\t Buscar por nombre  -> n"); 
                printf("\n\t Buscar por edad    -> y");
                printf("\n\t Volver             -> v");
                printf("\n\n Opcion: "); 
                fgets(opcion,10,stdin);

                if (only_characters(opcion))
                {
                    printf("\n\n Caracter invalido\n\n");
                    system("pause");
                }

                if ((opcion[0] != 'i'  && opcion[0] != 'c') && 
                    (opcion[0] != 'n'  && opcion[0] != 'y'  && opcion[0] != 'v'))
                {
                    printf("\n Esa opcion no existe intentalo de nuevo\n\n");
                    system("pause");
                }

            }while (only_characters(opcion)   && (opcion[0] != 'i' && opcion[0] != 'c' ) 
                         && (opcion[0] != 'v' &&  opcion[0] != 'n' && opcion[0] != 'y' ));

            if (opcion[0] != 'v') 
                search(opcion[0]);

            break;
        case 'f':
            settings();
            break;
        case 't':
            show_all_scores();
            break;
        case 'p':

            system("cls");
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
                              show_all_promedy(alumnos[i]);

            printf("\n\n");
            system("pause");
        }

    } while (opcion[0] != 's');

    printf(" \n\n Gracias por visitar\n");
    return 0;
}

