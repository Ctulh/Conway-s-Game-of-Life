
#pragma once

#include <SDL2/SDL.h>

class Field {
public:
    Field(int width, int height);
    void update();
    ~Field();
private:
    int m_width;
    int m_height;
    SDL_Window* window;
    SDL_Renderer* renderer;
};