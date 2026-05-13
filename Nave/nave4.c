#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15
#define MAX_OBJ 10

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m" 
#define RESET "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

int naveX, naveY, score = 0, contSpawn = 0, contVel = 0, contEstrella = 0, contEnemigo = 0;
bool game_over = false, pausado = false, estrellaVisible = false, enemigoEnPantalla = false;
int estrellaX, estrellaY;

typedef struct { int x, y, dir; bool activo; } Objeto;
Objeto balas[5], balasE[5], ast[MAX_OBJ], enemigos[3];

void clearScreen() {
#ifdef _WIN32
    COORD c = {0, 0}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#else
    printf("\033[H");
#endif
}

#ifndef _WIN32
struct termios oldt;
void enableRawMode() {
    struct termios newt; tcgetattr(STDIN_FILENO, &oldt); newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
}
void disableRawMode() { tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }
#endif

bool choca(int x, int y) { return (x == naveX && y == naveY) || ((x == naveX-1 || x == naveX+1) && y == naveY+1); }

void setup() {
    srand(time(NULL)); naveX = WIDTH / 2; naveY = HEIGHT - 3;
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); CONSOLE_CURSOR_INFO inf = {100, 0}; SetConsoleCursorInfo(h, &inf);
#else
    printf("\033[?25l");
#endif
}

void draw() {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) printf(YELLOW "#");
            else if (j == naveX && i == naveY) printf(GREEN "#");
            else if ((j == naveX - 1 || j == naveX + 1) && i == naveY + 1) printf(GREEN "#");
            else if (estrellaVisible && j == estrellaX && i == estrellaY) printf(CYAN "★");
            else {
                bool d = false;
                for (int k = 0; k < 5; k++) {
                    if (balas[k].activo && balas[k].x == j && balas[k].y == i) { printf(BLUE "|"); d = 1; break; }
                    if (balasE[k].activo && balasE[k].x == j && balasE[k].y == i) { printf(RED "v"); d = 1; break; }
                }
                for (int k = 0; k < MAX_OBJ && !d; k++) if (ast[k].activo && ast[k].x == j && ast[k].y == i) { printf(RED "*"); d = 1; break; }
                for (int k = 0; k < 3 && !d; k++) if (enemigos[k].activo && enemigos[k].x == j && enemigos[k].y == i) { printf(RED "W"); d = 1; break; }
                if (!d) printf(" ");
            }
        }
        printf("\n");
    }
    if (pausado) printf(YELLOW "\n  === PAUSA ===\n" RESET);
    else {
        printf(RESET "\nCONTROLES: WASD | Espacio | P\n" CYAN "SCORE: %d\n" RESET, score);
    }
}

void logic(char in) {
    if (in == 'p' || in == 'P') pausado = !pausado;
    if (pausado) return;
    if ((in == 'w' || in == 'W') && naveY > 1) naveY--;
    if ((in == 's' || in == 'S') && naveY < HEIGHT - 3) naveY++;
    if ((in == 'a' || in == 'A') && naveX > 2) naveX--;
    if ((in == 'd' || in == 'D') && naveX < WIDTH - 3) naveX++;
    if (in == ' ') for (int i = 0; i < 5; i++) if (!balas[i].activo) { balas[i] = (Objeto){naveX, naveY - 1, 0, 1}; break; }

    for (int i = 0; i < 5; i++) {
        if (balas[i].activo && --balas[i].y <= 0) balas[i].activo = 0;
        if (balasE[i].activo) { balasE[i].y++; if (balasE[i].y >= HEIGHT-1) balasE[i].activo = 0; if (choca(balasE[i].x, balasE[i].y)) game_over = 1; }
    }

    // --- LÓGICA DE EXCLUSIÓN MUTUA ---
    
    // Verificar si hay enemigos activos
    enemigoEnPantalla = false;
    for(int i=0; i<3; i++) if(enemigos[i].activo) enemigoEnPantalla = true;

    // Estrella: Solo aparece si NO hay enemigos
    if (!enemigoEnPantalla) {
        if (++contEstrella >= 100) { 
            estrellaVisible = !estrellaVisible; 
            if (estrellaVisible) { estrellaX = rand() % (WIDTH - 4) + 2; estrellaY = rand() % (HEIGHT - 4) + 2; } 
            contEstrella = 0; 
        }
    } else {
        estrellaVisible = false; // Desaparece si llega un enemigo
    }
    
    if (estrellaVisible && choca(estrellaX, estrellaY)) { score += 5; estrellaVisible = 0; }

    // Enemigo: Solo aparece si NO hay estrella visible
    if (!estrellaVisible) {
        if (++contEnemigo >= 80) { 
            for (int i = 0; i < 3; i++) if (!enemigos[i].activo) { 
                enemigos[i] = (Objeto){rand() % (WIDTH - 4) + 2, 1, 0, 1}; 
                for(int k=0; k<5; k++) if(!balasE[k].activo) { balasE[k] = (Objeto){enemigos[i].x, enemigos[i].y+1, 0, 1}; break; }
                break; 
            } 
            contEnemigo = 0; 
        }
    }

    // --- FIN EXCLUSIÓN ---

    if (++contSpawn >= 40) { for (int i = 0; i < MAX_OBJ; i++) if (!ast[i].activo) { ast[i] = (Objeto){rand() % (WIDTH - 4) + 2, 1, rand() % 3 - 1, 1}; break; } contSpawn = 0; }

    bool mov = (++contVel >= 3); if (mov) contVel = 0;
    for (int i = 0; i < MAX_OBJ; i++) if (ast[i].activo) {
        if (mov) { ast[i].y++; ast[i].x += ast[i].dir; }
        if (ast[i].x <= 1 || ast[i].x >= WIDTH - 2) ast[i].dir *= -1;
        if (ast[i].y >= HEIGHT - 1) ast[i].activo = 0;
        if (choca(ast[i].x, ast[i].y)) game_over = 1;
        for (int b = 0; b < 5; b++) if (balas[b].activo && balas[b].x == ast[i].x && balas[b].y == ast[i].y) { ast[i].activo = balas[b].activo = 0; score++; }
    }
    for (int i = 0; i < 3; i++) if (enemigos[i].activo) {
        if (mov) enemigos[i].y++;
        if (enemigos[i].y >= HEIGHT - 1) enemigos[i].activo = 0;
        if (choca(enemigos[i].x, enemigos[i].y)) game_over = 1;
        for (int b = 0; b < 5; b++) if (balas[b].activo && balas[b].x == enemigos[i].x && balas[b].y == enemigos[i].y) { enemigos[i].activo = balas[b].activo = 0; score += 2; }
    }
}

int main() {
    setup();
#ifndef _WIN32
    enableRawMode();
#endif
    while (!game_over) {
        char in = 0;
#ifdef _WIN32
        if (_kbhit()) in = _getch();
#else
        in = getchar(); if (in == EOF) in = 0;
#endif
        if (in == 'q' || in == 'Q') break;
        draw(); logic(in);
#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000);
#endif
    }
#ifndef _WIN32
    disableRawMode();
#endif
    printf(RED "\n--- GAME OVER ---\n" RESET "Puntaje Final: %d\n", score);
    return 0;
}