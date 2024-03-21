#include <stdio.h>

void main(){
    //Creación de un archivo y apertura en modo lectura
    FILE *archivo = fopen("prueba.txt", "w");

    //Comprueba si el archivo se ha abierto correctamente
    if(archivo == NULL){
        //Mensaje de error
        printf("El archivo no puede abrirse...\n");
        return;
    } else {
        //Mensaje de éxito
        printf("El archivo se ha abierto correctamente...\n");
    }

    //Escritura dentro del archivo
    fputs("Texto inicial", archivo);

    //Cierra el archivo
    fclose(archivo);
}