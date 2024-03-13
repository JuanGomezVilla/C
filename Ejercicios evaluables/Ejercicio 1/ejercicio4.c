//COMANDO: run ejercicio4.c

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definiciones iniciales
//Materiales
#define PLASTICO 0
#define CRISTAL 1
#define MADERA 2
#define METAL 3

//Opciones
#define NUEVA_MESA 1
#define MOSTRAR_MESAS 2
#define CALCULAR_PEDIDO 3
#define SALIR 4

//Estructura de una mesa
struct Mesa {
    int ancho;
    int alto;
    int fondo;
    int material;
    float precio;
};

//Método para devolver un tipo de material
char* obtenerMaterial(int tipoMaterial){
    //Se analiza con un switch el tipo de material
    switch(tipoMaterial){
        case PLASTICO:
            return "plastico";
        case CRISTAL:
            return "cristal";
        case MADERA:
            return "madera";
        case METAL:
            return "metal";
        default:
            break;
    }
    /*
        No se utiliza el default del switch para devolver, a modo de 
        nomenclatura se asegura que siempre se devuelve un valor
    */
    return "desconocido";
}

void main(){
    //Opción por defecto, listado con las mesas, y cantidad de mesas
    int opcion = -1;
    struct Mesa mesas[100];
    int lengthMesas = 0;
    
    //Título del ejercicio
    printf("EJERCICIO 4\n");

    //Si la opción es diferente de salir
    while(opcion != SALIR){
        //Imprime el menú
        printf("\n1. Introducir caracter%csticas de una nueva mesa\n2. Mostrar las mesas disponibles\n3. Calcular precio de pedido\n4. Salir\nOPCI%cN: ", 161, 224);
        
        //Evita posibles números nulos
        char opcionPosible[40];
        scanf("%s", &opcionPosible);
        opcion = strtol(opcionPosible, NULL, 10);

        //Si la opción es crear una mesa
        if(opcion == NUEVA_MESA){
            //Comprueba si ha llegado al límite de mesas disponibles
            if(lengthMesas == 100){
                printf("No puedes crear otra mesa porque has alcanzado el l%cmite permitido...\n", 161);
            } else {
                //Crea la estructura de una mesa temporal y el usuario escribe los datos
                struct Mesa mesaTemporal;
                printf("\nAncho: ");
                scanf("%i", &mesaTemporal.ancho);
                printf("Alto: ");
                scanf("%i", &mesaTemporal.alto);
                printf("Fondo: ");
                scanf("%i", &mesaTemporal.fondo);
                printf("Tipo [pl%cstico (0) | crital (1) | madera (2) | metal (3)]: ", 160);
                scanf("%i", &mesaTemporal.material);
                printf("Precio: ");
                scanf("%f", &mesaTemporal.precio);
                
                //Se añade la mesa temporal al listado y se incrementa por 1 la cantidad
                mesas[lengthMesas] = mesaTemporal;
                lengthMesas++;
            }
        
        //Si la opción es mostrar todas las mesas
        } else if(opcion == MOSTRAR_MESAS){
            printf("\nMESAS GUARDADAS\n");

            //Comprueba si existen mesas y lo notifica al usuario
            if(lengthMesas == 0) printf("   No hay mesas guardadas...\n");

            //Recorre el array de mesas sabiendo la cantidad
            for(int i=0; i<lengthMesas; i++){
                //Crea una mesa temporal a partir del iterador sobre la lista
                struct Mesa mesaTemporal = mesas[i];
                //Imprime el resultado
                printf("   Mesa %i -> Ancho:%i, alto:%i, fondo:%i, material:%s, precio:%f\n", i+1, mesaTemporal.ancho, mesaTemporal.alto, mesaTemporal.fondo, obtenerMaterial(mesaTemporal.material), mesaTemporal.precio);
            }
        
        //Cantidad de mesas
        } else if(opcion == CALCULAR_PEDIDO){
            //Comprueba si existen mesas y lo notifica al usuario
            if(lengthMesas == 0){
                printf("   No hay mesas guardadas...\n");
            } else {
                //El usuario escribe los índices separados por comas
                printf("Escribe los %cndices separados por comas: ", 161);
                char mesasIndices[20];
                scanf("%s", mesasIndices);

                //Crea un array para los índices
                int indices[5];
                int ordenIndices = 0;

                //Separa por una coma el argumento y va comprobando cada valor
                char *parte = strtok(mesasIndices, ",");

                //Agrega el primer índice
                indices[ordenIndices] = strtol(parte, NULL, 10);
                
                //Recorre cada parte separada por una coma
                while(parte != NULL){
                    //Incrementa en 1 el orden de índices
                    ordenIndices++;
                    parte = strtok(NULL, ",");
                    //Si la parte es diferente de NULL
                    if(parte != NULL) indices[ordenIndices] = strtol(parte, NULL, 10);
                }

                //Teniendo los índices, se calcula el precio total
                float precioTotal = 0;
                for(int i=0; i<ordenIndices; i++) precioTotal += mesas[indices[i]].precio;

                //Se imprime por pantalla el precio final
                printf("\nPrecio total: %f\n", precioTotal);
            }
        }
    }
}