/* Clase 25-05-26 ---- Diferentes Imagenes Para Posiciones

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH 800
#define HEIGHT 600

int posX, posY;
int speed = 10;

int main (int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf ("Error: %s\n", SDL_GetError());
        return 1;
    }

    /*IF(!(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG)){
        printf ("Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    SDL_Window *window = SDL_CreateWindow(
        "HOLA MUNDO", // titulo de la ventana
        SDL_WINDOWPOS_CENTERED, // posicion de la ventana en X
        SDL_WINDOWPOS_CENTERED, // posicion de la ventana en Y
        800, // ancho de la ventana 
        600, // alto de la ventana
        0
    );

    if(window == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_RaiseWindow(window);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if(renderer == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *texture = IMG_LadTexture(renderer, "venus.png");

    if(texture == NULL){
        printf("Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    posX=(WIDTH/2)-25;
    posY=(HEIGHT/2)-25;
    int frame = 0, frameWidth = 22, frameHeight = 40;
    int framePosX=0, framePosY=11; 
    int direction = 0;

    unsigned int lastframe = 0;
    const

    SDL_RendererFlip flip=SDL_FLIP_NONE;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        keyboard = SDL_GetKeyboardState(NULL);
        bool moving = false;

        if(keyboard[SDL_SCANCODE_UP]){
            direction=2;
            frame=(frame+1)%4;
            posY-=speed;
            flip=SDL_FLIP_NONE;
        }
        if(keyboard[SDL_SCANCODE_DOWN]){
            direction=1;
            frame=(frame+1)%5;
            posX-=speed;
            flip=SDL_FLIP_
        }
        if(keyboard[SDL_SCANCODE_LEFT]){
            direction=2;
            frame=(frame+1)%4;
            posY-=speed;
            flip=SDL_FLIP_;
        }
        if(keyboard[SDL_SCANCODE_RIGHT]){
            direction=1000;
            frame=(frame)
            flip=
        }

        unsigned int currentTime = SDL_GetTicks(); //Esta función retorna el tiempo actual

        if(!moving){
            if(currentTime > lastframe+150){
            
            }
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RendererClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,255,255,255);

    if(direction==100)
            SDL_RenderCopyEx(
                render,
                texture,
                &src,
                &dest,
                0,
                NULL,
                SDL_FLIP_HORIZONTAL
                );

    else
        SDL_RenderCopy(
            rederer,
            texture,
            &src,
            &dest
        );

        //SDL_RenderFillRect(renderer, &square);

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    //SDL_DestroyTexture(texture);
    //SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    //IMG_Quit();
    SDL_Quit();
}
*/