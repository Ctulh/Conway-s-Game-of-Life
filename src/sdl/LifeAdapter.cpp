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
            SDL_Rect r;
            r.x = j * m_squareSide;
            r.y = i * m_squareSide;
            r.w = m_squareSide;
            r.h = m_squareSide;
            if(grid[i][j]) {
                SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderFillRect(renderer.get(), &r);
            }
            else {
                if(!m_shouldDrawGrid)
                    continue;
                SDL_SetRenderDrawColor(renderer.get(), 180, 180, 180, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawRect(renderer.get(), &r);
            }
        }
    }
}

bool LifeAdapter::onKeyPressed(int key) {
    if(key == SDLK_c) {
        toggleGrid();
        return true;
    }
    return false;
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
    int gridSize = getHeight();
    m_squareSide = std::min(height / gridSize, width/ gridSize);
}

void LifeAdapter::toggleGrid() {
    m_shouldDrawGrid = !m_shouldDrawGrid;
}

void LifeAdapter::onUpdate() {
    update();
}