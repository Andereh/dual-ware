#include <stdbool.h>
#include <stdio.h>

#ifndef LIBRERIA_H
#define LIBRERIA_H

// acá van las declaraciones

int  validInt();
bool hasAChar(char* strStart, char* strEnd);
bool wantToRepeat();

void highOrLow();
void highOrLowLastNames();
void highOrLowNames();
void printUser();
void minToMaxV();
void MaxToMinV();
void minToMax();
void MaxToMin();
bool session();
void separar();
void concatenarDosApellidos(char x[100], char y[100], char z[100], char v[100]);
void firstLetterUP(char x[100], char y[100], char z[100], char v[100]);
void apellidosIguales(char x[100], char y[100], char z[100], char v[100]);
void mostrarNombreMayusculas();
int  numberOfWords(char x[100]);
int  numberOf4VocalWords(char x[100]);
int  numberOfVocalRepeatWords();
void vocalInString(char x[100]);
void divideAndConcatenateVocalsREVER(char x[100]);
int  WordStartsWithVowel(char x[100]);
void showWordStartsWithVowel(char x[100]);
void twoVocalWords(char x[100]);
void consonantsInString(char x[100]);
void vocalesAsteriscos(char x[100], char y[100]);

// Programas

void program1();
void program2();
void program3();
void program4();
void program5();
void program6();

#endif
