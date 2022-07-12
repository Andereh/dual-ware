#include "modules.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int opt;

    do
    {
        system("clear");
        printf("\n\t\tMENU\n\n");
        printf("Elija una de las siguientes opciones: \n");
        printf("\n\t1.  Promedio de notas");
        printf("\n\t2.  Determinar numero real");
        printf("\n\t3.  Ecuacion cuadratica");
        printf("\n\t4.  Sueldo de un empleado");
        printf("\n\t5.  Operar con tres numeros");
        printf("\n\t6.  Calcular ley de OHM");
        printf("\n\t7.  Operar con dos numeros");
        printf("\n\t8.  Area y perimetro de un circulo");
        printf("\n\t9.  Area de figuras geometricas");
        printf("\n\t10. Promedio y suma de los primeros 20 numeros");
        printf("\n\t11. Suma de pares e impares");
        printf("\n\t12. Cuadrado y cubo de los primeros 15 numeros");
        printf("\n\t13. Siete numeros");
        printf("\n\t14. Menu de bocadillos");
        printf("\n\t15. Pares entre 20 y 40");
        printf("\n\t16. Conversor de grados Farenheit");
        printf("\n\t17. Mostrar la suma de los multiplos de 5");
        printf("\n\t18. Determinar los numeros multiplos 3, desde 1 hasta n");
        printf("\n\t19. Hacer una factura");
        printf("\n\t20. Calcular el promedio de n numeros");
        printf("\n\t21. Medir corriente");
        printf("\n\t22. Calcular corriente");
        printf("\n\t23. Hacer factura de luz");
        printf("\n\t24. Mostrar todos los numeros pares entre 1-100");
        printf("\n\t25. Numeros decrecientes desde el 30");
        printf("\n\t26. Determinar el rango de un numero ");
        printf("\n\t27. Hacer una inversion");
        printf("\n\t28. Hospital");
        printf("\n\t29. Medir pulsaciones");
        printf("\n\t30. Calcular el minimo de un vector de 10 numeros, y "
               "mostrar su posicion ");
        printf("\n\t31. Suma de impares menores que m");
        printf("\n\t32. Suma de los numeros pares, impares y naturales");

        printf("\n\n\tOtro. salir\n");

        printf("\nOpcion: ");
        opt = validInt();

        switch (opt)
        {
        case 1:
            promedioNotas();
            break;
        case 2:
            realNum();
            break;
        case 3:
            ecuacionCuadratica();
            break;
        case 4:
            salario();
            break;
        case 5:
            tresNumeros();
            break;
        case 6:
            leyOHM();
            break;
        case 7:
            dosNumeros();
            break;
        case 8:
            circulo();
            break;
        case 9:
            areaDeFiguras();
            break;
        case 10:
            sumaProm20();
            break;
        case 11:
            sumaParesImpares();
            break;
        case 12:
            cuadradoCubo();
            break;
        case 13:
            sieteNumeros();
            break;
        case 14:
            menucomia();
            break;
        case 15:
            paresEntre20y40();
            break;
        case 16:
            convertor();
            break;
        case 17:
            multiplosDe5();
            break;
        case 18:
            multiplos3();
            break;
        case 19:
            hacerUnaFactura();
            break;
        case 20:
            promedioN();
            break;
        case 21:
            resistencias();
            break;
        case 22:
            voltaje();
            break;
        case 23:
            facturaDeLuz();
            break;
        case 24:
            numerospar100();
            break;
        case 25:
            numerosInvertidos();
            break;
        case 26:
            numero1_100();
            break;
        case 27:
            invertirCapital();
            break;
        case 28:
            hospital();
            break;
        case 29:
            pulsaciones();
            break;
        case 30:
            minimoVector();
            break;
        case 31:
            sumaImpares();
            break;
        case 32:
            sumaCIP();
        }

    } while (opt >= 1 && opt <= 32);

    printf("Gracias por visitarnos :3\n");

    /******************************************************************************
     * File:             principal.c
     *
     * Authors:          Ronald Hernandez y Jose Flores
     * Created:          06/29/22
     *
     * Description:      Primera evaluacion. Trimestre 2.
     *					Estamos orgullosos de nosotros mismos
     *****************************************************************************/

    return 0;
}
