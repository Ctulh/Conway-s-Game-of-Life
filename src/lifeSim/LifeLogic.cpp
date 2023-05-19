//
// Created by ctuh on 5/19/23.
//

#include "lifeSim/LifeLogic.hpp"

LifeLogic::LifeLogic(int height, int width): m_height(height), m_width(width) {
    m_grid = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
    m_neighbours = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}

std::vector<std::vector<bool>> LifeLogic::getGrid() const {
    return m_grid;
}

void LifeLogic::setState(std::vector<std::vector<bool>> grid) {
    m_grid = grid;
}


void LifeLogic::invertCell(int row, int column) {
    if(std::min(row, column) < 0 || row >= m_height || column >= m_width) return;
    m_grid[row][column] = !m_grid[row][column];
    updateNeighbours(row, column, m_grid[row][column] ? 1 : -1);
}

void LifeLogic::updateNeighbours(int i, int j, int action) {
    std::vector<std::pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    for(auto& direction: directions) {
        int newRow = i + direction.first;
        int newColumn = j + direction.second;
        if(std::min(newColumn, newRow) < 0 || newRow >= m_height || newColumn >= m_width) continue;
        m_neighbours[newRow][newColumn] += action;
    }
}

void LifeLogic::update() {
    std::vector<std::pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    std::vector<std::pair<int, std::pair<int,int>>> actions;
    for(int i = 0; i < m_height; ++i) {
        for(int j = 0; j < m_width; ++j) {
            if(m_grid[i][j] == 1 && m_neighbours[i][j] < 2) {
                m_grid[i][j] = false;
                actions.emplace_back(-1, std::pair<int,int>(i,j));
            }
            else if(m_grid[i][j] == 1 && m_neighbours[i][j] > 3) {
                m_grid[i][j] = false;
                actions.emplace_back(-1, std::pair<int,int>(i,j));
            }
            else if(m_grid[i][j] == 0 && m_neighbours[i][j] == 3) {
                m_grid[i][j] = true;
                actions.emplace_back(1, std::pair<int,int>(i,j));
            }
        }
    }

    for(auto& action: actions) {
        auto pos = action.second;
        updateNeighbours(pos.first, pos.second, action.first);
    }
}