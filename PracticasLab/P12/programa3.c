//Practica 06-05-26

#include <stdio.h>
#define RED "\033[31m"

int main (int argc, char **argv){
    FILE *archivo;
    char linea[256]; //arreglo con max 256 caracteres

    if (argc < 2){
        printf(RED"Error Fatal: hacen falta argumentos\n");
        return 1;
    }

    archivo = fopen(argv[1], "r");

    if(archivo!=NULL){
        printf("El archivo se abrio correctamente\n");

// feof retorna un número distinto de 0 cuando encuentre un archivo o un 0 cuando no ha leido el fin de archivo
        while(feof(archivo)==0){
            fgets(linea, 256, archivo);
            printf("%s", linea);        
        }
         
//primer agumento, en donde guardar lo q se leyò, el segundo, el numero max de caracteres a leer, el tercero de donde quiero leer 
//puede dejar de leer cuadno lea el número max de caracteres o un salto de linea

        int res = fclose(archivo);

        printf("fclose = %d\n", res);
    } else {
        printf (RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}


/* */