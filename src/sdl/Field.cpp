//
// Created by ctuh on 5/18/23.
//
#include "sdl/Field.hpp"

#include <SDL2/SDL.h>


namespace {
    int squareSize = 50;
    const int DELAY = 24;
}

Field::Field(int width, int height): m_height(height), m_width(width) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
    }
    window = SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Delay(DELAY);
    renderer = SDL_CreateRenderer(window, 1, 0);
}

void Field::update() {
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderPresent(renderer);
}

Field::~Field() {
    SDL_DestroyWindow(window);
}