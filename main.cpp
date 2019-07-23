#include <iostream>
#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BITS_PER_PIXEL 32

int main (int arggc, const char** argv) {
    SDL_Window* pWindow;
    SDL_GLContext glcontext;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Failed to initialize SDL library. Error: " << SDL_GetError() << std::endl;
        return -1;
    } 

    pWindow = SDL_CreateWindow( "SDL + OpenGL rock",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH,
                                WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!pWindow) {
        std::cout << "Failed to create window. Error: " << SDL_GetError() << std::endl;
        SDL_Quit();    
        return -1;
    }

    glcontext = SDL_GL_CreateContext(pWindow);
    if (!glcontext) {
        std::cout << "Failed to create Open GL context. Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(pWindow);
        SDL_Quit();
        return -1;
    }

    //glClearColor(0,0,0,1);
    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) break;
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) break;

        //SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
        //SDL_RenderClear(g_pRenderer);
        //SDL_RenderPresent(g_pRenderer);

        
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(pWindow);
    }
    
    SDL_GL_DeleteContext(glcontext);
    SDL_Quit();
    return 0;
}