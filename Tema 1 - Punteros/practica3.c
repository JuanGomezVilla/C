#include <stdio.h>

//EJECUTAR POR CLI: compile ejercicio1.c && ejercicio argumento1 argumento2

void main(int argc, char* argv[]){
    //Omite el primer argumento, que sería el nombre del archivo
    //Se repite tantas veces como argumentos hay en la línea de comandos
    for(int i=1; i<argc; i++){
        //Imprime el valor aplicando un salto de línea y utilizando el iterador
        printf("%s\n", argv[i]);
    }
}