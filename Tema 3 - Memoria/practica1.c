//COMANDO: run practica1

//Librerías
#include <stdio.h>
#include <stdlib.h>

//Definiciones
#define CANTIDAD_NUMEROS 10

void main(){
    //Creación de un puntero para la posición de memoria
    int* punteroEnteros = (int*) malloc(CANTIDAD_NUMEROS * sizeof(int));

    //Comprobación de que se ha reservado la memoria
    if(punteroEnteros == NULL){
        printf("No se ha podido reservar memoria\n");
    } else {
        //El usuario va escribiendo tantos números como sean necesarios
        for(int i=0; i<CANTIDAD_NUMEROS; i++) {
            //Prompt y ubica el valor en la memoria
            printf("NUMERO %d: ", i+1);
            scanf("%d", &punteroEnteros[i]);
        }

        //Listar los números separados por coma
        printf("%i", punteroEnteros[0]);
        for(int i=1; i<CANTIDAD_NUMEROS; i++) printf(", %i", punteroEnteros[i]);

        //Limpieza de la memoria
        free(punteroEnteros);
    }
}