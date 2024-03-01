#include <stdio.h>
#include <stdlib.h>

void main(){
    //El usuario indica la cantidad de alumnos a guardar
    int cantidadAlumnos = 0;
    printf("CANTIDAD DE ALUMNOS: ");
    scanf("%d", &cantidadAlumnos);

    //Reserva de memoria para las edades
    int* punteroEdades = (int*) malloc(cantidadAlumnos * sizeof(int));
    int* punteroCopia = (int*) malloc(cantidadAlumnos * sizeof(int));

    //El usuario escribe la edad de cada alumno
    for(int i=0; i<cantidadAlumnos; i++){
        printf("ALUMNO %i: ", i+1);
        scanf("%d", &punteroEdades[i]);
    }

    //Variables de cálculo
    int edadMaxima = 0, edadMinima;
    float total = 0;

    for(int i=0; i<cantidadAlumnos; i++){
        //Guarda temporalmente la edad
        int edad = punteroEdades[i];

        //Copiar el contenido del puntero
        punteroCopia[i] = edad;

        //Se ajusta la edad mínima inicial
        if(i == 0) edadMinima = edad;

        //Ajusta para records de edad máxima y mínima
        if(edad > edadMaxima) edadMaxima = edad;
        if(edad < edadMinima) edadMinima = edad;

        //Obtiene la media
        total += edad;
    }

    //Título de resultados
    printf("\nEDADES\n");

    //Imprimir con un bucle las edades del puntero de copia
    for(int i=0; i<cantidadAlumnos; i++) printf("   Edad de alumno %i: %i\n", i+1, punteroCopia[i]);

    //RESULTADOS
    printf("\nRESULTADOS\n   Edad m%cxima: %i\n   Edad m%cnima: %i\n   Media: %.2f\n", 160, edadMaxima, 161, edadMinima, total/cantidadAlumnos);

    //Vaciar la memoria
    free(punteroEdades);
    free(punteroCopia);
}