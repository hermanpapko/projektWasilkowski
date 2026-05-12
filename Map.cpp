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
                row += "#"; // Perimeter Wall
            } else {
                row += "."; // Floor
            }
        }
        m_grid.push_back(row);
    }

    // Add some internal pillars for testing collisions later
    if (m_width > 15 && m_height > 8) {
        m_grid[3][5] = '#';
        m_grid[3][14] = '#';
        m_grid[6][5] = '#';
        m_grid[6][14] = '#';
    }
}

std::string Map::render(const std::vector<RenderEntity>& entities) const {
    std::string result = "";
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            char symbolToRender = m_grid[y][x];
            
            // Check if any entity is at this position
            for (const auto& entity : entities) {
                if (entity.x == x && entity.y == y) {
                    symbolToRender = entity.symbol;
                    break;
                }
            }
            
            result += symbolToRender;
        }
        result += "\n";
    }
    return result;
}

bool Map::isWithinBounds(int x, int y) const {
    return (x >= 0 && x < m_width && y >= 0 && y < m_height);
}

bool Map::isWalkable(int x, int y) const {
    if (!isWithinBounds(x, y)) {
        return false;
    }
    return m_grid[y][x] == '.'; // Only floor is walkable
}
