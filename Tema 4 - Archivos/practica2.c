#include <stdio.h>

void main(){
    //Creación de un archivo
    FILE *archivo = fopen("abecedario.txt", "w");

    //Definición de letras
    char* letras = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

    //Avanzar hasta 52 letras de 2 en 2
    for(int i=0; i<52; i += 2){
        //Añade la primera letra (minúscula) y avanza el puntero
        fputc(*letras, archivo);
        letras++;

        //Añade la letra mayúscula y avanza el puntero
        fputc(*letras, archivo);
        letras++;

        //Añade un ; y un salto de línea
        fputc(';', archivo);
        fputc('\n', archivo);
    }

    //Cierra el archivo
    fclose(archivo);
}