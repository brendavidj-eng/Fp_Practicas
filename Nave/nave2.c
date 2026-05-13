//Clase 13-05-26

//Código Space con ayuda de IA (Gemini)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 15

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

int naveX, naveY; 
int fruitX, fruitY;
int score = 0;
bool game_over = false;

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#ifndef _WIN32
struct termios oldt;
void enableRawMode(){
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int flags = fcntl(STDIN_FILENO, F_GETFL, O_NONBLOCK);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}
void disableRawMode(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
#endif

// Función modificada: si no hay tecla, devuelve 0 (no se mueve sola)
char readInput(){
#ifdef _WIN32
    if(_kbhit()) return _getch();
#else
    int ch = getchar();
    if(ch != EOF) return ch;
#endif
    return 0;
}

void generateFruit(){
    // Evitamos que la fruta salga en los bordes o donde la nave suele estar
    fruitX = (rand() % (WIDTH - 4)) + 2;
    fruitY = (rand() % (HEIGHT - 4)) + 1;
}

void setup(){
    // Posición inicial: centro horizontal, parte inferior (dejando espacio para las alas)
    naveX = WIDTH / 2;
    naveY = HEIGHT - 3; 
    generateFruit();
}

void draw(){
    clearScreen();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            // Bordes
            if(j == 0 || i == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
                printf(YELLOW "#");
            }
            // Nave (Punta)
            else if(j == naveX && i == naveY){
                printf(GREEN "#");
            }
            // Nave (Alas un renglón abajo)
            else if((j == naveX - 1 || j == naveX + 1) && i == naveY + 1){
                printf(GREEN "#");
            }
            // Fruta
            else if(j == fruitX && i == fruitY){
                printf(RED "Ѽ");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf(RESET "Score: %d | Mueve la nave con WASD\n", score);
}

void logic(char move){
    switch (move) {
        case 'w': case 'W': naveY--; break;
        case 's': case 'S': naveY++; break;
        case 'a': case 'A': naveX--; break;
        case 'd': case 'D': naveX++; break;
    }

    // Colisiones con bordes (ajustadas para el tamaño de la nave 3x2)
    if(naveX <= 1 || naveX >= WIDTH - 2 || naveY < 1 || naveY >= HEIGHT - 2){
        game_over = true;
    }

    // Colisión con fruta
    if((naveX == fruitX && naveY == fruitY) || 
       (naveX - 1 == fruitX && naveY + 1 == fruitY) || 
       (naveX + 1 == fruitX && naveY + 1 == fruitY)){
        score += 10;
        generateFruit();
    }
}

int main(){
    setup();
#ifndef _WIN32
    enableRawMode();
#endif

    while(!game_over){
        draw();
        char input = readInput();
        
        // Solo ejecuta la lógica si el usuario presionó una tecla válida
        if(input != 0) {
            logic(input);
        }

        // Un pequeño delay para que no parpadee demasiado
#ifdef _WIN32
        Sleep(30);
#else
        usleep(30000);
#endif
    }

    // GAME OVER EN ROJO
    clearScreen();
    draw();
    printf(RED "\n###########################\n");
    printf("#        GAME OVER        #\n");
    printf("###########################\n" RESET);

#ifndef _WIN32
    disableRawMode();
#endif
    return 0;
}