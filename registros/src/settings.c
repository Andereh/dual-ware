#include "settings.h"

void erase_enter(char *str)
{
    while (*str != '\n')
        str++;

    *str = '\0';
}

void add_user()
{
    return;
    return;
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

    } while (strcmp(opcion, "s") != 0);
}
