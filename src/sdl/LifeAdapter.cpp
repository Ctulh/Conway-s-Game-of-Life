//
// Created by ctuh on 5/19/23.
//

#include "sdl/LifeAdapter.hpp"


LifeAdapter::LifeAdapter(int height, int width): LifeLogic(height, width) {}

void LifeAdapter::draw(std::shared_ptr<SDL_Renderer> renderer) const {
    auto grid = getGrid();
    int rows = grid.size();
    int columns = grid.begin()->size();

    for(int i = 0 ; i < rows; ++i) {
        for(int j = 0 ; j < columns; ++j) {
            if(!grid[i][j]) continue;
            SDL_Rect r;
            r.x = j * m_squareSide;
            r.y = i * m_squareSide;
            r.w = m_squareSide;
            r.h = m_squareSide;
            if(grid[i][j]) {
                SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer.get(), &r);
            }
        }
    }
}

bool LifeAdapter::onMouseButtonDown(int x, int y) {
    int cellRow = x / m_squareSide;
    int cellColumn = y / m_squareSide;
    invertCell(cellRow, cellColumn);
    return true;
}

void LifeAdapter::setWindowSize(int height, int width) {
    m_windowHeight = height;
    m_windowWidth = width;
    m_squareSide = height / getGrid().size();
}

void LifeAdapter::onUpdate() {
    update();
}