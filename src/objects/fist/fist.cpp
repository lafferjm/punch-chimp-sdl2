#include <string>
#include <SDL2/SDL.h>
#include "fist.hpp"

Fist::Fist(std::string resource, SDL_Renderer* renderer) {
    m_renderer = renderer;

    SDL_Surface* image = SDL_LoadBMP(resource.c_str());
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0));
    m_texture = SDL_CreateTextureFromSurface(renderer, image);

    m_position.w = image->w;
    m_position.h = image->h;

    m_x_offset = image->h / 2;
    m_y_offset = image->w / 2;

    SDL_GetMouseState(&m_position.x, &m_position.y);
    m_position.x = m_position.x - m_x_offset;
    m_position.y = m_position.y - m_y_offset;
}

void Fist::draw() {
    SDL_GetMouseState(&m_position.x, &m_position.y);
    m_position.x = m_position.x - m_x_offset;
    m_position.y = m_position.y - m_y_offset;

    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_position);
}
