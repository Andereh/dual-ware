#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <windows.h> merwebo maldito windows*/

int  contador = 0, i;
char init1[100], init2[100];
char user[] = {"Burga"}, password[] = {"sexo"};
char firstName1[400], firstLastName1[400], secondName1[400],
    secondLastName1[400];
char firstName2[400], firstLastName2[400], secondName2[400],
    secondLastName2[400];

bool hasAChar(char* strStart, char* strEnd) // Para validar que una
                                            // cadena no tenga caracteres
{
    char* ptr = strStart;
    if (*ptr == '-')
        ptr++;
    while (ptr <= strEnd && *ptr != '\0')
    {
        if ((*ptr < 48 || *ptr > 57))
            return true;
        if (*(++ptr) == '\n')
            *ptr = '\0';
    }

    return false;
}

bool wantToRepeat() // Para repetir el bucle
{

    int opt;

    printf("\n\n\t\tOPCIONES\n");
    printf("\n\t1. De nuevo con la misma cadena\n");
    printf("\t2. Volver al menu de programas \n");
    printf("\t3. De nuevo con una nueva cadena\n");
    printf("\tOtro. Salir del programa\n");
    printf("\nOpcion: ");
    opt = validInt();

    return opt == 1;
}

int validInt() // Te retorna un int.
               // La uso para no validar cada
               // que necesitamos ingresar algo
{
    char str[10];
    int  num, i;

    fgets(str, 10, stdin);

    while (hasAChar(str, str + 10))
    {
        printf("Caracteres detectados. Intente de nuevo: ");
        fgets(str, 10, stdin);
    }

    return (int)strtol(str, NULL, 10);
}

void printUser() { printf("\n Usuario: %s", init1); }

bool session()
{

    do
    {
        system("clear");
        printf("\n\t\t\t\t INICIAR SESION ");
        printf("\n\n\n \t\t\t\t Usuario: ");
        fgets(init1, 10, stdin);
        printf("\n\t\t\t\t Clave: ");
        fgets(init2, 10, stdin);

        printf("\n Validando datos...");

        // Comparar los datos ingresados con los datos almacenados
        // Si son diferentes se cancela el inicio de sesion
        if ((strcmp(init1, user) != 0 && strcmp(init2, password) != 0) &&
            contador < 3)
        {

            if (contador < 3)
            {

                printf("\n\n Usuario y Clave incorrecta ");
                printf("\n\n");
                system("pause");
            }

            contador++;
        }
        else if ((strcmp(init1, user) != 0) && contador < 3)
        {

            if (contador < 3)
            {
                printf("\n\n Usuario incorrecto ");
                printf("\n\n");
                system("pause");
            }
            contador++;
        }
        else if ((strcmp(init2, password) != 0) && contador < 3)
        {

            if (contador < 3)
            {
                printf("\n\n Clave incorrecta ");
                printf("\n\n");
                system("pause");
            }
            contador++;
        }
    } while ((strcmp(init1, user) != 0 || strcmp(init2, password) != 0) &&
             contador < 3);

    if (contador > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Determinar la cadena mayor y menor alfabeticamente
void highOrLow(char x[100], char y[100])
{

    if (strcmp(x, y) == 0)
    {
        printf("\n\t Ambas cadenas son iguales");
        printf("\n\t Cadena 1 ingresada: %s", x);
        printf("\n\t Cadena 2 ingresada: %s\n\n", y);
    }
    else if (strcmp(x, y) < 0)
    {
        printf("\n\t La segunda cadena ingresada es mayor Alfabeticamente");
        printf("\n\t Cadena ingresada: %s\n\n", y);
        printf("\n\t La primera cadena ingresada es menor Alfabeticamente");
        printf("\n\t Cadena ingresada: %s\n\n", x);
    }
    else
    {
        printf("\n\t La primera cadena ingresada es mayor Alfabeticamente");
        printf("\n\t Cadena ingresada: %s\n\n", x);
        printf("\n\t La segunda cadena ingresada es menor Alfabeticamente");
        printf("\n\t Cadena ingresada: %s\n\n", y);
    }
}

// separar la cadena por nombre y apellido
void separar(char x[100], char y[100], char z[100], char a[100], char o[100])
{

    int  c           = 1;
    char limitador[] = {" "};
    char token;

    // Nombres
    strcpy(x, strtok(o, limitador));
    strcpy(y, strtok(NULL, limitador));
    // Apellidos
    strcpy(z, strtok(NULL, limitador));
    strcpy(a, strtok(NULL, limitador));
}

// Los mismo que lo anterior (pero para nombres de personas como lo determina el
// programa)
void highOrLowNames(char x[100], char y[100])
{

    if (strcmp(x, y) == 0)
    {
        printf("\n\t Ambos son iguales Alfabeticamente");
        printf("\n\t Nombre 1 ingresada: %s", x);
        printf("\n\t Nombre 2 ingresada: %s\n\n", y);
    }
    else if (strcmp(x, y) < 0)
    {
        printf("\n\t Nombre de persona 2 ingresado es mayor Alfabeticamente");
        printf("\n\t Nombre ingresado: %s\n\n", y);
        printf("\n\t Nombre de persona 1 ingresado es menor Alfabeticamente");
        printf("\n\t Nombre ingresado: %s\n\n", x);
    }
    else
    {
        printf("\n\t Nombre de persona 1 ingresado es mayor Alfabeticamente");
        printf("\n\t Nombre ingresado: %s\n\n", x);
        printf("\n\t Nombre de persona 2 ingresado es menor Alfabeticamente");
        printf("\n\t Nombre ingresado: %s\n\n", y);
    }
}

// Los mismo que lo anterior (pero para apellidos de personas como lo determina
// el programa)
void highOrLowLastNames(char x[100], char y[100])
{

    if (strcmp(x, y) == 0)
    {
        printf("\n\t Ambos son iguales Alfabeticamente");
        printf("\n\t Cadena 1 ingresada: %s", x);
        printf("\n\t Cadena 2 ingresada: %s\n\n", y);
    }
    else if (strcmp(x, y) < 0)
    {
        printf("\n\t Apellido de persona 2 ingresado es mayor Alfabeticamente");
        printf("\n\t Apellido ingresado: %s\n\n", y);
        printf("\n\t Apellido de persona 1 ingresado es menor Alfabeticamente");
        printf("\n\t Apellido ingresado: %s\n\n", x);
    }
    else
    {
        printf("\n\t Apellido de persona 1 ingresado es mayor Alfabeticamente");
        printf("\n\t Apellido ingresado: %s\n\n", x);
        printf("\n\t Apellido de persona 2 ingresado es menor Alfabeticamente");
        printf("\n\t Apellido ingresado: %s\n\n", y);
    }
}

// de minisculas a mayusculas solo vocales
void minToMaxV(char x[100])
{

    int  vocal = 0;
    char a;
    char aux[100];
    strcpy(aux, x);

    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal >= 1)
        {
            strupr(aux);
            printf("%c", aux[i]);
        }
        else
        {
            strlwr(aux);
            printf("%c", x[i]);
        }
        vocal = 0;
    }
}

// de minisculas a  mayusculas solo consonantes
void minToMax(char x[100])
{

    int  vocal = 0;
    char a;
    char aux[100];
    strcpy(aux, x);

    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal < 1)
        {
            strupr(aux);
            printf("%c", aux[i]);
        }
        else
        {
            strlwr(aux);
            printf("%c", x[i]);
        }
        vocal = 0;
    }
}

// de mayusculas a minisculas solo vocales
void MaxToMinV(char x[100])
{

    int  vocal = 0;
    char a;
    char aux[100];
    strcpy(aux, x);
    strupr(aux);

    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal == 0)
        {
            strlwr(aux);
            printf("%c", aux[i]);
        }
        else
        {
            strupr(aux);
            printf("%c", aux[i]);
        }
        vocal = 0;
    }
}

// de mayusculas a minisculas solo consonantes
void MaxToMin(char x[100])
{

    int  vocal = 0;
    char a;
    char aux[100];
    strcpy(aux, x);
    strupr(aux);

    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal == 0)
        {
            strlwr(aux);
            printf("%c", aux[i]);
        }
        else
        {
            strupr(aux);
            printf("%c", aux[i]);
        }
        vocal = 0;
    }
}

// Mostrar el primer nombre en mayusculas de la persona con el segundo nombre
// mayor alfabeticamente
void mostrarNombreMayusculas(char x[100], char y[100], char z[100], char v[100])
{

    // x Primer nombre de persona 1
    // y primer nombre de persona 2
    // z segundo nombre persona 1
    // v segundo nombre de persona 2

    if (strcmp(z, v) > 0)
    {

        strupr(x);
        printf("\n\t Nombre: %s \n\n", x);
    }
    else if (strcmp(z, v) < 0)
    {

        strupr(y);
        printf("\n\t Nombre: %s \n\n", y);
    }
    else
    {
        printf("\n\t Sus segundos nombres son iguales alfabeticamente \n");
        printf("\n\t Persona 1: %s ", z);
        printf("\n\t Persona 2: %s \n\n", v);
    }
}

// Primera letra en mayúscula de los apellidos de la persona que tenga el primer
// apellido mayor alfabéticamente
void firstLetterUP(char x[100], char y[100], char z[100], char v[100])
{

    // x Primer apellido de persona 1
    // y primer apellido de persona 2
    // z segundo apellido persona 1
    // v segundo apellido de persona 2

    char letter[2], helper1[100], helper2[100], l[1];

    if (strcmp(x, y) > 0)
    {

        //almacenar la primera letra del primer apellido
        letter[0] = x[0];
        l[0]      = x[0];
        //almacenar la primera letra del segundo apellido
        letter[1] = z[0];
        strupr(letter);
        //separar el apellido de la primera letra
        // ejemplo Jose ==> ose                    
        strcpy(helper1, strtok(x, l));   
        l[0] = z[0];
        strcpy(helper2, strtok(z, l));
        printf("\n\t Apellidos: %c%s %c%s\n\n", letter[0], helper1, letter[1],
               helper2);
    }
    else if (strcmp(x, y) == 0)
    {
        printf("\n\t Sus primeros apellidos son iguales alfabéticamente\n\n");
        printf("\n\t Persona 1: %s", x);
        printf("\n\t Persona 2: %s\n\n", y);
    }
    else
    {
        //almacenar la primera letra del primer apellido
        letter[0] = y[0];
        l[0]      = y[0];
        //almacenar la primera letra del segundo apellido
        letter[1] = v[0];
        strupr(letter);
        //separar el apellido de la primera letra
        // ejemplo Jose ==> ose
        strcpy(helper1, strtok(y, l));
        l[0] = v[0];
        strcpy(helper2, strtok(v, l));
        printf("\n\t Apellidos: %c%s %c%s\n\n", letter[0], helper1, letter[1],
               helper2);
    }
}

// Determinar si hay algun apellido igual entre las dos personas
void apellidosIguales(char x[100], char y[100], char z[100], char v[100])
{

    // x Primer apellido de persona 1
    // y primer apellido de persona 2
    // z segundo apellido persona 1
    // v segundo apellido de persona 2

    if ((strcmp(x, y) == 0) && (strcmp(z, v) == 0))
    {
        printf("\n\t Todos los apellidos son iguales Alfabeticamente");
        printf("\n\t Apellidos: %s - %s - %s - %s", x, z, y, v);
    }
    else if ((strcmp(x, v) == 0) && (strcmp(y, z) == 0))
    {
        printf("\n\t El primer apellido de la persona 1 es igual al segundo "
               "apellido de la persona 2");
        printf("\n\t Y el primer apellido de la persona 2 es igual al segundo "
               "apellido de la persona 1\n\n");
        printf("\n\t Apellidos: %s - %s - %s - %s", x, z, y, v);
    }
    else if (strcmp(x, y) == 0)
    {
        printf("\n\t El primer apellido de ambas personas son iguales\n\n");
        printf("\n\t Apellidos: %s - %s", x, y);
    }
    else if (strcmp(z, v) == 0)
    {
        printf("\n\t El segundo apellido de ambas personas son iguales\n\n");
        printf("\n\t Apellidos: %s - %s", z, v);
    }
    else if (strcmp(x, v) == 0)
    {
        printf("\n\t El primer apellido de la persona 1 es igual que el "
               "segundo apellido de la persona 2");
        printf("\n\t Apellidos: %s - %s", x, v);
    }
    else if (strcmp(y, z) == 0)
    {
        printf("\n\t El primer apellido de la persona 2 es igual que el "
               "segundo apellido de la persona 1");
        printf("\n\t Apellidos: %s - %s", y, z);
    }
    else
    {
        printf("\n\t Ninguno de los apellidos coincide con el de la otra "
               "persona\n\n");
        printf("\n\t Apellidos: %s - %s - %s - %s", x, z, y, v);
    }
    printf("\n\n");
}

// Concatenar los 2 apellidos de la segunda persona con el apellido menor de la
// primera persona
void concatenarDosApellidos()
{

    char aux[100];

    if (strcmp(firstLastName1, secondLastName1) < 0)
    {

        strcpy(aux, firstLastName1);
        strcat(aux, " ");
        strcat(aux, firstLastName2);
        strcat(aux, " ");
        strcat(aux, secondLastName2);

        printf("\n\t Concatenado: %s", aux);
    }
    else
    {
        strcpy(aux, secondLastName1);
        strcat(aux, " ");
        strcat(aux, firstLastName2);
        strcat(aux, " ");
        strcat(aux, secondLastName2);

        printf("\n\t Concatenado: %s", aux);
    }
}

// Mostrar numero de palabras
int numberOfWords(char x[100])
{

    int   c           = 0;
    char  limitador[] = {" "};
    char* token       = strtok(x, limitador);

    // Nombres
    if (token != NULL)
    {
        while (token != NULL)
        {

            token = strtok(NULL, limitador);
            c++;
        }
    }

    return c;
}
// Mostrar el numero de palabras que tiene 4 vocales diferentes
int numberOf4VocalWords(char x[100])
{

    int a = 0, e = 0, I = 0, o = 0, u = 0, suma = 0;
    strlwr(x);
    int   c           = 0;
    char  limitador[] = {" "};
    char* token       = strtok(x, limitador);

    if (token != NULL)
    {
        printf("\n\n\t Palabras: ");
        while (token != NULL)
        {

            for (i = 0; i <= strlen(token); i++)
            {

                switch (token[i])
                {
                case 'a':
                    a++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'i':
                    I++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'u':
                    u++;
                }
            }

            suma = a + e + I + o + u;
            if ((a <= 1) && (e <= 1) && (I <= 1) && (o <= 1) && (u <= 1) &&
                (suma == 4))
            {
                printf(" %s ", token);
                c++;
            }
            token = strtok(NULL, limitador);
            a     = 0;
            e     = 0;
            I     = 0;
            o     = 0;
            u     = 0;
            suma  = 0;
        }
    }

    return c;
}

// Numero de palabras que tienen vocales que se repiten
int numberOfVocalRepeatWords(char x[100])
{

    int  a = 0, e = 0, I = 0, o = 0, u = 0;
    int  c           = 0;
    char limitador[] = {" "}, aux2[100];
    strcpy(aux2, x);
    strlwr(aux2);
    char* token = strtok(aux2, limitador);

    if (token != NULL)
    {
        printf("\n\n\t Palabras: ");
        while (token != NULL)
        {

            for (i = 0; i <= strlen(token); i++)
            {

                switch (token[i])
                {
                case 'a':
                    a++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'i':
                    I++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'u':
                    u++;
                }
            }

            if ((a > 1) || (e > 1) || (I > 1) || (o > 1) || (u > 1))
            {
                printf(" %s ", token);
                c++;
            }
            token = strtok(NULL, limitador);
            a     = 0;
            e     = 0;
            I     = 0;
            o     = 0;
            u     = 0;
        }
    }

    return c;
}

// Mostrar las vocales que una cadena
void vocalInString(char x[100])
{

    int vocal = 0;
    strlwr(x);
    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal >= 1)
        {
            printf("%c", x[i]);
        }
        vocal = 0;
    }
}

// Separar las vocales de una cadena,concatenarlas y revertirlas

void divideAndConcatenateVocalsREVER(char x[100])
{

    int v = 0, vocal = 0, a = 0;

    char aux[100];

    for (i = 0; i < strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
            break;
        }

        if (vocal >= 1)
        {
            aux[v] = x[i];
            v++;
            a++;
        }
        vocal = 0;
    }
    for (i = a; i >= -1; i--)
        printf("%c", aux[i]);
}

// Mostrar palabras que inician con una vocal
void showWordStartsWithVowel(char x[100])
{

    int   vocal = 0, c = 0;
    char  limitador[] = {" "};
    char* token       = strtok(x, limitador);

    if (token != NULL)
    {

        printf("\n\n\t Palabras: ");
        while (token != NULL)
        {

            switch (token[0])
            {
            case 'a':
                printf("%s ", token);
                break;
            case 'e':
                printf("%s ", token);
                break;
            case 'i':
                printf("%s ", token);
                break;
            case 'o':
                printf("%s ", token);
                break;
            case 'u':
                printf("%s ", token);
                break;
            case 'A':
                printf("%s ", token);
                break;
            case 'E':
                printf("%s ", token);
                break;
            case 'I':
                printf("%s ", token);
                break;
            case 'O':
                printf("%s ", token);
                break;
            case 'U':
                printf("%s ", token);
            }

            token = strtok(NULL, limitador);
        }
    }
}

// Numero de palabras que inician con vocales
int WordStartsWithVowel(char x[100])
{

    int vocal = 0, c = 0;
    strlwr(x);
    char  limitador[] = {" "};
    char* token       = strtok(x, limitador);

    if (token != NULL)
    {

        while (token != NULL)
        {

            switch (token[0])
            {
            case 'a':
                c++;
                break;
            case 'e':
                c++;
                break;
            case 'i':
                c++;
                break;
            case 'o':
                c++;
                break;
            case 'u':
                c++;
            }

            token = strtok(NULL, limitador);
        }

        return c;
    }
}

// Palabras que tienen 2 vocales
void twoVocalWords(char x[100])
{

    int   a = 0, e = 0, I = 0, o = 0, u = 0;
    int   suma        = 0;
    char  limitador[] = {" "};
    char* token       = strtok(x, limitador);

    if (token != NULL)
    {
        printf("\n\n\t Palabras: ");
        while (token != NULL)
        {

            for (i = 0; i <= strlen(token); i++)
            {

                switch (token[i])
                {
                case 'a':
                    a++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'i':
                    I++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'u':
                    u++;
                }
            }

            suma = a + e + I + o + u;
            if (suma == 2)
            {
                printf(" %s ", token);
            }
            token = strtok(NULL, limitador);
            a     = 0;
            e     = 0;
            I     = 0;
            o     = 0;
            u     = 0;
            suma  = 0;
        }
    }
}

// Mostrar las consonantes en una cadena
void consonantsInString(char x[100])
{

    int vocal = 0;
    strlwr(x);
    for (i = 0; i <= strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal <= 0)
        {
            printf("%c", x[i]);
        }
        vocal = 0;
    }
}

// Convertir las vocales en asteriscos
void vocalesAsteriscos(char x[100], char y[100])
{

    int vocal = 0;
    strcpy(y, x);
    for (i = 0; i < strlen(x); i++)
    {

        switch (x[i])
        {
        case 'a':
            vocal++;
            break;
        case 'e':
            vocal++;
            break;
        case 'i':
            vocal++;
            break;
        case 'o':
            vocal++;
            break;
        case 'u':
            vocal++;
        }

        if (vocal >= 1)
        {
            y[i] = '*';
        }
        vocal = 0;
    }

    printf("%s ", y);
}
