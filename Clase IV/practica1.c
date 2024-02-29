#include <stdio.h>
#include <string.h>

union DatosUnion {
    int edad;
    float peso;
    char nombre[10];
};

struct DatosStruct {
    int edad;
    float peso;
    char nombre[10];
};

void main(){
    //Creación de una unión y una estructura
    union DatosUnion datosU;
    struct DatosStruct datosS;

    //Asignación de datos para la unión
    datosU.edad = 99;
    datosU.peso = 3.81;
    strcpy(datosU.nombre, "Fulano");

    //Asignación de datos para la estructura
    datosS.edad = 99;
    datosS.peso = 3.81;
    strcpy(datosS.nombre, "Fulano");

    //RESULTADO FINAL
    printf("%s pesa %f y su edad es %i\n", datosU.nombre, datosU.peso, datosU.edad);
    printf("%s pesa %2f y su edad es %i\n", datosS.nombre, datosS.peso, datosS.edad);
}