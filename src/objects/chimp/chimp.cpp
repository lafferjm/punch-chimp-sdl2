#include <string>
#include <SDL2/SDL.h>
#include "chimp.hpp"

Chimp::Chimp(std::string resource, SDL_Renderer* renderer) {
    m_renderer = renderer;

    SDL_Surface* image = SDL_LoadBMP(resource.c_str());
    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 0, 0));
    m_texture = SDL_CreateTextureFromSurface(renderer, image);

    m_x_offset = image->h / 2;
    m_y_offset = image->w / 2;

    m_position.w = image->w;
    m_position.h = image->h;
    m_position.x = 0;
    m_position.y = 0;
}

void Chimp::draw() {
    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_position);
}
