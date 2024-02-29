#include <stdio.h>

void main(){
    //Declaración de variables, de la cadena de origen y el destino
    char cadena1[] = "Juan Gomez";
    char cadena2[50];

    //Declaración de punteros a partir de las variables
    char *puntero1 = cadena1;
    char *puntero2 = cadena2;

    //Tomando como puntero la cadena
    //Siempre que la posición del puntero tenga de valor diferente de \0
    while(*puntero1 != '\0'){
        //Tomamos el valor primero de la cadena 1 y lo pasamos a 2
        *puntero2 = *puntero1;

        //Aumentamos el puntero
        puntero1++;
        puntero2++;
    }

    //Imprimir los resultados
    printf("CADENA 1: %s\n", cadena1);
    printf("CADENA 2: %s\n", cadena2);
}