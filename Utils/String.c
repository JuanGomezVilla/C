#include <stdio.h>
#include <stdlib.h>

/*
    Método para copiar una cadena en un string
    Similar al funcionamiento de strcpy
*/
void copiarString(char *punteroString, char *punteroValor){
    //Siempre que el contenido del puntero del valor sea diferente del final
    while(*punteroValor != '\0'){
        //Inserta en el puntero el valor del otro puntero
        *punteroString = *punteroValor;

        //Incrementa ambos punteros
        punteroString++;
        punteroValor++;
    }

    //Añade un final de línea
    *punteroString = '\0';
}

/*
    Método para comprobar dos strings
    Similar al funcionamiento de strcmp
*/
int compararStrings(char *punteroString1, char *punteroString2){
    //Bucle que se repetirá hasta llegar al carácter del último puntero
    while(*punteroString1 != '\0' || *punteroString2 != '\0'){
        //Si el contenido de ambos punteros es diferente, devuelve 0
        if(*punteroString1 != *punteroString2) return 0;

        //Incrementa ambos punteros
        punteroString1++;
        punteroString2++;
    }

    //Devuelve 1 porque ambos valores son correctos
    return 1;   
}

//Estructura para una persona
struct Persona {
    char nombre[10];
    int edad;
};

void main(){
    //Personas
    struct Persona persona1;
    struct Persona persona2;

    //Datos de la persona 2
    copiarString(persona1.nombre, "Fulanito");
    persona1.edad = 99;

    //Datos de la persona 1
    copiarString(persona2.nombre, "Menganito");
    persona2.edad = 0;

    //Resultados
    printf("NOMBRE: %s, EDAD: %i\n", persona1.nombre, persona1.edad);
    printf("NOMBRE: %s, EDAD: %i\n", persona2.nombre, persona2.edad);

    //Los nombres coinciden
    if(compararStrings(persona1.nombre, persona2.nombre)) printf("Los nombres coinciden\n");
}