#include "Map.h"
#include <iostream>

Map::Map(int width, int height) : m_width(width), m_height(height) {
    initialize();
}

Map::~Map() {}

void Map::initialize() {
    m_grid.clear();
    for (int y = 0; y < m_height; ++y) {
        std::string row = "";
        for (int x = 0; x < m_width; ++x) {
            if (x == 0 || x == m_width - 1 || y == 0 || y == m_height - 1) {
                row += "#"; // Wall
            } else {
                row += "."; // Floor
            }
        }
        m_grid.push_back(row);
    }
}

void Map::render() const {
    for (const auto& row : m_grid) {
        std::cout << row << std::endl;
    }
}
