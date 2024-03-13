//COMANDO: compile ejercicio1.c && ejercicio a u i

//Librerías
#include <stdio.h>
#include <stdlib.h>

//Definiciones iniciales
#define SALIR 0
#define NUEVA_FRASE 1
#define VER_RESULTADO 2

//Letras del abecedario y cantidades para cada una
char letras[]       = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int cantidades[]    = {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

//Obtener posición de letra
int obtenerPosicion(char *letra){
    //Posición de la letra por defecto
    int posicionLetra = 0;

    //Para cada letra del abecedario
    for(int i=0; i<26; i++) {
        //Si la letra coincide
        if(letras[i] == *letra){
            //Captura la posición y termina el bucle
            posicionLetra = i;
            break;
        }
    }
    //Devuelve la posición de la letra
    return posicionLetra;
}

void main(int argc, char *argv[]){
    //Valor inicial por defecto de la opción y frase
    int opcion = -1;
    char frase[40];
    char cTemporal;

    //Título del ejercicio
    printf("EJERCICIO 1\n");
   
    //Siempre que la opción sea diferente de 0 (salir) continúa la ejecución
    while(opcion != SALIR){
        //Muestra por pantalla el menú y lee una posible opción de entrada
        printf("\n----------------------------------------------------------\nPara introducir una nueva frase pulse 1\nPara mostrar el resultado pulse 2\nPara salir pulse 0\n----------------------------------------------------------\nOPCION: ");
        
        //Evita posibles bucles si el usuario pretende escribir un valor que no es válido
        char opcionPosible[40];
        scanf("%s", &opcionPosible);

        //Si el usuario escribe un valor que no es correcto, cierra el programa
        opcion = strtol(opcionPosible, NULL, 10);

        //Cuando la opción es una nueva frase
        if(opcion == NUEVA_FRASE){
            //Frase a introducir por el usuario
            printf("\nIntroduzca una frase: ");
            scanf("%c", &cTemporal);
            fgets(frase, 40, stdin); //Se utiliza para evitar errores

            //Puntero para la frase
            char *punteroFrase = frase;

            //Siempre que el puntero sea diferente del final de la frase
            while(*punteroFrase != '\0'){
                //Si el contenido del puntero en ese momento es diferente de un espacio
                if(*punteroFrase != ' ') {
                    //Para cada argumento pasado por consola, si coincide con la letra, suma en 1 la cantidad de la posición correspondiente
                    for(int i=1; i<argc; i++) if(*punteroFrase == *argv[i]) cantidades[obtenerPosicion(argv[i])]++;
                }
                //Incrementa el puntero
                punteroFrase++;
            }
        } else if(opcion == VER_RESULTADO){
            //Muestra por pantalla el resultado
            printf("\nRESULTADO:\n");

            //Recorre cada letra de los argumentos
            for(int i=1; i<argc; i++){
                //Captura una posición temporal
                int posicionTemporal = obtenerPosicion(argv[i]);

                //Imprime por pantalla el resultado
                printf("%c -> %i\n", letras[posicionTemporal], cantidades[posicionTemporal]);
            }
        }
    }
}