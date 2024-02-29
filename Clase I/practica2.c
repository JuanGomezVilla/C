#include <stdio.h>

int getLengthChar(char cadena[]){
    //Declara un puntero para la cadena
    char *punteroCadena = cadena;
    int longitud = 0;

    //Obtención de la lontigud de la cadena
    while(*punteroCadena != '\0'){
        longitud++;
        punteroCadena++;
    }

    //Devuelve la longitud
    return longitud;
}

void main(){
    //Declaración de cadena normal
    char cadena[] = "Juan Gomez";
    int longitud = getLengthChar(cadena);

    //Iniciamos dos punteros, uno desde el inicio, y otro desde el final
    char *punteroIzquierda = cadena;
    char *punteroDerecha = cadena + longitud - 1;
    
    //Siempre que el puntero de la izquierda sea inferior al de la derecha
    while(punteroIzquierda < punteroDerecha) {
        //Capturamos el primer valor desde la izquierda
        char valorTemporal = *punteroIzquierda;

        //Al valor del puntero de la izquierda le voy a asignar al de la derecha
        *punteroIzquierda = *punteroDerecha;

        //El valor de la derecha le guardo el valor temporal
        *punteroDerecha = valorTemporal;
        
        //Después avanzamos el puntero de la izquierda y reducimos el de la derecha
        punteroIzquierda++;
        punteroDerecha--;
    }
    
    //RESULTADO FINAL
    printf("CADENA INVERTIDA: %s\n", cadena);

}