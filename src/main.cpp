#include <SDL2/SDL.h>
#include <stdio.h>

#include "objects/chimp/chimp.hpp"
#include "objects/fist/fist.hpp"
#include "text/text.hpp"
#include "window/window.hpp"

int main(int argc, char** argv) {
    Window* window = new Window("Monkey Fever", 468, 60);
    window->set_clear_color(255, 255, 255, 255);    

    Text* text = new Text("Pummel The Chimp, And Win $$$", 24, 35, 0, window->get_renderer());
    Fist* fist = new Fist("resources/textures/fist.bmp", window->get_renderer());
    Chimp* chimp = new Chimp("resources/textures/chimp.bmp", window->get_renderer());

    while(window->is_open()) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    exit(0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        fist->punch(chimp);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        fist->unpunch();
                    }
                default:
                    break;
            }
        }

        window->begin();
        text->draw();
        chimp->update();
        fist->update();
        window->end();
        
    }
    

    return 0;
}