
#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "events/Event.hpp"
#include "events/MouseEvent.hpp"

class SdlElement: public Event, public MouseEvent {
public:
    virtual ~SdlElement() = default;

public:
    virtual void draw(std::shared_ptr<SDL_Renderer> renderer) const = 0;
    virtual void setWindowSize(int height, int width) = 0;
};