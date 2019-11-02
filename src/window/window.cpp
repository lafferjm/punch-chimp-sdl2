#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "window.hpp"

Window::Window(std::string title, int width, int height) {
    m_window = nullptr;
    m_renderer = nullptr;
    m_is_open = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    if (TTF_Init() < 0) {
        printf("Couldn't initialize ttf: %s\n", TTF_GetError());
        exit(1);
    }

    SDL_ShowCursor(SDL_DISABLE);
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (!m_window) {
        printf("Failed to open window: %s\n", SDL_GetError());
        exit(1);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
}

bool Window::is_open() {
    return m_is_open;
}

void Window::set_clear_color(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Window::begin() {
    SDL_RenderClear(m_renderer);
}

void Window::end() {
    SDL_RenderPresent(m_renderer);
}

SDL_Renderer* Window::get_renderer() {
    return m_renderer;
}
