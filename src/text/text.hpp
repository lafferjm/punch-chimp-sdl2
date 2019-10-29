#ifndef __TEXT_HPP__
#define __TEXT_HPP__

#include <string>
#include <SDL2/SDL_ttf.h>

class Text {
    public:
        Text(std::string, int, int, int, SDL_Renderer*);
        void draw();
    private:
        TTF_Font* m_font;
        SDL_Surface* m_message_surface;
        SDL_Texture* m_message;
        SDL_Rect m_message_rect;

        SDL_Renderer* m_renderer;
};

#endif
