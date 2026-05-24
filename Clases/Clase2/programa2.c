#include <stdio.h>
int main(){
    int x,y;

    // SUMA
    x=6;
    printf ("x=%d \n",x);
    y=4;
    printf("y=%d \n",y);
    x+=3;
    printf ("x=%d \n",x);
    x+=y;
    printf ("x=%d \n",x);

    // RESTA
    x=6;
    printf ("x=%d \n",x);
    y=2;
    printf("y=%d \n",y);
    x-=1;
    printf ("x=%d \n",x);
    x-=y;
    printf ("x=%d \n",x);

    // MULTIPLICACIÓN
    x=5;
    printf ("x=%d \n",x);
    y=3;
    printf("y=%d \n",y);
    x*=2;
    printf ("x=%d \n",x);
    x*=y;
    printf ("x=%d \n",x);

    // DIVISIÓN
    x=30;
    printf ("x=%d \n",x);
    y=2;
    printf("y=%d \n",y);
    x/=3;
    printf ("x=%d \n",x);
    x/=y;
    printf ("x=%d \n",x);

    // MÓDULO
    x=20;
    printf ("x=%d \n",x);
    y=3;
    printf("y=%d \n",y);
    x%=12;
    printf ("x=%d \n",x);
    x%=y;
    printf ("x=%d \n",x);

    return 0;
}