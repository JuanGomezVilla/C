#include <stdio.h>
#include <stdlib.h>

//Calcular la media de unos números pasados por la línea de comandos
void main(int argc, char* argv[]){
    //El valor inicial del total es 0, y un numero temporal posible para el bucle
    int total = 0, numeroTemporal = 0, cantidadReal = 0;

    //Si hay más de un argumento, puede haber números para realizar la operación
    if(argc > 1){
        //Para cada valor del argumento, saltando el nombre del archivo
        //Convertir cada valor a entero y sumarlo
        for(int i=1; i<argc; i++){
            //Guarda el número temporal en una variable
            numeroTemporal = strtol(argv[i], NULL, 10);

            //strtol devuelve 0 si el valor a convertir no es un número
            //Si el número temporal es diferente de 0 o el valor escrito es un 0
            if(numeroTemporal != 0 || *argv[i] == '0'){
                //Aumenta en 1 la cantidad real y añade el número temporal al total
                cantidadReal++;
                total += numeroTemporal;
            }
        }
    }

    //Realizar la media sobre el total
    total /= cantidadReal;

    //Resultado final
    printf("MEDIA: %d\n", total);
}