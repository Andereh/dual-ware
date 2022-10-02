#include "utils.h"
#include "alumno.h"
#include <stdbool.h>
#include <stdio.h>

extern int actual_alumns_number;

void erase_enter(char *str)
{
    while (*(str) != '\0')
    {
        if (*str == '\n')
            *str = '\0';
        str++;
    }
}

void show_all_alumns(Alumno al[])
{
    char dir_name[128];
    for (int i = 0; i < actual_alumns_number; ++i)
    {
        print_alumno(al[i]);


        sprintf(dir_name, "./calificaciones/%s.txt", al[i].name);
        FILE *check = fopen(dir_name, "r");

        if (check == NULL)
            printf("\033[33m*\033[0m");
    }
}

void space_and_printl(char str[], int len) // hacia la izquierda
{
    int spaces = len - strlen(str);

    printf("%s", str);
    while (spaces-- > 0)
        printf(" ");
}

void space_and_printr(char str[], int len) // hacia la derecha
{
    int spaces = len - strlen(str);

    while (spaces-- > 0)
        printf(" ");
    printf("%s", str);
}

void print_alumno(Alumno al)
{
    char nums_str[3];
    printf("\n #");
    sprintf(nums_str, "%d", al.id);
    space_and_printr(nums_str, 2);
    printf(" | ");

    space_and_printl(al.name, 20);
    printf("| ");

    space_and_printr(al.ci, 9);
    printf(" | ");

    space_and_printl(al.year_of_birth, 5);
    space_and_printl(al.sex, 3);
}

bool has_a_enter(char str[])
{
    while (*str != '\0')
    {
        if (*str == '\n')
            return true;
        str++;
    }
    return false;
}
