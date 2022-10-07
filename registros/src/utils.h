#ifndef UTILS_H
#define UTILS_H

#include "alumno.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


void erase_enter(char *str);
void print_alumno(Alumno al);
void space_and_printl(char[], int);
void space_and_printr(char[], int);
void show_all_alumns(Alumno[]);
bool has_a_enter(char[]);
bool only_numbers(char[]);
bool only_characters(char[]);

#endif /* ifndef UTILS_H */
