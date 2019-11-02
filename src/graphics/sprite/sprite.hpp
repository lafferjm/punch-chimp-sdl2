#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <SDL2/SDL.h>

class Sprite {
    public:
        void set_offset(int, int);
        void set_position(int, int);
        virtual void update() = 0;
    protected:
        SDL_Renderer* m_renderer;
        SDL_Texture* m_texture;
        SDL_Rect m_position;
        SDL_Point m_offset;

};

#endif
