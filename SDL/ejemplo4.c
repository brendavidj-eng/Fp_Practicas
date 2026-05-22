// Clase 22-05-26 ---- El cuadrado se moverá

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>

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
    }*/

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

    /*if(texture == NULL){
        printf("Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }*/

    posX=(WIDTH/2)-25;
    posY=(HEIGHT/2)-25;

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                running = false;
            } else if (event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym)
                {
                case SDLK_x:
                    running = false;
                    break;

                case SDLK_UP:
                    posY -= speed;
                    break;

                case SDLK_DOWN:
                    posY += speed;
                    break;

                case SDLK_LEFT:
                    posX -= speed;
                    break;

                case SDLK_RIGHT:
                    posX += speed;
                    break;

                default:
                    break;
                    
                }
            }
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RendererClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        SDL_Rect square= {posX, posY, 50, 50};

        //SDL_Rect src = {0,10,16,40}; // Sirve para recorrer la imagen
        //SDL_Rect dest = {posX, posY, 32, 64}; // Dibuja

        /*SDL_RenderCopy(
            rederer,
            texture,
            &src,
            &dest
        ); */

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