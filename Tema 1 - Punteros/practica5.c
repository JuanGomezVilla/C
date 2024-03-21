#include <stdio.h>
#include <stdlib.h>

/*
    Escribir un programa que reciba una matriz 3x3 de números en float
    a través de la línea de comandos y nos la presente por pantalla
*/
void main(int argc, char* argv[]){
    //Iterador y matriz de 3x3 iniciada a 0
    int iterador = 0;
    float matriz[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    //Si la cantidad de argumentos es diferente de 10
    if(argc != 10){
        //Notifica al usuario para que escriba una cantidad
        printf("Es necesario que aportes 9 numeros\n");
    } else {
        //Para cada fila de la matriz (nested loops)
        for(int y=0; y<3; y++){
            //Para cada columna de la fila
            for(int x=0; x<3; x++){
                //Ingresa el valor del tipo float con las coordenadas de los bucles
                matriz[y][x] = strtof(argv[iterador], NULL);
                //Incrementa en 1 el iterador
                iterador++;
            }
        }

        //Muestra por pantalla el resultado final
        printf("[\n");
        for(int y=0; y<3; y++) printf("    [%.2f, %.2f, %.2f]\n", matriz[y][0], matriz[y][1], matriz[y][2]);
        printf("]\n");
    }
}