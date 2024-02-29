# Depurar código

## Índice
1. [Escribir breakpoints](#punto1)
2. [Proceso de depuración](#punto2)
3. [Anotaciones](#punto3)



<br><div id="punto1"></div>

## 1. Escribir breakpoints

1. Tras ejecutar la compilación y el depurador, escribe:
    ```bash
    break NUMERO_LINEA
    ```
2. Posteriormente, escribe _run_ para iniciar la ejecución de código:
    ```bash
    run
    ```
3. Para eliminar los breakpoints, ejecuta:
    ```bash
    clear
    ```
4. Cuando el código se detiene y quieres continuar con la ejecución, escribe:
    ```bash
    continue
    ```
5. Imprimir el valor de una variable en un break determinado:
    ```bash
    print NOMBRE_DE_VARIABLE
    ```



<br><div id="punto2"></div>

## 2. Proceso de depuración
1. Abrir la línea de comandos y acceder a la carpeta del archivo:
    ```bash
    cd SUSITUIR_POR_RUTA_DE_CARPETA
    ```
2. Compilar en modo depuración con el parámetro -g:
    ```bash
    gcc -g practica1.c -o practica1.exe
    ```
3. Cargar en el depurador el ejecutable:
    ```bash
    gdb practica1.exe
    ```
    > Si añades el parámetro _-q_ o _--quiet_ ocultará el texto inicial de GDB. Ejemplo: _gdb -q practica1.exe_



<br><div id="punto3"></div>

## Anotaciones
- Puedes ejecutar todo directamente:
    ```bash
    gcc -g practica1.c -o practica1.exe && gdb --quiet practica1.exe
    ```
