//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readString(char *variable){
    fgets(variable, sizeof(char) * sizeof(variable), stdin);
    sscanf(variable, "%[^\n]", variable);
}

int readInteger(){
    int number;
    scanf("%d", &number);
    return number;
}


void main(){
    printf("Escribe tu edad: ");
    int edad = readInteger();

    printf("Las iniciales son %i\n", edad);

}