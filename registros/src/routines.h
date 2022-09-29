#define ROUTINES_H
#include "alumno.h"
#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_alumno(Alumno al);
void space_and_printl(char[], int);
void space_and_printr(char[], int);
void save_scores(Alumno al);
void infoExtend();
void load_ddbb();
void search(char);
void show_all_alumns(Alumno[], int);
void settings();
