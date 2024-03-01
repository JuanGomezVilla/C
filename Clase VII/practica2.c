#include <stdio.h>
#include <stdlib.h>

char *leerLineaDinamicamente(){
    //Caracter a leer por consola y la cantidad
    char caracter;
    int cantidad = 0;

    //Reserva memoria en el puntero
    char *linea = (char*) malloc((cantidad+1) * sizeof(char));

    //Para cada caracter que sea diferente del final
    while((caracter = getchar()) != '\n'){
        //Guarda en el puntero la letra e incrementa la cantidad
        linea[cantidad] = caracter;
        cantidad++;
        
        //Modifica la  memoria para un nuevo caracter
        linea = (char*) realloc(linea, cantidad * sizeof(char));
    }
    
    //Agregar un caracter nulo al final
    linea[cantidad] = '\0';

    //Devuelve la línea
    return linea;
}

void main() {
    //El usuario escribe un nombre
    printf("Introduce un nombre: ");
    char *nombre = leerLineaDinamicamente();

    //Muestra el resultado por pantalla y limpia la memoria
    printf("Nombre: %s\n", nombre);
    free(nombre);
}