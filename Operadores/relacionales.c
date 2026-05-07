#include <stdio.h>

int main () {
    int res;

    //Igual a
    res = ('h' == 'p');
    printf("res=%d\n", res);

    //Diferente
    res = ('h' != 'p');
    printf("res=%d\n", res);

    //Menor que
    res = (7 < 15);
    printf("res=%d\n", res); 

    //Mayor que
    res = (22 > 11);
    printf("res=%d\n", res);

    //Menor o igual que
    res = (15 <= 2);
    printf("res=%d\n", res);
    
    //Mayor o igual que
    res = (30 >= 100);
    printf("res=%d\n", res);

    return 0;

}