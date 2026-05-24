#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15
#define MAX_BALAS 10
#define MAX_ASTEROIDES 20

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m" 
#define RESET   "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

int naveX, naveY; 
int score = 0;
bool game_over = false;
bool pausado = false;

// Disparos
int balaX[MAX_BALAS], balaY[MAX_BALAS];
bool balaActiva[MAX_BALAS];

// Asteroides
int astX[MAX_ASTEROIDES], astY[MAX_ASTEROIDES], astDir[MAX_ASTEROIDES];
bool astActivo[MAX_ASTEROIDES];
int contSpawn = 0, contVel = 0;

// Item Estrella (★)
int estrellaX, estrellaY;
bool estrellaVisible = false;
int contEstrella = 0;

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

char readInput(){
#ifdef _WIN32
    if(_kbhit()) return _getch();
#else
    int ch = getchar();
    if(ch != EOF) return ch;
#endif
    return 0;
}

void generarAsteroide() {
    for(int i = 0; i < MAX_ASTEROIDES; i++) {
        if(!astActivo[i]) {
            astX[i] = (rand() % (WIDTH - 4)) + 2;
            astY[i] = 1;
            astDir[i] = (rand() % 3) - 1; 
            astActivo[i] = true;
            break;
        }
    }
}

void setup(){
    srand(time(NULL));
    naveX = WIDTH / 2;
    naveY = HEIGHT - 3; 
    for(int i=0; i<MAX_BALAS; i++) balaActiva[i] = false;
    for(int i=0; i<MAX_ASTEROIDES; i++) astActivo[i] = false;
    estrellaVisible = false;
}

void draw(){
    clearScreen();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            bool dibujado = false;

            if(j == 0 || i == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
                printf(YELLOW "#");
                dibujado = true;
            } else {
                for(int b=0; b < MAX_BALAS; b++) {
                    if(balaActiva[b] && balaX[b] == j && balaY[b] == i) {
                        printf(BLUE "|");
                        dibujado = true; break;
                    }
                }
                if(dibujado) continue;

                for(int a=0; a < MAX_ASTEROIDES; a++) {
                    if(astActivo[a] && astX[a] == j && astY[a] == i) {
                        printf(RED "*");
                        dibujado = true; break;
                    }
                }
                if(dibujado) continue;

                if(estrellaVisible && j == estrellaX && i == estrellaY) {
                    printf(CYAN "★");
                    dibujado = true;
                }
            }

            if(dibujado) continue;

            if(j == naveX && i == naveY) printf(GREEN "#");
            else if((j == naveX - 1 || j == naveX + 1) && i == naveY + 1) printf(GREEN "#");
            else printf(" ");
        }
        printf("\n");
    }
if (pausado) {
        printf(YELLOW "\n  === PAUSA (P para volver) ===\n" RESET);
    } else {
        printf(RESET "\nCONTROLES: WASD (Mover) | Espacio (Disparar) | P (Pausa)\n");
        printf(CYAN "SCORE: %d\n" RESET, score);
    }
}

void logic(char move){
    if (pausado) return;

    if ((move == 'w' || move == 'W') && naveY > 1) naveY--;
    if ((move == 's' || move == 'S') && (naveY + 1 < HEIGHT - 2)) naveY++;
    if ((move == 'a' || move == 'A') && (naveX - 1 > 1)) naveX--;
    if ((move == 'd' || move == 'D') && (naveX + 1 < WIDTH - 2)) naveX++;
    if (move == ' ') {
        for(int i = 0; i < MAX_BALAS; i++) {
            if(!balaActiva[i]) {
                balaX[i] = naveX; balaY[i] = naveY - 1;
                balaActiva[i] = true; break;
            }
        }
    }

    for(int i = 0; i < MAX_BALAS; i++) {
        if(balaActiva[i]) {
            balaY[i]--;
            if(balaY[i] <= 0) balaActiva[i] = false;
        }
    }

    contEstrella++;
    if(contEstrella >= 80) { // 4 segundos aprox
        estrellaVisible = !estrellaVisible;
        if(estrellaVisible) {
            estrellaX = (rand() % (WIDTH - 4)) + 2;
            estrellaY = (rand() % (HEIGHT - 4)) + 2;
        }
        contEstrella = 0;
    }

    if(estrellaVisible) {
        if((estrellaX == naveX && estrellaY == naveY) || 
           (estrellaX == naveX - 1 && estrellaY == naveY + 1) || 
           (estrellaX == naveX + 1 && estrellaY == naveY + 1)) {
            score += 5;
            estrellaVisible = false;
        }
    }

    contSpawn++;
    if(contSpawn >= 40) { generarAsteroide(); contSpawn = 0; }

    contVel++;
    bool moverAhora = (contVel >= 3);
    if(moverAhora) contVel = 0;

    for(int i = 0; i < MAX_ASTEROIDES; i++) {
        if(astActivo[i]) {
            if(moverAhora) {
                astY[i]++;
                astX[i] += astDir[i];
                if(astX[i] <= 1 || astX[i] >= WIDTH - 2) astDir[i] *= -1;
                if(astY[i] >= HEIGHT - 1) astActivo[i] = false;
            }

            if(astActivo[i] && ((astX[i] == naveX && astY[i] == naveY) || 
               ((astX[i] == naveX - 1 || astX[i] == naveX + 1) && astY[i] == naveY + 1))) {
                game_over = true;
            }

            for(int b = 0; b < MAX_BALAS; b++) {
                if(balaActiva[b] && astActivo[i]) {
                    if(balaX[b] == astX[i] && (balaY[b] == astY[i] || balaY[b] == astY[i]-1)) {
                        balaActiva[b] = false;
                        astActivo[i] = false;
                        score += 1;
                    }
                }
            }
        }
    }
}

int main(){
    setup();
#ifndef _WIN32
    enableRawMode();
#endif

    while(!game_over){ 
        char input = readInput();
        if(input == 'q' || input == 'Q') break;
        if(input == 'p' || input == 'P') pausado = !pausado;

        draw();
        logic(input);

#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000);
#endif
    }

#ifndef _WIN32
    disableRawMode();
#endif

    clearScreen();
    printf(RED "\n      --- GAME OVER ---\n");
    printf(" \n");
    printf(RESET "      Puntaje Total: %d\n\n", score);
    return 0;
}