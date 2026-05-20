// Clase 20-05-26

#include <stdio.h>
#include <SDL2/SDL.h>

int main (int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO)==0)
    {
        printf ("Error: %s\n", SDL_GetError());
        return 1;
    }

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

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();
}