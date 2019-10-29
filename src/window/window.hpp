#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <string>
#include <SDL2/SDL.h>

class Window {
    public:
        Window(std::string, int, int);
        bool is_open();
        void set_clear_color(int, int, int, int);
        void begin();
        void end();
        SDL_Renderer* get_renderer();
    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_is_open;
};

#endif
