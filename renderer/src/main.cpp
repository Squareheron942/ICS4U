#include <stdio.h>
#include <SDL2/SDL.h>
#include <renderer.h>
#include "vector"

int main() {
    SDL_Window * window = nullptr;

    SDL_Surface * window_surface = nullptr;
    SDL_Surface * image_surface = nullptr;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    window_surface = SDL_GetWindowSurface(window);

    image_surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0xFF, 0xFF00, 0xFF0000, 0xFF000000);

    // vector v1 = {{0.577350269f, 0.577350269f, 0.577350269f, 0.0f}}, v2 = {{0.577350269f, 0.577350269f, 0.577350269f, 0.0f}};
    // printf("%f", v1 * v2);

    // printf("%f %f %f\n", persp_bary(float4{3, 2}, float4{5, 3}, float4{2, 4}, float4{3, 3}, float4{1, 1, 1, 1})[0], persp_bary(float4{3, 2}, float4{5, 3}, float4{2, 4}, float4{3, 3}, float4{1, 1, 1, 1})[1], persp_bary(float4{3, 2}, float4{5, 3}, float4{2, 4}, float4{3, 3}, float4{1, 1, 1, 1})[2]);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT){
                quit = true;
            }
        }
        
        renderer::render(image_surface);
        SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
        SDL_UpdateWindowSurface(window);
        SDL_FillRect(image_surface, NULL, 0);
        SDL_FillRect(window_surface, NULL, 0);
    }

    SDL_DestroyWindow(window);
    SDL_FreeSurface(image_surface);
    SDL_Quit();
}