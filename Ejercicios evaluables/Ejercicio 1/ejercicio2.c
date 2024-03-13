//COMANDO: compile ejercicio2.c && ejercicio Espartaco,20,espada Marcus,10,lanza

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definiciones iniciales
#define JUGADOR 1
#define CPU 2
#define ATACAR 1
#define DEFENDER 2

//Estructura del tipo Gladiador
struct Gladiador {
    char nombre[10]; //Nombre
    char arma[10]; //Arma
    int fuerza; //Fuerza
    int salud; //Salud
};

void main(int argc, char *argv[]){
    //Creación de un jugador y la CPU
    struct Gladiador jugador, cpu;

    //Asignación de vida inicial
    jugador.salud = 100;
    cpu.salud = 100;

    //Lectura de datos por consola
    for(int jugadorActual=1; jugadorActual<argc; jugadorActual++){
        //Captura el argumento y crea un orden para cada parámetro
        char *argumentoTemporal = argv[jugadorActual];
        int ordenTemporal = 0;
        
        //Separa por una coma el argumento y va comprobando cada valor
        char *parte = strtok(argumentoTemporal, ",");
        while(parte != NULL){
            //El primer argumento pertenece al jugador
            if(jugadorActual == JUGADOR){
                //Asigna los valores al jugador
                if(ordenTemporal == 0) strcpy(jugador.nombre, parte);
                else if(ordenTemporal == 1) jugador.fuerza = strtol(parte, NULL, 10);
                else strcpy(jugador.arma, parte);
            
            //El segundo argumento pertenece a la CPU
            } else if(jugadorActual == CPU) {
                //Asigna los valores a la CPU
                if(ordenTemporal == 0) strcpy(cpu.nombre, parte);
                else if(ordenTemporal == 1) cpu.fuerza = strtol(parte, NULL, 10);
                else strcpy(cpu.arma, parte);
            }

            //Actualiza comprobando posibles comas, y posteriormente incrementa el orden temporal
            parte = strtok(NULL, ",");
            ordenTemporal++;
        }        
    }

    //Opción de acción del usuario
    int accionJugador, accionCPU;

    //Siempre que la salud de ambos sea superior a 0, el juego continúa 
    while(cpu.salud > 0 && jugador.salud > 0){
        //Vida de los personajes
        printf("\n%s (jugador) -> %i de vida\n%s (CPU) -> %i de vida\n", jugador.nombre, jugador.salud, cpu.nombre, cpu.salud);

        //Genera una acción aleatoria a realizar en el turno del jugador
        srand(time(NULL));
        accionCPU = rand() % 2 + 1;

        //TURNO DEL JUGADOR
        printf("\nTurno de %s\n   1. Atacar\n   2. Defender\n   OPCI%cN: ", jugador.nombre, 224);
        scanf("%i", &accionJugador);

        //Si la opción es ATACAR
        if(accionJugador == ATACAR){
            //Comprueba si la CPU no se defiende
            if(accionCPU != DEFENDER){
                //Obtiene una cantidad de dolor a infligir, dependiendo del tipo de arma
                int dolorCausado = 0;
                if(strcmp(jugador.arma, "espada") == 0) dolorCausado = jugador.fuerza;
                else if(strcmp(jugador.arma, "lanza") == 0) dolorCausado = jugador.fuerza * 2;

                //Aplicar el dolor sobre la CPU
                cpu.salud -= dolorCausado;

                //Imprimir la acción por pantalla
                printf("   Atacaste a %s con %s y le causaste %i de da%co\n", cpu.nombre, jugador.arma, dolorCausado, 164);
            } else {
                //Si la CPU se defiende
                printf("   Atacaste a %s con %s, pero se ha defendido, 0 de da%co causado\n", cpu.nombre, jugador.arma, 164);
            }
            
        } else if(accionJugador == DEFENDER){
            //La acción del jugador es defenderse para el próximo ataque
            accionJugador = DEFENDER;
        }

        //Turno de la CPU
        printf("\nTurno de %s", cpu.nombre);

        //Genera una acción a realizar en el turno de la CPU
        srand(time(NULL));
        accionCPU = rand() % 2 + 1;
        
        //Si la acción de la CPU es atacar
        if(accionCPU == ATACAR){
            //Comprueba si el usuario no decidió defenderse en su turno
            if(accionJugador != DEFENDER){
                //Calcula el dolor a causar y lo aplica sobre el jugador
                int dolorCausar = 0;
                if(strcmp(cpu.arma, "espada") == 0) dolorCausar = cpu.fuerza;
                else if(strcmp(cpu.arma, "lanza") == 0) dolorCausar = cpu.fuerza * 2;

                //Reduce la salud del jugador
                jugador.salud -= dolorCausar;

                //Imprimir la acción por pantalla
                printf("\n   %s atac%c a %s con %s y te caus%c %i de da%co\n", cpu.nombre, 162, jugador.nombre, cpu.arma, 162, dolorCausar, 164);
            } else {
                //Mensaje de que el jugador se ha defendido
                printf("\n   %s atac%c con %s a %s, pero se ha defendido, 0 da%co aplicado\n", cpu.nombre, 162, cpu.arma, jugador.nombre, 164);
            }
        } else {
            printf("\n   %s se ha defendido, cambio de turno\n", cpu.nombre);
        }
    }

    //Muestra el resultado final
    if(cpu.salud > 0) printf("\nHa ganado la CPU!\nNombre: %s\nTipo de arma: %s\nFuerza: %i\nSalud: %i\n", cpu.nombre, cpu.arma, cpu.fuerza, cpu.salud);
    else printf("\nHas ganado la batalla!\nNombre: %s\nTipo de arma: %s\nFuerza: %i\nSalud: %i\n", jugador.nombre, jugador.arma, jugador.fuerza, jugador.salud);
}