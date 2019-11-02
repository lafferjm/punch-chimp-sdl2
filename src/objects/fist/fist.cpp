#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "fist.hpp"
#include "../chimp/chimp.hpp"

#include <stdio.h>

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

    m_punch_sound = Mix_LoadWAV("resources/sounds/punch.wav");
    m_whiff_sound = Mix_LoadWAV("resources/sounds/whiff.wav");
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
