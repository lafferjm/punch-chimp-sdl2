#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <string>
#include <SDL2/SDL.h>

#include "../chimp/chimp.hpp"

class Fist {
    public:
        Fist(std::string, SDL_Renderer*);
        void draw();
        void punch(Chimp*);
        void unpunch();
    private:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Rect m_position;
        int m_x_offset;
        int m_y_offset;
        bool m_punching;
};

#endif
