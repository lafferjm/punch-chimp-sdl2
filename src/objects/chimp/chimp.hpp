#ifndef __CHIMP_HPP__
#define __CHIMP_HPP__

#include <string>
#include <SDL2/SDL.h>

class Chimp {
    public:
        Chimp(std::string, SDL_Renderer*);
        void draw();
    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Rect m_position;
        int m_x_offset;
        int m_y_offset;
};

#endif