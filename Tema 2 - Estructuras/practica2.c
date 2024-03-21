#include <stdio.h>

#define INT 1
#define FLOAT 2
#define CHAR 3

//Estructura para la lectura de datos
struct LecturaDatos {
    int tipo;

    union Tipos {
        int valorInteger;
        float valorFloat;
        char valorString[4];
    } tipos;
};

void main(){
    //Declaración de una estructura para la lectura de datos
    struct LecturaDatos lectura;

    //Se imprime las opciones por pantalla y el usuario selecciona una opción
    printf("1 -> integer\n2 -> float\n3 -> char\n\n");
    printf("Selecciona una opcion: ");
    scanf("%i", &lectura.tipo);

    //Si el tipo de lectura es un valor entero
    if(lectura.tipo == INT){
        printf("Escribe un numero entero: ");
        scanf("%i", &lectura.tipos.valorInteger);
        printf("\nEl valor es %i\n", lectura.tipos.valorInteger);

    //Si el tipo de lectura es para un valor float
    } else if(lectura.tipo == FLOAT){
        printf("Escribe un valor flotante: ");
        scanf("%f", &lectura.tipos.valorFloat);
        printf("\nEl valor es %f\n", lectura.tipos.valorFloat);

    //Si el tipo de lectura es para un char de múltiples datos
    } else if(lectura.tipo == CHAR){
        printf("Escribe un valor de str[4]: ");
        scanf("%s", &lectura.tipos.valorString);
        printf("\nEl valor es %s\n", lectura.tipos.valorString);
    } else {
        //Mensaje de error ante opción fuera de rango (1-3)
        printf("\nOpcion no valida");
    }
}