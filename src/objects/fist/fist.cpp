#include <string>
#include <SDL2/SDL.h>
#include "fist.hpp"
#include "../chimp/chimp.hpp"

Fist::Fist(std::string resource, SDL_Renderer* renderer) {
    m_punching = false;
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

    if (m_punching) {
        m_position.x = m_position.x + 5;
        m_position.y = m_position.y + 10;
    }

    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_position);
}

void Fist::punch(Chimp* chimp) {
    if (!m_punching) {
        m_punching = true;
    }
}

void Fist::unpunch() {
    m_punching = false;
}
