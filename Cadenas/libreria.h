#include <stdbool.h>
#include <stdio.h>

#ifndef LIBRERIA_H
#define LIBRERIA_H

// acá van las declaraciones

int  validInt();
bool hasAChar(char* strStart, char* strEnd);
bool wantToRepeat();

void printUser();
void minToMaxV(char[100]); 
void MaxToMinV(char[100]);
void minToMax(char[100]);
void MaxToMin(char[100]);
bool session();
void separar();
void concatenarDosApellidos();
void firstLetterUP(char x[100], char y[100], char z[100], char v[100]);
void apellidosIguales(char x[100], char y[100], char z[100], char v[100]);
void mostrarNombreMayusculas();
int  numberOfWords(char x[100]);
int  numberOf4VocalWords(char x[100]);
int  numberOfVocalRepeatWords();
void vocalInString(char x[100]);
void vocalRever(char x[100]);
int  WordStartsWithVowel(char x[100]);
void showWordStartsWithVowel(char x[100]);
void twoVocalWords(char x[100]);
void consonantsInString(char x[100]);
void vocalesAsteriscos(char x[100]);
void bigger(char x[100],char y[100]);
void lower(char x[100], char y[100]);
bool noChar(char x[100]);
void numberRepeat(char x[100]);
void numberInOtherString(char x[100], char y[100]);
void numberDifferent(char x[100]);
void printInvert(char x[100]);
void minToMaxString(char x[100]);

// Programas

void program1();
void program2();
void program3();
void program4();
void program5();
void program6();
void program7();

#endif
