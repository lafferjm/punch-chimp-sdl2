#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char** argv) {

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Monkey Fever", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 468, 60, 0);
    if (!window) {
        printf("Failed to open window: %s\n", SDL_GetError());
        exit(1);
    }


    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    bool windowOpen = true;

    while(windowOpen) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    exit(0);
                    break;
                default:
                    break;
            }
        }

        SDL_RenderClear(renderer);  
        SDL_RenderPresent(renderer);
    }
    

    return 0;
}