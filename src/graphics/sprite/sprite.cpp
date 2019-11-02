#include <string>
#include <SDL2/SDL.h>
#include "sprite.hpp"

#include <stdio.h>

Sprite::Sprite(std::string resource, SDL_Renderer* renderer) {
    m_renderer = renderer;

    m_offset.x = 0;
    m_offset.y = 0;

    m_image = SDL_LoadBMP(resource.c_str());
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_image);

    m_position.w = m_image->w;
    m_position.h = m_image->h;
}

void Sprite::set_offset(int x, int y) {
    m_offset.x = x;
    m_offset.y = y;
}

void Sprite::set_position(int x, int y) {
    m_position.x = x - m_offset.x;
    m_position.y = y - m_offset.y;
}

void Sprite::move(int x, int y) {
    m_position.x = m_position.x + x;
    m_position.y = m_position.y + y;
}

void Sprite::set_colorkey(int r, int g, int b) {
    SDL_SetColorKey(m_image, SDL_TRUE, SDL_MapRGB(m_image->format, r, g, b));
    m_texture = SDL_CreateTextureFromSurface(m_renderer, m_image);
}

SDL_Point Sprite::get_offset() {
    return m_offset;
}

SDL_Rect Sprite::get_rect() {
    return m_position;
}

SDL_Point Sprite::get_position() {
    SDL_Point point;
    point.x = m_position.x;
    point.y = m_position.y;

    return point;
}
