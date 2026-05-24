#include <stdio.h>
int main(){ 
    int a,b,c,op2;
    float f,g,h;
    char op;
    printf ("Seleccionar una opción\n");
    printf ("1. Operaciones con enteros \n");
    printf ("2. Operaciones con reales\n");
    scanf ("%c", &op);
    printf ("Seleccionar una opción\n");
    printf ("1. Suma\n");
    printf ("2. Resta\n");
    printf ("3. Mutiplicación\n");
    printf ("4. División\n");
    printf ("5. Módulo\n");
    printf ("6. Salir\n");
    scanf ("%d", &op2);
    
    if(op==1){ 
        printf ("Ingresa los dos números con los que quieras operar:\n");
        scanf ("%d %d", &a, &b);
        switch (op2){ 
        case 1: 
            c=a+b;
            break;
        case 2:
            c=a-b;
            break;
        case 3:
            c=a*b;
            break;
        case 4:
            c=a/b;
            break;
        case 5:
            c=a%b;
            break;
        default:
    }
    printf ("El resultado es %d\n",c);

    }else
        printf ("Ingresa los dos números con los que quieras operar\n");
        scanf ("%f %f", &f, &g);
        switch (op2 ){ 
          case 1: 
            h=f+g;
            break;
        case 2:
            h=f-g;
            break;
        case 3:
            h=f*g;
            break;
        case 4:
            h=f/g;
            break;
        case 5:
            h=(int)f%(int)g;
            break;
        default:      
    }
    printf ("El resultado es %f\n",h);

    return 0;
}