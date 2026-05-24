//Practica 06-05-26

#include <stdio.h>
#define RED "\033[31m"

int main (int argc, char **argv){
    FILE *archivo;

    if (argc < 2){
        printf(RED"Error Fatal: hacen falta argumentos\n");
        return 1;
    }

    archivo = fopen(argv[1], "r");

    if(archivo!=NULL){
        printf("El archivo se abrio correctamente\n");
        int res = fclose(archivo);
        printf("fclose = %d\n", res);
    } else {
        printf (RED"Error Fatal: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}


/* argv es un arreglo de cadenas, aquì viene el nombre del archivo almacenado 
en la 2da posiciòn de la cadena [1]
argc es el contador o el nùmero de cadenas almacenadas en argv 
el nombre del programa ejecutable es argv[0] = ./ */