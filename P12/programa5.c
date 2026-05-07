// Practica 06-05-26

#include <stdio.h>
#define RED "\033[31m"

int main(int argc, char **argv){
    FILE *archivo;
    char linea[256];

    if(argc < 2 ){
        printf(RED"ERROR FATAL: hacen falta argumentos\n");
        return 1;
    }

    archivo=fopen(argv[1], "r");

    if(archivo!= NULL){
        printf("El archivo se abrio correctamente\n");
        char cosa[30];
        float precio;
        while(feof(archivo)==0){
            fscanf(archivo,"%s\t%f",cosa, &precio);
            printf("%s\t%f\n",cosa, precio);
        }
        int res = fclose(archivo);
        printf("fclose = %d\n", res);
    }else{
        printf(RED"ERROR FATAL: %s no es un archivo o directorio\n", argv[1]);
    }
    return 0;
}