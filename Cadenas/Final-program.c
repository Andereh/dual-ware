// Final-program

#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <windows.h> fuck u windows*/

// Variables de uso global

char word[400], word2[400];
int opt, program;

// funciones de uso recurrente
void printProgram() { printf("\n Programa %d\n\n\n", program); }

int main(int argc, char const* argv[])
{

    system("color 0B");

    if (!session())
    {
        system("clear");
        printf("\n\n Se ha equivocado mas de 3 veces. Se ha deshabilitado el "
               "inicio de sesion\n\n");
        system("pause");
    }
    else
    {

        do
        {
            system("clear");
            printUser();

            printf("\n\n\n\t     MENU \n");

            printf("\n\t 1: Programa 1");
            printf("\n\t 2: Programa 2");
            printf("\n\t 3: Programa 3");
            printf("\n\t 4: Programa 4");
            printf("\n\t 5: Programa 5");
            printf("\n\t 6: Programa 6");
            printf("\n\t 7: Programa 7");
            printf("\n\t Otro. Salir");
            printf("\n\n\t Ingresar: ");
            opt     = validInt();
            program = opt;

            switch (opt)
            {

            case 1:
                program1();
                break;

            case 2:
                program2();
                break;

            case 3:
                program3();
                break;

            case 4:
                program4();
                break;

            case 5:
                program5();
                break;

            case 6:
                program6();
                break;

            case 7:
                program7();
            }

            // Si ingresa cualquier numero menor que 8 (excepto 1-2)
            // Cambiara su valor para salir del programa
            // ESTO SOLO SE EJECUTA AL FINALIZAR CADA FUNCION CORRESPONDIENTE
            if (opt < 1 || opt > 2)
                opt = 10;

        } while (opt <= 7);
    }

    system("clear");
    printf("\nMUCHAS GRACIAS POR UTILIZAR NUESTRO PROGRAMA :3 :D\n\n\n");
    system("pause");
    return 0;
}

void program1()
{

    char aux[100];
    int   program;

    do
    {
        system("clear");
        printUser();
        printProgram();

        printf("\n\n\t\tIngrese una frase: ");
        fgets(word, 400, stdin);
        printf("\n\t\tIngrese otra frase: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");
        
        do
        {
            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\n\t Ha ingresado 2 cadenas de caracteres decida que "
                       "hacer\n");
                printf("\n\t 1: Cadena mayor y menor Alfabeticamente");
                printf("\n\t 2: Segunda cadena con las vocales a Mayusculas");
                printf(
                    "\n\t 3: Primera cadena con las consonantes a minusculas");
                printf("\n\t 4: Cadenas concatenadas");
                printf("\n\t 5: Cadenas concatenada invertida");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }
                system("clear");
                printUser();
                printProgram();

            } while (opt < 1 || opt > 5);

            switch (opt)
            {
            case 1:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Cadena mayor y menor alfabeticamente\n");
                printf("\n\t Cadena mayor: "); bigger(word,word2);
                printf("\n\t Cadena menor: "); lower(word,word2);
                break;

            case 2:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\t Segunda cadena con las vocales mayusculas: ");
                minToMaxV(word2);
                break;

            case 3:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\t Primera cadena con las consonantes a minusculas: ");
                MaxToMin(word);
                break;

                // Mostrar las cadenas concatenadas
            case 4:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();

                strcpy(aux, word2);
                strcat(aux, " ");
                strcat(aux, word);

                printf("\n\t Cadenas concatenadas: %s", aux);
                break;

                // Mostrar las cadenas concatenadas invertidas
            case 5:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                strtok(word,"\n");
                strtok(word2,"\n");
                strcpy(aux, word2);
                strcat(aux, " ");
                strcat(aux, word);
                printf("\n\t Cadena concatenada invertida: ");
                printInvert(aux);
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program2()
{

    char aux[100];
    int   program;
    // Se usaran para copiar los nombres completos
    // Puesto que luego seran separados
    char copyPerson1[100], copyPerson2[100];

    char firstName1[400], firstLastName1[400], secondName1[400],
        secondLastName1[400];
    char firstName2[400], firstLastName2[400], secondName2[400],
        secondLastName2[400];

    do
    {
        system("clear");
        printUser();
        printProgram();
        printf("\n Ingrese los nombres y apellidos de dos personas\n\n");
        printf("\n NOTA ''La persona debe tener dos nombres y dos apellidos\n "
                "      De no ser asi no funcionara''\n\n");
        printf("\n\t\t1: Ingrese sus nombres y apellidos: ");
        fgets(word, 400, stdin);
        printf("\n\t\t2: Ingrese sus nombres y  apellidos: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");

        // Copiar los nombres completos ya que luego seran separados
        strcpy(copyPerson1, word);
        strcpy(copyPerson2, word2);

        separar(firstName1, secondName1, firstLastName1, secondLastName1, word);
        separar(firstName2, secondName2, firstLastName2, secondLastName2,
                word2);

        do
        {

            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\t Ha ingresado nombre y apellido de dos personas "
                       "\n\t Decida que hacer\n");
                printf("\n\t 1: Persona con el primer apellido Alfabeticamente "
                       "mayor");
                printf("\n\t    Y Persona con el segundo nombre menor "
                       "Alfabeticamente ");
                printf("\n\t 2: Apellidos de la primera y segunda persona con "
                       "las vocales mayusculas");
                printf("\n\t 3: Primer Nombre de cada persona con las "
                       "consonantes mayusculas");
                printf("\n\t 4: Apellidos de la segunda persona concatenado "
                       "con los nombres de la primera persona");
                printf("\n\t 5: Primeros nombres de las personas concatenados "
                       "e invertidos");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }
                system("clear");
                printUser();
                printProgram();
            } while (opt < 1 || opt > 5);

            switch (opt)
            {

            case 1:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Persona con el primer apellido mayor alfabeticamente\n");
                printf("\n\t Primer apellido mayor: "); bigger(firstLastName1,firstLastName2);
                printf("\n\n\t Persona con el segundo nombre menor alfabeticamente\n");
                printf("\n\t Segundo nombre menor: "); lower(secondName1,secondName2);
                //highOrLowNames(secondName1, secondName2);
                break;

            case 2:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Convertidas las vocales a mayusculas\n\n");
                printf("\n\t Apellidos de la primera persona: ");
                minToMaxV(firstLastName1);
                printf(" ");
                minToMaxV(secondLastName1);
                printf("\n\t Apellidos de la segunda persona: ");
                minToMaxV(firstLastName2);
                printf(" ");
                minToMaxV(secondLastName2);
                break;

            case 3:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Primer Nombre de cada persona con las consonantes "
                       "mayusculas\n\n");
                printf("\t Persona 1: ");
                minToMax(firstName1);
                printf("\n\t Persona 2: ");
                minToMax(firstName2);
                printf("\n\n");
                break;

            case 4:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Apellidos de la segunda persona concatenado con "
                       "los nombres de la primera persona");

                // Concatenando
                strcpy(aux, firstName1);
                strcat(aux, " ");
                strcat(aux, secondName1);
                strcat(aux, " ");
                strcat(aux, firstLastName2);
                strcat(aux, " ");
                strcat(aux, secondLastName2);

                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s", copyPerson2);
                printf("\n\n\t Concatenado: %s", aux);
                break;
            case 5:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Primeros nombres de las personas concatenados e "
                       "invertidos\n");

                // concatenando
                strcpy(aux, firstName1);
                strcat(aux, " ");
                strcat(aux, firstName2);

                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s", copyPerson2);
                printf("\n\n\t Concatenado: ");
                printInvert(aux);
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program3()
{

    char aux[100];
    int  program;
    // Se usaran para copiar los nombres completos
    // Puesto que luego seran separados
    char copyPerson1[100], copyPerson2[100];
    char firstName1[400], firstLastName1[400], secondName1[400],
        secondLastName1[400];
    char firstName2[400], firstLastName2[400], secondName2[400],
        secondLastName2[400];

    do
    {
        system("clear");
        printUser();
        printProgram();
        printf("\n Ingrese los nombres y apellidos de dos personas\n");
        printf("\n NOTA ''La persona debe tener dos nombres y dos apellidos\n "
                   "      De no ser asi no funcionara''\n\n");
        printf("\n\t\t1: Ingrese sus nombres y apellidos: ");
        fgets(word, 400, stdin);
        printf("\n\t\t2: Ingrese sus nombres y  apellidos: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");

        // Copiar los nombres completos ya que luego seran separados
        strcpy(copyPerson1, word);
        strcpy(copyPerson2, word2);

        separar(firstName1, secondName1, firstLastName1, secondLastName1, word);
        separar(firstName2, secondName2, firstLastName2, secondLastName2,
                word2);

        do
        {

            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\t Ha ingresado nombre y apellido de dos personas "
                       "\n\t Decida que hacer\n");
                printf("\n\t 1: Primer nombre mayor alfabeticamente y segundo "
                       "nombre menor alfabeticamente de ambas personas");
                printf("\n\t 2: Apellidos de la primera y nombres de la "
                       "segunda persona con las vocales a mayusculas");
                printf("\n\t 3: Nombres de la primera y apellidos de la "
                       "segunda persona con las consonantes a mayusculas");
                printf("\n\t 4: Apellidos de la primera persona concatenados "
                       "con los apellidos de la segunda persona");
                printf("\n\t 5: Segundos nombres de las personas concatenados "
                       "e invertidos");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }
                system("clear");
                printUser();
                printProgram();
            } while (opt < 1 || opt > 5);

            switch (opt)
            {

            case 1:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Primer nombre mayor: "); bigger(firstName1, firstName2);
                printf("\n\n\t Segundo nombre menor: "); lower(secondName1, secondName2);
                break;

            case 2:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Convertidas las vocales a mayusculas\n\n");
                printf("\n\t Apellidos de la primera persona: ");
                minToMaxV(firstLastName1);
                printf(" ");
                minToMaxV(secondLastName1);
                printf("\n\t Nombres de la segunda persona: ");
                minToMaxV(firstName2);
                printf(" ");
                minToMaxV(secondName2);
                break;

            case 3:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Convertidas las consonantes a mayusculas\n\n");
                printf("\n\t Nombres de la primera persona: ");
                minToMax(firstName1);
                printf(" ");
                minToMax(secondName1);
                printf("\n\t Apellidos de la segunda persona: ");
                minToMax(firstLastName2);
                printf(" ");
                minToMax(secondLastName2);
                break;

            case 4:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Apellidos de la primera persona concatenados con "
                       "los apellidos de la segunda persona");

                // Concatenando
                strcpy(aux, firstLastName1);
                strcat(aux, " ");
                strcat(aux, secondLastName1);
                strcat(aux, " ");
                strcat(aux, firstLastName2);
                strcat(aux, " ");
                strcat(aux, secondLastName2);

                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s", copyPerson2);
                printf("\n\n\t Concatenado: %s", aux);
                break;
            case 5:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Segundos nombres de las personas concatenados e "
                       "invertidos\n");

                // concatenando
                strcpy(aux, secondName1);
                strcat(aux, " ");
                strcat(aux, secondName2);

                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s", copyPerson2);
                printf("\n\n\t Concatenado: ");
                printInvert(aux);
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program4()
{

    char aux[100];
    int   program;
    // Se usaran para copiar los nombres completos
    // Puesto que luego seran separados
    char copyPerson1[100], copyPerson2[100];
    char firstName1[400], firstLastName1[400], secondName1[400],
        secondLastName1[400];
    char firstName2[400], firstLastName2[400], secondName2[400],
        secondLastName2[400];

    do
    {
        system("clear");
        printUser();
        printProgram();
        printf("\n Ingrese los nombres y apellidos de dos personas\n");
        printf("\n NOTA ''La persona debe tener dos nombres y dos apellidos\n "
                   "      De no ser asi no funcionara''\n\n");
        printf("\n\t\t1: Ingrese sus nombres y apellidos: ");
        fgets(word, 400, stdin);
        printf("\n\t\t2: Ingrese sus nombres y  apellidos: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");

        // Copiar los nombres completos ya que luego seran separados
        strcpy(copyPerson1, word);
        strcpy(copyPerson2, word2);

        separar(firstName1, secondName1, firstLastName1, secondLastName1, word);
        separar(firstName2, secondName2, firstLastName2, secondLastName2,
                word2);

        do
        {

            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\t Ha ingresado nombre y apellido de dos personas "
                       "\n\t Decida que hacer\n");
                printf("\n\t 1: Primer nombre en mayuscula de la persona que "
                       "tenga el segundo nombre mayor alfabeticamente");
                printf("\n\t 2: Primera letra en mayuscula de los apellidos "
                       "\n\t    de la persona que tenga el primer apellido "
                       "mayor alfabeticamente");
                printf("\n\t 3: Determinar si algun apellido de las dos "
                       "personas es igual");
                printf("\n\t 4: Apellido menor de la primera persona "
                       "concatenado con los apellidos de la segunda persona");
                printf("\n\t 5: Segundos apellidos de las personas concatenados "
                       "e invertidos");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }
                system("clear");
                printUser();
                printProgram();
            } while (opt < 1 || opt > 5);

            switch (opt)
            {

            case 1:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Primer nombre en mayuscula de la persona que "
                       "tenga el segundo nombre mayor alfabeticamente\n\n");
                mostrarNombreMayusculas(firstName1, firstName2, secondName1,
                                        secondName2);
                break;

            case 2:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Primera letra en mayuscula de los apellidos \n\t "
                       "de la persona que tenga el primer apellido mayor "
                       "alfabeticamente\n\n");
                firstLetterUP(firstLastName1, firstLastName2, secondLastName1,
                              secondLastName2);
                break;

            case 3:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Determinar si algun apellido de las dos personas "
                       "es igual\n\n");
                apellidosIguales(firstLastName1, firstLastName2,
                                 secondLastName1, secondLastName2);
                break;

            case 4:

                printf("\n cargando...");
                system("clear");

                printUser();
                printProgram();
                printf("\n\t Apellido menor de la primera persona concatenado "
                       "con los apellidos de la segunda persona\n");
                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s\n", copyPerson2);

                concatenarDosApellidos(firstLastName1, firstLastName2, secondLastName1,
                            secondLastName2);
                printf("\n\n");
                break;

            case 5:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Segundos apellidos de las personas concatenados e "
                       "invertidos\n");

                // concatenando
                strcpy(aux, secondLastName1);
                strcat(aux, " ");
                strcat(aux, secondLastName2);

                printf("\n\n\t Primera persona: %s", copyPerson1);
                printf("\n\n\t Segunda persona: %s", copyPerson2);
                printf("\n\n\t Concatenado: %s", aux);
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program5()
{

    char aux[100];
    int  program;

    do
    {
        system("clear");
        printUser();
        printProgram();

        printf("\n\n\t\tIngrese una frase: ");
        fgets(word, 400, stdin);
        printf("\n\t\tIngrese otra frase: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");

        do
        {
            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\n\t Ha ingresado 2 cadenas de caracteres decida que "
                       "hacer\n");
                printf("\n\t 1: Numero de palabras de cada cadena");
                printf("\n\t 2: Numero de palabras con 4 vocales distintas en "
                       "la segunda cadena");
                printf("\n\t 3: Numero de palabras con vocales repetidas en la "
                       "primera cadena");
                printf("\n\t 4: Vocales contenidas en la primera cadena");
                printf("\n\t 5: Vocales en la primera cadena concatenada "
                       "invertida");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }
                system("clear");
                printUser();
                printProgram();
            } while (opt < 1 || opt > 5);

            switch (opt)
            {
            case 1:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Numero de palabras de cada cadena\n\n");
                printf("\n\t Cadena 1: %d", numberOfWords(word));
                printf("\n\t Cadena 2: %d", numberOfWords(word2));
                break;

            case 2:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Numero de palabras con 4 vocales distintas en la "
                       "segunda cadena: ");
                printf("\n\n\t Numero de palabras: %d",
                       numberOf4VocalWords(word2));
                break;

            case 3:

                printf("\n\nCargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Numero de palabras con vocales repetidas en la "
                       "primera cadena");
                printf("\n\n\t Numero de palabras: %d",
                       numberOfVocalRepeatWords(word));
                break;

                // Mostrar las cadenas concatenadas
            case 4:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Vocales contenidas en la primera cadena ");
                printf("\n\t Vocales: ");
                vocalInString(word);
                break;

                // Mostrar las cadenas concatenadas invertidas
            case 5:

                printf("\n Cargando...");
                system("clear");
                printUser();
                printProgram();
                printf("\n\t Vocales en la primera Cadena concatenada "
                       "invertida: \n\t vocales: ");
                vocalRever(word);printf("\n\n");
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program6()
{

    char aux[100];
    int  suma = 0;

    do
    {
        system("clear");
        printUser();
        printProgram();

        printf("\n\n\t\tIngrese una frase: ");
        fgets(word, 400, stdin);
        printf("\n\t\tIngrese otra frase: ");
        fgets(word2, 400, stdin);

                strtok(word,"\n");
                strtok(word2,"\n");

        //quitar salto de linea
        strtok(word,"\n");
        strtok(word2,"\n");

        do
        {
            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\n\t Ha ingresado 2 cadenas de caracteres decida que "
                       "hacer\n");
                printf("\n\t 1: Numero de palabras que empiezan con una vocal");
                printf("\n\t 2: Palabras con 2 vocales en la segunda cadena");
                printf("\n\t 3: Palabras que inician con una vocal en la "
                       "primera cadena");
                printf("\n\t 4: Consonantes contenidas en la primera cadena");
                printf("\n\t 5: Vocales convertidas en asteriscos ");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }

            } while (opt < 1 || opt > 5);
            printf("\n\nCargando...");
            system("clear");
            printUser();
            printProgram();

            switch (opt)
            {
            case 1:

                printf("\n\t Numero de palabras que empiezan con una vocal\n\n");
                suma = WordStartsWithVowel(word) + WordStartsWithVowel(word2);
                printf("\n\t Numero: %d", suma);
                break;

            case 2:

                printf("\n\t Palabras con 2 vocales en la segunda cadena\n");
                printf("\n\t Palabras: "); twoVocalWords(word2); printf("\n\n");
                break;

            case 3:

                printf("\n\t Palabras que inician con una vocal en la primera "
                       "cadena \n");
                showWordStartsWithVowel(word);
                break;
                // Mostrar las cadenas concatenadas
            case 4:

                printf("\n Cargando..."); system("clear");
                printUser();
                printProgram();
                printf("\n\t Consonantes contenidas en la primera cadena \n");
                printf("\n\t Consonantes: ");
                consonantsInString(word);
                break;

                // Mostrar las cadenas concatenadas invertidas
            case 5:
            
                printf("\n Cargando..."); system("clear");
                printUser();
                printProgram();
                printf("\n\t Vocales convertidas en asteriscos: ");
                vocalesAsteriscos(word);
                printf(" ");
                vocalesAsteriscos(word2);
            }

        } while (wantToRepeat());

    } while (opt == 3);
}

void program7()
{

    char aux[100];
    int  suma = 0;
    bool letter = false;

    do
    {
        
        do{

            system("clear");
            printUser();
            printProgram();
            letter = false;
            printf("\n\n\t\tIngrese una cantidad numerica entera: ");
            fgets(word, 400, stdin); strtok(word,"\n");
            printf("\n\t\tIngrese otra catidad numerica entera: ");
            fgets(word2, 400, stdin); strtok(word2,"\n");

            if(noChar(word) || noChar(word2)){
                printf("\n\n\t Solo puedes ingresar numeros enteros\n\n");
                letter = true;
                system("pause");
            } 
        }while(letter);
        

        do
        {
            system("clear");
            printUser();
            printProgram();

            do
            {

                printf("\n\n\t Ha ingresado 2 cadenas de caracteres decida que "
                       "hacer\n");
                printf("\n\t 1: Cadena mayor y menor");
                printf("\n\t 2: Numeros que se repiten en la primera cadena");
                printf("\n\t 3: Primera cadena concatenada con la segunda");
                printf("\n\t 4: Numeros distintos en la segunda cadena");
                printf("\n\t 5: Numeros en la primera cadena contenidos en la segunda ");
                printf("\n\n\t Ingresar: ");
                opt = validInt();

                if (opt < 1 || opt > 5)
                {
                    printf(
                        "\n Solo hay opciones entre 1-5 intenta de nuevo\n\n");
                    system("pause");
                }

            } while (opt < 1 || opt > 5);
            printf("\n\nCargando...");
            system("clear");
            printUser();
            printProgram();

            switch (opt)
            {
            case 1:

                printf("\n\t Cadena mayor y menor\n\n");
                printf("\n\t Cadena mayor: "); bigger(word,word2);
                printf("\n\t Cadena menor: "); lower(word,word2);
                break;

            case 2:
                printf("\n\t Cadena: %s\n",word);
                printf("\n\t Numeros que se repiten en la primera cadena: ");
                numberRepeat(word); printf("\n\n");
                break;

            case 3:

                printf("\n\t Primera cadena concatenada con la segunda: ");
                strcpy(aux,word);strcat(aux," ");strcat(aux,word2);
                printf("%s\n\n",aux);
                break;
                // Mostrar las cadenas concatenadas
            case 4:

                printf("\n Cargando..."); system("clear");
                printUser();
                printProgram();
                printf("\n\t Numeros distintos en la segunda cadena: ");
                numberDifferent(word2);
                break;

                // Mostrar las cadenas concatenadas invertidas
            case 5:
            
                printf("\n Cargando..."); system("clear");
                printUser();
                printProgram();
                printf("\n\t Primera cadena: %s\n",word);
                printf("\n\t segunda cadena: %s\n",word2);
                printf("\n\t Numeros en la primera cadena contenidos en la segunda: ");
                numberInOtherString(word,word2);printf("\n\n");
            }

        } while (wantToRepeat());

    } while (opt == 3);
}
