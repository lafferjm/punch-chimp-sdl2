#include <string>
#include <SDL2/SDL_ttf.h>

#include "text.hpp"

Text::Text(std::string message, int size, int x, int y, SDL_Renderer* renderer) {
    m_renderer = renderer;
    m_font = TTF_OpenFont("resources/fonts/freesansbold.ttf", size);
    
    SDL_Color black = {0, 0, 0};

    m_message_surface = TTF_RenderText_Solid(m_font, message.c_str(), black);
    m_message = SDL_CreateTextureFromSurface(renderer, m_message_surface);

    m_message_rect.x = x;
    m_message_rect.y = y;
}

void Text::draw() {
    SDL_RenderCopy(m_renderer, m_message, NULL, &m_message_rect);
}
