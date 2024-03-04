# Programación 2 - UTAD


## Partes
1. Clase I - Punteros y bucles
2. Clase II - Argumentos por CLI
3. Clase III - Depuración de código


<br><div id="punto2"></div>

## Compilación y ejecución
- Compilación del código:
    ```bash
    compile filename.c 
    ```
    > El archivo resultante es un ejecutable de nombre _ejercicio.exe_
- Compilación y ejecución del código:
    ```bash
    run filename.c
    ```
    > El programa compilará el código y luego lo ejecutará


## Alternativas de string.h
- Alternativa para _strcpy_:
    ```c
    void copiarString(char *punteroString, char *punteroValor){
        while(*punteroValor != '\0'){
            *punteroString = *punteroValor;
            punteroString++;
            punteroValor++;
        }
        *punteroString = '\0';
    }

    //...

    copiarString(persona1.nombre, "Fulanito");
    ```
- Alternativa para _strcmp_:
    ```c
    int compararStrings(char *punteroString1, char *punteroString2){
        while(*punteroString1 != '\0' || *punteroString2 != '\0'){
            if(*punteroString1 != *punteroString2) return 0;
            punteroString1++;
            punteroString2++;
        }
        return 1;   
    }

    //...
    
    if(compararStrings(persona1.nombre, "Fulanito")) printf("Los nombres coinciden\n");
    ```