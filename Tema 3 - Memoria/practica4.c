#include <stdio.h>
#include <stdlib.h>

//Variables globales
int c, d;

void main(int argc, char* argv[]){
    //Variables locales
    int a, b;

    //Puntero con memoria
    int *puntero = (int*) malloc(sizeof(int) * 1000);

    //%p imprime la dirección de memoria como si fuera un puntero
    printf("Global 1    -> %p\n", &c);
    printf("Global 2    -> %p\n", &d);
    printf("Cabecera 1  -> %p\n", &argc);
    printf("Cabecera 2  -> %p\n", &argv);
    printf("Local 1     -> %p\n", &a);
    printf("Local 2     -> %p\n", &b);
    printf("malloc      -> %p\n", &puntero);
}