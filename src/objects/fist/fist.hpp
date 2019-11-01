#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <string>
#include <SDL2/SDL.h>

class Fist {
    public:
        Fist(std::string, SDL_Renderer*);
        void draw();
    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Rect m_position;
};

#endif
