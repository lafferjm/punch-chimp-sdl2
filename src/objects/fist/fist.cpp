#include <string>
#include <SDL2/SDL.h>
#include "fist.hpp"

Fist::Fist(std::string resource, SDL_Renderer* renderer) {
    m_renderer = renderer;

    SDL_Surface* image = SDL_LoadBMP(resource.c_str());
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0));
    m_texture = SDL_CreateTextureFromSurface(renderer, image);

    m_position.x = 0;
    m_position.y = 0;
    m_position.h = image->h;
    m_position.w = image->w;
}

void Fist::draw() {
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_position);
}
