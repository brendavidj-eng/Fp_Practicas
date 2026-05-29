/*

//Partes del personaje --- Clase 29/05/26

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include WIDTH 800
#define HEIGHT 600

typedef enum{
    STATE_IDLE
    STATE_WALK
} State;

struct P{
    //Posición en x, y
    int x;
    int y;

    //Rápidez a la que se mueve el personaje
    int speed;

    //Velocidad en x, y
    int velX;
    int velY;

    //Número de sprite
    int frame;

    //Dirección del personaje
    int direction;

    State state;
    State previousState;

    SDL_RendererFlip flip; // Orientación hacia donde dibujar

    bool moving;

    unsigned int lastFrameTime;
};

typedef struct P Player;

void Player_Init(Player *player, int posx, int posy);

void Player_Update( Player *player, const Uint8 *keyboard);

void Player_Render(Player *player, SDL_Renderer *renderer, SDL_Texture *texture);

static void Player_HandleInput (Player *player, const unsigned char *keyboard);

static void Player_Move(Player *player);

static void Player_CheckCollisions(Player *player);

static void Player_UpdateState(Player *player);

static void Player_UpdateAnimation(Player *player);


)

*/