#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window* g_pWindow = 0;
    SDL_Renderer* g_pRenderer = 0;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout<< "Failed to initialize SDL library." << std::endl;
        return -1;
    } 

    g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL",
                                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 1440, 900, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if(g_pWindow == NULL) {
        std::cout << "Failed to create window" << std::endl;
        SDL_Quit();
        return -1;
    }

    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    if (g_pRenderer == NULL) {
        SDL_DestroyWindow(g_pWindow);
        SDL_Quit();
        return -1;
    }

    std::cout << "Library initialized. Window and Renderer are ready. Rendering..." << std::endl;

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            break;
        }

        SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(g_pRenderer);
        SDL_RenderPresent(g_pRenderer);
    }    

    std::cout << "Finilizing." << std::endl;
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
    return 0;
}