# Archivos

## Índice
1. [Introducción](#punto1)
2. [Flujos](#punto2)
3. [Apertura y cierre de un archivo](#punto3)
4. [Modos de apertura](#punto4)
5. [Funciones de lectura y escritura](#punto5)



<br><div id="punto1"></div>

## 1. Introducción
Los datos que se han tratado hasta el momento han residido en la memoria principal. Los archivos sirven para almacenar información (en bytes) que luego pueda utilizarse. En C, antes de abrir un archivo, se decide cómo se abre este.



<br><div id="punto2"></div>

## 2. Flujos
Un flujo, o _stream_, es una abstracción que ese refiere a un fujo o corriente de datos que fluyen entre un origen o fuente (productor) y un destino o sumidero (consumidor).

La apertura de un archivo supone establecer la conexión del programa con el dispositivo que contiene el archivo. El acceso a los archivos se hace con un buffer intermedio

Tipos de flujos:
- `extern FILE *stdin`: entrada de teclado
- `extern FILE *stdout`: salida de pantalla
- `extern FILE *stderr`: entrada de errores



<br><div id="punto3"></div>

## 3. Apertura y cierre de un archivo
En C, un archivo puede abrirse como binario o como texto. El programa accede a través de un puntero a la estructura FILE. La función de apertura devuelve dicho puntero. Esta estructura incluye información acerca del archivo.


Ejemplo:
1. Crea un archivo vacío de nombre _prueba.txt_
2. A continuación, en un archivo de C, dentro del _main_, pega las siguientes líneas:
    ```c
    //Creación de un archivo y apertura en modo lectura
    FILE *archivo = fopen("prueba.txt", "r");
    ```
3. Posteriormente, añade estas líneas para comprobar si el archivo se ha abierto correctamente:
    ```c
        //Comprueba si el archivo se ha abierto correctamente
        if(archivo == NULL){
            //Mensaje de error
            printf("El archivo no puede abrirse...\n");
        } else {
            //Mensaje de éxito
            printf("El archivo se ha abierto correctamente...\n");
        }
    ```
    > Si el archivo no se abre o lanza un mensaje de error, añade la línea _perror("Error")_ para devovler el mensaje
4. Añade _flcose(archivo);_ para cerrar el archivo. Esta función devuelve 0 si se cierra correctamente:
    ```c
    //Cerrar el archivo
    fclose(archivo);
    ```


<br><div id="punto4"></div>

## 4. Modos de apertura
| Modo | Descripción | ¿Crea un archivo si no existe? |
| ---- | ----------- | ----------------------- |
| r    | Abre en modo lectura | No |
| w    | Abre en modo escritura | Sí |
| a    | Añade contenido al final | Sí |
| r+   | Modo lectura y escritura al mismo tiempo | No |
| w+   | Escribe, pero elimina su contenido antes | Sí |
| a+   | Abre para lectura y añadir contenido al final | Sí |




<br><div id="punto5"></div>

## 5. Funciones de lectura y escritura
Partiendo del ejemplo anterior, escribe en ese archivo tu nombre utilizando _fputs_:
```c
//Escritura dentro del archivo
fputs("Texto inicial", archivo);

//IMPORTANTE: cerrar el archivo
fclose(archivo);
```