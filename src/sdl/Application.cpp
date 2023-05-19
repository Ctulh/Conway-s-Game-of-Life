//
// Created by ctuh on 5/19/23.
//

#include "sdl/Application.hpp"

#include <iostream>

Application::Application(int height, int width):
    m_window(SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, height, width, 0), [](SDL_Window* window){ SDL_DestroyWindow(window);}),
    m_width(width),
    m_height(height)
{
    m_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), [](SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer);});
}

void Application::run() {
    if(m_isRunning.test_and_set(std::memory_order_acquire)) {
       std::cout << "[APPLICATION] Application in already running" << std::endl;
        return;
    }
    std::cout << "[APPLICATION] Renderer is running" << std::endl;
    while(m_isRunning.test(std::memory_order_acquire)) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    shutDown();
                }
                case SDL_KEYUP: {
                    switch(event.key.keysym.sym) {
                        case SDLK_SPACE: {
                            m_isPause = !m_isPause;
                            std::cout << "[APPLICATION] Application is " << (m_isPause ? "Paused" : "Unpaused") << std::endl;
                            break;
                        }
                    }
                    break;
                }
                case SDL_KEYDOWN: {
                    for(auto& sdlElement: m_elements) {
                        if(sdlElement->onKeyPressed(event.key.keysym.sym))
                            break;
                    }
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    for(auto& sdlElement: m_elements) {
                        int x, y;
                        SDL_GetMouseState(&y, &x);
                        if(sdlElement->onMouseButtonDown(x, y))
                            continue;
                    }
                    break;
                }
            }
        }
        SDL_SetRenderDrawColor(m_renderer.get(), 0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_renderer.get());

            for (auto &sdlElement: m_elements) {
                if(!m_isPause)
                    sdlElement->onUpdate();
                sdlElement->draw(m_renderer);
            }
        SDL_Delay(80);

        SDL_RenderPresent(m_renderer.get());
    }
}

void Application::shutDown() {
    m_isRunning.clear(std::memory_order_release);
}

void Application::addSdlElement(std::unique_ptr<SdlElement> sdlElement) {
    sdlElement->setWindowSize(m_height, m_width);
    m_elements.push_back(std::move(sdlElement));
}