// Clase 18-05-26   Código para abrir una ventana (Msys2)

/*#include <SDL2/SDL.h>
#include <stdio.h>

int main (int argc, char **argv){
    if (SDL_Init(SDL_INIT_VIDEO)!=0){
        printf("Error %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
    "Hola Mundo",
    SDL_WINDOWPOS_CENTERED, //POS X
    SDL_WINDOWPOS_CENTERED, //POS Y
    800,
    600,
    0
    );

    if(!window) // if(window == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
*/