#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 15

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

//Dependiendo del sistema operativo (WIndows o MAc)
#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>

#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>

#endif

int snakeX, snakeY; // posición de la primera parte de la vibora
int fruitX, fruitY;
char direction= 'd';
int score=0;

int increaseScore(){
    static int score=0;
    score++;
    return score;
}

//Cuando paso los parameteos como un apuntador estoy usando "por referencia", es que la variable que entra a la funcion se modificará, (enviando la direccion de las variabkles)
void moveSnake(int *x, int *y,char dir){
    switch (dir)
    {
    case 'w': case 'W': (*y)--; break;
    case 's': case 'S': (*y)++; break;
    case 'a': case 'A': (*x)--; break;
    case 'd': case 'D': (*x)++; break;
    }
}

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Función que sirve para no presionar Enter al moverse en Windows
#ifdef _WIN32
char readInput(){
    if(_kbhit()) return _getc();
    return direction;
}
#else
//Función que sirve para no presionar Enter al moverse en Linux (Mac)
struct termios oldt;

void enableRawMode(){
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_GETFL, O_NONBLOCK);
}
void disableRawMode(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

char readInput(){
    
    int ch;
    ch = getchar();
    if(ch!= EOF) return ch;
    return 0;
}


char readInput(){
    
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch!=EOF){

    } return (char) ch;

    return direction;
}
#endif

/**
 * Función que sirve  para iniciar el juego
 */
void setup(){
    snakeX=WIDTH/2;
    snakeY=HEIGHT/2;

    fruitX = (rand()%(WIDTH-2))+1;
    fruitY = (rand()%(HEIGHT-2))+1;
}

void draw(){
    clearScreen();
    //system("clear");
    for(int i=0; i< HEIGHT;i++){
        for(int j=0; j< WIDTH; j++){
            if(j==0 || i ==0 || i==HEIGHT-1 || j == WIDTH-1){
                 printf(YELLOW"#");
                 continue;
            }
            if(snakeX==j && snakeY==i){
                printf(GREEN"s");
                continue;
            } 
            if(fruitX==j && fruitY==i){
                printf(RED"o");
                continue;
            } 
            printf(RESET" ");
        }
        printf(RESET"\n");
    }
    printf(RESET"Score %d\n", score);
   // printf("Presiona W o S o D o A\n");
}

// Código para que se mueva la serpiente
void logic(){
    // Función para que choque con las paredes
    if(snakeX<=0 || snakeX>=WIDTH || snakeY<=0 || snakeY>=HEIGHT){
        printf(RED"Game Over \n" RESET);
        exit(0);
    }
    // Función para que se coma las frutas
    if(snakeX == fruitX && snakeY == fruitY){
        fruitX = (rand()%(WIDTH-2))+1;
        fruitY = (rand()%(HEIGHT-2))+1;
        score = increaseScore();
    }
}
int main(){
    char newDirection;
    setup();
    #ifndef _WIN32
    enableRawMode();
    #endif
    while(true){
        draw();
        direction = readInput();
        switch (newDirection){
            case 'w': case 'W': case 's': case 'S': case 'd': case 'D': case 'a': case 'A':
            direction = newDirection;
            break; //solo cambia la dirección 
        }
        moveSnake(&snakeX, &snakeY, direction);
        logic();

        //Función para detener la pantalla tantos milisegundos
        #ifdef _WIN32
        Sleep(150);
        #else
        usleep(150000);
        #endif 
    }
    #ifndef _WIN32
    disableRawMode();
    #endif
    return 0;
}


//Variables globales fuera de una funcion 
/*Variables locales una vez q se termina la funcion se le olvidan los valores
pero las variables estaticas a pesar de su ejecuciòn siempre va a conservar el último 
valor calculado
*/