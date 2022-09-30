#include "utils.h"
#include "alumno.h"

extern int actual_alumns_number;

void erase_enter(char *str)
{
    while (*str != '\n')
        str++;

    *str = '\0';
}

void show_all_alumns(Alumno al[])
{
    for (int i = 0; i < actual_alumns_number; ++i)
        print_alumno(al[i]);
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
    printf("\n #%d | ", al.id);
    space_and_printl(al.name, 20);
    printf("| ");
    space_and_printr(al.ci, 9);
    printf(" | ");
    space_and_printl(al.year_of_birth, 5);
    space_and_printl(al.sex, 3);
}

