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

// Variables globales
int naveX, naveY;
char direction = ' ';
bool game_over = false;

// --- FUNCIONES DE TERMINAL (SISTEMA) ---
#ifdef _WIN32
void clearScreen(){ system("cls"); }
char readInput(){ if(_kbhit()) return _getch(); return 0; }
#else
struct termios oldt;
void enableRawMode(){
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON| ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);    
    int flags = fcntl(STDIN_FILENO, F_GETFL, O_NONBLOCK); 
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); 
}
void disableRawMode(){ tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }
void clearScreen(){ system("clear"); }
char readInput(){ int ch = getchar(); if(ch!= EOF) return ch; return 0; }
#endif

// --- MOVER JUGADOR (CON PUNTEROS) ---
void movePlayer(int *x, int *y, char dir){
    switch (dir){
        case 'w': case 'W': (*y)--; break;
        case 's': case 'S': (*y)++; break;
        case 'a': case 'A': (*x)--; break;
        case 'd': case 'D': (*x)++; break;
    }
}

// --- LÓGICA DE COLISIONES (GAME OVER) ---
void logic(){
    // Verifica si la punta o la base de la nave tocan los muros
    if(naveX <= 0 || naveX >= WIDTH - 1 || naveY <= 0 || naveY >= HEIGHT - 2){
        game_over = true;
    }
    // Verifica si las alas laterales chocan
    if(naveX - 1 <= 0 || naveX + 1 >= WIDTH - 1){
        game_over = true;
    }
}

void setup(){
    // Inicia en el centro inferior
    naveX = WIDTH / 2;
    naveY = HEIGHT - 3; 
}

void draw(){
    clearScreen();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            // Bordes amarillos
            if(i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1){
                printf(YELLOW"#");
                continue;
            }

            // DIBUJAR LA NAVE (# arriba y # # abajo)
            if(i == naveY && j == naveX){
                printf(GREEN"#"); // Punta
            }
            else if(i == naveY + 1 && (j == naveX - 1 || j == naveX + 1)){
                printf(GREEN"#"); // Alas
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    if(game_over) {
        printf(RED"  ¡¡¡ GAME OVER !!!\n"RESET);
        printf(RED"  Chocaste contra el borde.\n"RESET);
    } else {
        printf(RESET"  WASD: Mover | Q: Salir\n");
    }
}

int main(){
    setup();
    #ifndef _WIN32
    enableRawMode();
    #endif

    while(!game_over){
        draw();
        char nuevo = readInput();
        if(nuevo == 'q' || nuevo == 'Q') break;
        
        if(nuevo != 0) direction = nuevo;

        movePlayer(&naveX, &naveY, direction);
        direction = 0; // Detenerse para que no sea como la víbora
        
        logic(); 

        #ifdef _WIN32
        Sleep(50);
        #else
        usleep(50000);
        #endif
    }

    // Dibujar el estado final del choque
    draw();

    #ifndef _WIN32
    disableRawMode();
    #endif

    // Pausa para que veas tu derrota
    #ifdef _WIN32
    Sleep(2000);
    #else
    sleep(2);
    #endif

    return 0;
}