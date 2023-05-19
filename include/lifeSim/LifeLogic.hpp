
#pragma once

#include <vector>

class LifeLogic {
public:
    LifeLogic(int height, int width);

public:
    void setState(std::vector<std::vector<bool>> grid);
    void invertCell(int row, int column);
public:
    std::vector<std::vector<bool>> getGrid() const;
    void update();

private:
    void updateNeighbours(int i, int j, int action);
private:
    std::vector<std::vector<int>> m_neighbours;
    std::vector<std::vector<bool>> m_grid;
    int m_height;
    int m_width;
};
