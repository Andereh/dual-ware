#ifndef ROUTINES_H
#define ROUTINES_H

typedef struct
{
    char name[64];
    char ci[10];
    char year_of_birth[4]; // agno de nacimiento
    int  id;
    char sex[2];

    struct Trimester
    {
        float notes[4];
    } trimesters[3];

} Alumno;

void print_alumno(Alumno al);
void space_and_printl(char[], int);
void space_and_printr(char[], int);

#endif
