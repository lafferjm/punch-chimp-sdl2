#include <string>
#include <SDL2/SDL.h>
#include "chimp.hpp"

Chimp::Chimp(std::string resource, SDL_Renderer* renderer) :
    Sprite(resource, renderer)
{
    set_colorkey(255, 0, 0);
    set_offset(0, 0);
    set_position(0, 0);

    m_move_speed = 9;
    m_dizzy = 0;

    m_flip = SDL_FLIP_NONE;
}

void Chimp::update() {
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

    set_position(new_position, get_position().y);
}

void Chimp::punched() {
    if (!m_dizzy) {
        m_dizzy = 1;
    }
}
