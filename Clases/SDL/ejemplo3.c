// Clase 22-05-26

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main (int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf ("Error: %s\n", SDL_GetError());
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

    //Comando para q aviente la ventana ahcia el frente
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

    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                running = false;
            } else if (event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_x)
                    running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RendererClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        SDL_Rect square= {(WIDTH/2)-25, (HEIGHT/2)-25, 50, 50};

        SDL_RenderFillRect(renderer, &square);

        SDL_RenderPresent(renderer);
    }

    //SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}