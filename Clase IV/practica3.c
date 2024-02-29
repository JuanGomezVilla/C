#include <stdio.h>

//Valores constantes
#define CREAR_ARBOL 1
#define MOSTRAR_ARBOL 2
#define SALIR 3

//Tipos de datos
typedef long long int Int64;
typedef int Int32;
typedef short Int16;
typedef char Byte;

enum TiposArbol {
    PINO,
    HAYA,
    ROBLE,
    EUCALIPTO
};

//Estructura del arbol
struct ArbolData {
    Int64 numeroHojas;
    Int32 numeroRamas;
    Int16 numeroRaices;
    enum TiposArbol nombreArbol;
};

//Método que devuelve un arbol con datos especificados por el usuario
struct ArbolData crearArbol(){
    struct ArbolData arbolTemporal;

    //Lectura de datos de entrada por parte del usuario
    printf("\nNumero de hojas: ");
    scanf("%lli", &arbolTemporal.numeroHojas);
    printf("Numero de ramas: ");
    scanf("%i", &arbolTemporal.numeroRamas);
    printf("Numero de raices: ");
    scanf("%hu", &arbolTemporal.numeroRaices);
    printf("Nombre del arbol: ");
    scanf("%s", &arbolTemporal.nombreArbol);

    //Devuelve el árbol temporal con los valores asignados
    return arbolTemporal;
};

//Método para mostrar los datos de un árbol pasado por parámetro
void mostrarArbol(struct ArbolData arbol){
    printf("El arbol %s tiene  %i hojas, %i ramas, %i raices\n\n", arbol.nombreArbol, arbol.numeroHojas, arbol.numeroRamas, arbol.numeroRaices);
}

void main(){
    //Arbol inicial y opción por defecto a 0
    struct ArbolData arbol;
    int opcion = 0;

    //Siempre que la opción sea diferente de 3, continúa ejecutando el menú
    while(opcion != SALIR){
        //Imprime un mensaje con las opciones válidas
        printf("\n1. Crear arbol\n2. Mostrar arbol\n3. Salir\n\nOPCION: ");
        scanf("%i", &opcion);

        //Si la opción es crear el árbol (1), lo crea, y asigna el valor devuelto
        if(opcion == CREAR_ARBOL){
            arbol = crearArbol();

        //Si la opción es mostrar el árbol (2), muestra pasando por parámetro la variable árbol
        } else if(opcion == MOSTRAR_ARBOL){
            mostrarArbol(arbol);
        }
    }

    //Fin del programa
    printf("\nFin del programa");
}