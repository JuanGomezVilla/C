//COMANDO: compile ejercicio3.c && ejercicio Juan Pedro Marta Luis Silvia Rafael Daniel Carlos

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definiciones
#define CANTIDAD_PAREJAS 4
#define INTRODUCIR_RESULTADOS 1
#define MOSTRAR_RESULTADOS 2
#define MOSTRAR_GANADOR 3
#define SALIR 4

//ESTRUCTURAS

//Pareja de jugadores
struct Pareja {
    int identificador;
    char jugador1[40];
    char jugador2[40];
    int puntos;
    int setsFavor;
    int setsContra;
    int puntosTrasEmpate;
};

//Estructura de un hipotético partido
struct Partido {
    struct Pareja pareja1;
    struct Pareja pareja2;
    int puntosPareja1;
    int puntosPareja2;
};

//Estructura de una jornada
struct Jornada {
    struct Partido partidos[2];
};

//Listado de parejas
struct Pareja parejas[CANTIDAD_PAREJAS];
struct Jornada jornadas[3];
int jornadaActual = 0, partidoActual = 0;

//Método para capturar el input del usuario
void getText(char *variable){
    fgets(variable, sizeof(char) * sizeof(variable), stdin);
    sscanf(variable, "%[^\n]", variable);
}

void main(int argc, char *argv[]){
    //Comprueba que la cantidad de personas es válida
    if(argc != (CANTIDAD_PAREJAS * 2 + 1)){
        //Muestra un mensaje de error, y finaliza el programa
        printf("Especifica %i parejas, es decir, %i personas en total (2 personas por pareja)\n", CANTIDAD_PAREJAS, CANTIDAD_PAREJAS*2);
        return;
    }

    //Verificar que no hay nombres repetidos directamente sobre los argumentos
    for(int i=1; i<argc; i++){
        //Bucle anidado para comprobar sobre el siguiente valor
        for(int j=i+1; j<argc; j++){
            //Si ambos valores son iguales
            if(strcmp(argv[i], argv[j]) == 0){
                //Muestra un mensaje de error
                printf("El nombre \"%s\" est%c repetido...\n", argv[i], 160);
                return;
            }
        }
    }

    //Recorre cada argumento empezando por 1, y con un orden para cada pareja
    //Al ser parejas de 2, aumenta de 2 en 2, pero el orden de cada pareja lo hace por 1
    for(int i=1, ordenPareja = 0; i<argc; i+=2, ordenPareja++){
        //Crea una pareja temporal, e inserta los nombres
        struct Pareja parejaTemporal;
        strcpy(parejaTemporal.jugador1, argv[i]);
        strcpy(parejaTemporal.jugador2, argv[i+1]);
        parejaTemporal.puntos = 0;
        parejaTemporal.identificador = ordenPareja;
        parejaTemporal.setsContra = 0;
        parejaTemporal.setsFavor = 0;
        parejaTemporal.puntosTrasEmpate = 0;

        //Inserta en el array la pareja temporal
        parejas[ordenPareja] = parejaTemporal;
    }

    //Definir los partidos
    struct Partido partido1Jornada1;
    struct Partido partido2Jornada1;
    struct Partido partido1Jornada2;
    struct Partido partido2Jornada2;
    struct Partido partido1Jornada3;
    struct Partido partido2Jornada3;
    
    //Definir los equipos de los partidos
    //JORNADA 1
    partido1Jornada1.pareja1 = parejas[0];
    partido1Jornada1.pareja2 = parejas[1];
    partido2Jornada1.pareja1 = parejas[2];
    partido2Jornada1.pareja2 = parejas[3];
    //JORNADA 2
    partido1Jornada2.pareja1 = parejas[0];
    partido1Jornada2.pareja2 = parejas[2];
    partido2Jornada2.pareja1 = parejas[3];
    partido2Jornada2.pareja2 = parejas[1];
    //JORNADA 3
    partido1Jornada3.pareja1 = parejas[0];
    partido1Jornada3.pareja2 = parejas[3];
    partido2Jornada3.pareja1 = parejas[1];
    partido2Jornada3.pareja2 = parejas[2];


    //Definir las jornadas
    struct Jornada jornada1;
    struct Jornada jornada2;
    struct Jornada jornada3;

    //Definir los partidos de cada jornada
    //JORNADA 1
    jornada1.partidos[0] = partido1Jornada1;
    jornada1.partidos[1] = partido2Jornada1;
    //JORNADA 2
    jornada2.partidos[0] = partido1Jornada2;
    jornada2.partidos[1] = partido2Jornada2;
    //JORNADA 3
    jornada3.partidos[0] = partido1Jornada3;
    jornada3.partidos[1] = partido2Jornada3;

    //Guardar las jornadas
    jornadas[0] = jornada1;
    jornadas[1] = jornada2;
    jornadas[2] = jornada3;

    //Opción por defecto y jornadas realizadas
    int opcion = -1;

    //Menú de opciones
    while(opcion != SALIR){
        //Mensaje por pantalla con las opciones
        printf("\n1. Introducir resultados\n2. Mostrar resultados\n3. Obtener ganador\n4. Salir\nOPCI%cN: ", 224);

        //El usuario escribe una opción por pantalla, evitando posibles valores incorrectos
        char opcionPosible[40];
        getText(opcionPosible);
        opcion = strtol(opcionPosible, NULL, 10);

        //Si la opción elegida es introducir resultados
        if(opcion == INTRODUCIR_RESULTADOS){
            //Comprueba que se han completado todas las jornadas
            if(jornadaActual == 3){
                printf("\nNo puedes introducir m%cs de 3 jornadas\n", 160);
            } else {
                //Muestra el título de la jornada
                printf("\nResultado de la jornada %i:\n", jornadaActual + 1);

                //Bucle para los dos partidos
                for(int i=0; i<2; i++){
                    //Se obtiene la ubicación de las parejas que tocan en ese momento
                    struct Pareja pareja1 = jornadas[jornadaActual].partidos[i].pareja1;
                    struct Pareja pareja2 = jornadas[jornadaActual].partidos[i].pareja2;

                    //Se imprime por pantalla los nombres y el usuario escribe un valor
                    printf("   %s-%s -- %s-%s: ", pareja1.jugador1, pareja1.jugador2, pareja2.jugador1, pareja2.jugador2);
                    
                    //Obtiene el input del usuario
                    char puntuacion[20];
                    getText(puntuacion);

                    //Guarda los resultados en un partido temporal
                    jornadas[jornadaActual].partidos[i].puntosPareja1 = puntuacion[0] - '0';
                    jornadas[jornadaActual].partidos[i].puntosPareja2 = puntuacion[2] - '0';

                    //Guarda los resultados y avanza el iterador de partido actual
                    partidoActual++;
                }
                jornadaActual++;
            }
        } else if(opcion == MOSTRAR_RESULTADOS){
            //Comprobar el partido actual, muestra el título por pantalla si hay partidos
            if(partidoActual == 0) printf("\nActualmente no se han jugado partidos...\n");
            else printf("\nRESULTADOS:\n");

            //Iterador para todas las jornadas realizadas
            for(int i=0; i<jornadaActual; i++){
                //Iterador para cada partido
                for(int j=0; j<2; j++){
                    struct Partido partidoTemporal = jornadas[i].partidos[j];
                    printf("   %s-%s -- %s-%s: %i %i\n",
                        partidoTemporal.pareja1.jugador1, 
                        partidoTemporal.pareja1.jugador2,
                        partidoTemporal.pareja2.jugador1, 
                        partidoTemporal.pareja2.jugador2,
                        partidoTemporal.puntosPareja1,
                        partidoTemporal.puntosPareja2
                    );
                }
            }
        } else if(opcion == MOSTRAR_GANADOR){
            //Si se han jugado tres jornadas en total
            if(jornadaActual == 3){
                printf("\nGANADORES\n");

                //Primero se obtiene el record
                for(int i=0; i<3; i++){
                    //Bucle para cada partido dentro de cada jornada
                    for(int j=0; j<2; j++){
                        struct Partido partidoTemporal = jornadas[i].partidos[j];
                        if(partidoTemporal.puntosPareja1 < partidoTemporal.puntosPareja2){
                            parejas[partidoTemporal.pareja2.identificador].puntos += 1;

                            //A la pareja 2 (que ha ganado), se indican los sets a favor, y el contrario con la pareja 1
                            parejas[partidoTemporal.pareja2.identificador].setsFavor += partidoTemporal.puntosPareja2;
                            parejas[partidoTemporal.pareja1.identificador].setsContra += partidoTemporal.puntosPareja1;

                        } else if(partidoTemporal.puntosPareja1 > partidoTemporal.puntosPareja2){
                            parejas[partidoTemporal.pareja1.identificador].puntos += 1;

                            //A la pareja 1 (que ha ganado), se indican los sets a favor, y el contrario con la pareja 2
                            parejas[partidoTemporal.pareja1.identificador].setsFavor += partidoTemporal.puntosPareja1;
                            parejas[partidoTemporal.pareja2.identificador].setsContra += partidoTemporal.puntosPareja2;
                        }
                    }
                }

                //Obtención del record
                int record = 0;
                int recordTrasEmpate = 0;
                for(int i=0; i<4; i++) if(record < parejas[i].puntos) record = parejas[i].puntos;

                //Para todas aquellas parejas que tengan empate
                for(int i=0; i<4; i++) if(parejas[i].puntos == record) parejas[i].puntosTrasEmpate = parejas[i].setsFavor - parejas[i].setsContra;

                //Comprobación del record tras empate
                for(int i=0; i<4; i++) if(parejas[i].puntos == record && recordTrasEmpate < parejas[i].puntosTrasEmpate) recordTrasEmpate = parejas[i].puntosTrasEmpate;

                //Muestra todos los usuarios que han llegado al record y tienen el record tras empate
                for(int i=0; i<4; i++){
                    if(parejas[i].puntos == record && recordTrasEmpate == parejas[i].puntosTrasEmpate){
                        printf("   %s-%s (favor->%i, contra->%i, puntos->%i)\n", parejas[i].jugador1, parejas[i].jugador2, parejas[i].setsFavor, parejas[i].setsContra, parejas[i].puntos);
                    }
                }
            } else {
                //Mensaje de error
                printf("\nTodav%ca no se han jugado 3 jornadas...\n", 161);
            }
        }
    }
}