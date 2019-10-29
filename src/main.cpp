#include <SDL2/SDL.h>
#include <stdio.h>

#include "window/window.hpp"

int main(int argc, char** argv) {
    Window * window = new Window("Monkey Fever", 468, 60);
    window->set_clear_color(255, 255, 255, 255);    

    while(window->is_open()) {
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

        window->draw();
    }
    

    return 0;
}