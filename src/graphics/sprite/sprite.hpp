#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <string>
#include <SDL2/SDL.h>

class Sprite {
    public:
        Sprite(std::string, SDL_Renderer* renderer);
        void set_offset(int, int);
        void set_position(int, int);
        void move(int, int);
        void set_colorkey(int, int, int);
        virtual void update() = 0;
    protected:
        SDL_Renderer* m_renderer;
        SDL_Surface* m_image;
        SDL_Texture* m_texture;
        SDL_Rect m_position;
    private:
        SDL_Point m_offset;

};

#endif
