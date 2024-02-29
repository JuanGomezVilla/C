#include <stdio.h>

/**
 * Función para pasar únicamente el valor. El alcance de esta variable se limita solo a la función.
 * Si ese valor lo modificas dentro de la función, no afecta fuera, es decir, el valor continua siendo
 * el que es fuera.
 */
void pasarPorValor(int numero){
    numero++;
}

/**
 * Función para pasar por referencia un número. El argumento que le pasas no es el valor de "numero",
 * sino la referencia en memoria. De ese modo, la función accede al contenido de la referencia pasada
 * y suma 1, modificando el valor en memoria directamente
 */
void pasarPorReferencia(int *numero){
    (*numero)++;
}

void main(){
    //Declaración inicial de un número cualquiera
    int numero = 1;

    printf("%p\n", &numero);

    //Se muestra por consola el resultado inicial
    printf("Inicialmente, el numero es %d\n", numero);

    //Pasar por valor el número a la función y verificar si se ha aplicado la suma
    pasarPorValor(numero);
    printf("Despues de pasar el numero, el resultado es %d, es decir, no se ha modificado\n", numero);

    //Pasar por referencia el número y verificar el resultado
    pasarPorReferencia(&numero);
    printf("Despues de pasar el numero por referencia , el nuevo valor es %d, por lo tanto, se ha modificado\n", numero);

    /*
        EXPLICACIÓN:
            Cuando pasas por valor un número a una función, solo le estás pasando su valor, en este caso 1, pero no su referencia en memoria.
            Sin embargo, cuando pasas por referencia, le pasas la ubicación en memoria de esa variable, no el número en cuestión. De este
            modo, la función "pasarPorReferencia()" es capaz de modificar el valor de "numero", porque accede a la memoria a partir de su
            referencia.
    */
}