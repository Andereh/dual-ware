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
void save_scores_id(int);
void infoExtend();
int load_ddbb();
void search(char);
void settings();
void show_all_scores();
void show_all_promedy(Alumno al);
