
#pragma once

#include "SdlElement.hpp"

#include <memory>
#include <vector>
#include <atomic>

#include <SDL2/SDL.h>

class Application {
public:
    Application(int height, int width);
public:
    void run();
    void shutDown();
    void addSdlElement(std::unique_ptr<SdlElement> sdlElement);
private:
    std::vector<std::unique_ptr<SdlElement>> m_elements;
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;
    std::atomic_flag m_isRunning = false;
    bool m_isPause = true;
    int m_height;
    int m_width;
};