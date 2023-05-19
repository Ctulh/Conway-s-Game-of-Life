
#pragma once

#include "lifeSim/LifeLogic.hpp"
#include "SdlElement.hpp"

class LifeAdapter: public SdlElement, public LifeLogic {
public:
    LifeAdapter(int height, int width);

public:
    void onUpdate() override;
    void draw(std::shared_ptr<SDL_Renderer> renderer) const override;
    void setWindowSize(int height, int width) override;
    bool onMouseButtonDown(int x, int y) override;
private:
    int m_windowHeight = 0;
    int m_windowWidth = 0;
    int m_squareSide = 100;
};