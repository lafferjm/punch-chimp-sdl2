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

    m_move_speed = 9;
    m_dizzy = 0;

    m_flip = SDL_FLIP_NONE;
}

void Chimp::draw() {
    if (m_dizzy > 0) {
        spin();
    } else {
        walk();
    }

    SDL_RenderCopyEx(m_renderer, m_texture, NULL, &m_position, m_dizzy, NULL, m_flip);
}

void Chimp::spin() {
    m_dizzy = m_dizzy + 12;
    if (m_dizzy >= 360) {
        m_dizzy = 0;
    }
}

void Chimp::walk() {
    float new_position = m_position.x + m_move_speed;
    int right_bounds = 0;
    SDL_GetRendererOutputSize(m_renderer, &right_bounds, NULL);

    if (new_position >= right_bounds - m_position.w) {
        m_move_speed = m_move_speed * -1;
        new_position = m_position.x + m_move_speed;
        m_flip = SDL_FLIP_HORIZONTAL;
    } else if (new_position <= 0) {
        m_move_speed = m_move_speed * -1;
        new_position = m_position.x + m_move_speed;
        m_flip = SDL_FLIP_NONE;
    }

    m_position.x = new_position;
}

void Chimp::punched() {
    if (!m_dizzy) {
        m_dizzy = 1;
    }
}

SDL_Rect Chimp::get_rect() {
    return m_position;
}
