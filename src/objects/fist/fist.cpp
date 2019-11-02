#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "fist.hpp"
#include "../chimp/chimp.hpp"

Fist::Fist(std::string resource, SDL_Renderer* renderer) :
    Sprite(resource, renderer)
{
    m_punching = false;
    set_colorkey(0, 0, 0);

    set_offset(m_image->h / 2, m_image->w / 2);

    SDL_GetMouseState(&m_position.x, &m_position.y);
    set_position(m_position.x, m_position.y);

    m_punch_sound = Mix_LoadWAV("resources/sounds/punch.wav");
    m_whiff_sound = Mix_LoadWAV("resources/sounds/whiff.wav");
}

void Fist::update() {
    SDL_GetMouseState(&m_position.x, &m_position.y);
    set_position(m_position.x, m_position.y);

    if (m_punching) {
        move(5, 10);
    }

    SDL_RenderCopy(m_renderer, m_texture, NULL, &m_position);
}

void Fist::punch(Chimp* chimp) {
    if (!m_punching) {
        m_punching = true;
        SDL_Rect chimp_rect = chimp->get_rect();

        if (SDL_HasIntersection(&m_position, &chimp_rect) == SDL_TRUE) {
            Mix_PlayChannel(-1, m_punch_sound, 0);
            chimp->punched();
        } else {
            Mix_PlayChannel(-1, m_whiff_sound, 0);
        }
    }
}

void Fist::unpunch() {
    m_punching = false;
}
