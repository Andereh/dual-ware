#ifndef ALUMNO_H
#define ALUMNO_H

typedef struct
{
    char name[64];
    char ci[9];
    char year_of_birth[6]; // agno de nacimiento
    int  id;
    char sex[3];

    struct Trimester
    {
        float notes[4];
    } trimesters[3];
} Alumno;

#endif /* ifndef SYMBOL */
