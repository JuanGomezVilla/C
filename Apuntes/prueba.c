#include <stdio.h>

void main(){
    //Creación de dos punteros
    char *puntero1, *puntero2;

    //Creación de una cadena y se pasa al puntero 1
    char cadena[] = "Hasta luego";
    puntero1 = cadena;

    //El puntero 2 recibe la posición de memoria de la cadena en la ubicación 6
    puntero2 = &cadena[6];

    //Accede a la letra "e" a partir del puntero
    printf("%c\n", *(puntero2 + 2));
}