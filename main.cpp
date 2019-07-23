#include <iostream>
#include <SDL2/SDL.h>

int main (int arggc, const char** argv) {
    int width = 800;
    int height = 600;
    int bits_per_pixel = 32;
    bool windowed = true;

    SDL_Surface* pOGLSurface;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout<< "Failed to initialize SDL library." << std::endl;
        return -1;
    } 

    int displays =  SDL_GetNumVideoDisplays();
    int drivers = SDL_GetNumRenderDrivers();
    std::cout << "Displays number: " << displays << std::endl;
    for (int i = 0; i< displays; ++i)
        std::cout << "\t\t" << SDL_GetDisplayName(i) << std::endl;

    std::cout << "Drivers number: " << drivers << std::endl;

    for(int driver_index = 0; driver_index < drivers; ++driver_index) {
        SDL_RendererInfo info;
        SDL_GetRenderDriverInfo(driver_index, &info);
        std::cout << "-------------------------------------\n";
        std::cout << "Driver: " << info.name << std::endl;    
        
        std::cout << "FLAGS: ";
        if (info.flags & SDL_RENDERER_SOFTWARE) std::cout << "SDL_RENDERER_SOFTWARE ";
        if (info.flags & SDL_RENDERER_ACCELERATED) std::cout << "SDL_RENDERER_ACCELERATED ";
        if (info.flags & SDL_RENDERER_PRESENTVSYNC) std::cout << "SDL_RENDERER_PRESENTVSYNC ";
        if (info.flags & SDL_RENDERER_TARGETTEXTURE) std::cout << "SDL_RENDERER_TARGETTEXTURE ";
        std::cout << std::endl;

        std::cout << "Supported formats: " << std::endl;
        for(int i = 0; i < info.num_texture_formats; ++i) {
            std::cout << "\t\t" << SDL_GetPixelFormatName(info.texture_formats[i]) << std::endl;
        }

        std::cout << "Max texture width: " << info.max_texture_width << std::endl;
        std::cout << "Max texture height: " << info.max_texture_height << std::endl;
    }

    SDL_Rect rect;
    SDL_GetDisplayBounds(0, &rect);
    std::cout << "Bounds x= " << rect.x << ", ";
    std::cout << "y= " << rect.y << ", ";
    std::cout << "w= " << rect.w << ", ";
    std::cout << "h= " << rect.h << std::endl;
    //SDLGetVideoInfo


    SDL_Quit();
    return 0;
}