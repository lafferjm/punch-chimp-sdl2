#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../../graphics/sprite/sprite.hpp"
#include "../chimp/chimp.hpp"

class Fist : protected Sprite {
    public:
        Fist(std::string, SDL_Renderer*);
        void update() override;
        void punch(Chimp*);
        void unpunch();
    private:
        bool m_punching;

        Mix_Chunk* m_whiff_sound;
        Mix_Chunk* m_punch_sound;
};

#endif
