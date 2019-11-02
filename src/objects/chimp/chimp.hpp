#ifndef __CHIMP_HPP__
#define __CHIMP_HPP__


#include <string>
#include <SDL2/SDL.h>
#include "../../graphics/sprite/sprite.hpp"

class Chimp : public Sprite {
    public:
        Chimp(std::string, SDL_Renderer*);
        void update() override;
        void punched();
    private:
        int m_move_speed;
        int m_dizzy;
        SDL_RendererFlip m_flip;

        void spin();
        void walk();
};

#endif
