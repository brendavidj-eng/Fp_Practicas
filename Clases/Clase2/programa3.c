#include<stdio.h>
int main(){
    int x,y;

    //Post Incremento
    x=7;
    printf ("x=%d \n",x);
    y=x++;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);

    //Pre Incremento
    x=7;
    printf ("x=%d \n",x);
    y=++x;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);

    //Post Decremento
    x=7;
    printf ("x=%d \n",x);
    y=x--;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);

    //Pre Decremento
    x=7;
    printf ("x=%d \n",x);
    y=--x;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);
    
    return 0;
}