#include <string>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>

#include "text.hpp"

Text::Text(std::string message, int size, int x, int y, SDL_Renderer* renderer) {
    if (TTF_Init() < 0) {
        printf("Couldn't initialize ttf: %s\n", TTF_GetError());
        exit(1);
    }

    m_renderer = renderer;
    m_font = TTF_OpenFont("resources/fonts/freesansbold.ttf", size);

    SDL_Color black = {0, 0, 0};
    SDL_Color white = {255, 255, 255};

    m_message_surface = TTF_RenderText_Shaded(m_font, message.c_str(), black, white);
    if (m_message_surface == NULL) {
        printf("Unable to render text surface: %s\n", TTF_GetError());
        exit(1);
    }

    m_message = SDL_CreateTextureFromSurface(m_renderer, m_message_surface);
    if (m_message == NULL) {
        printf("Unable to create texture from surface: %s\n", TTF_GetError());
        exit(1);
    }

    m_message_rect.x = x;
    m_message_rect.y = y;
    m_message_rect.w = m_message_surface->w;
    m_message_rect.h = m_message_surface->h;
}

void Text::draw() {
    SDL_RenderCopy(m_renderer, m_message, NULL, &m_message_rect);
}
