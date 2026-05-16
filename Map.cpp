#include "Map.h"
#include <iostream>

// ANSI Color Codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

    // Add exit tile
    if (m_width > 2 && m_height > 2) {
        m_grid[m_height - 2][m_width - 2] = '>';
    }
}

std::string Map::render(const std::vector<RenderEntity>& entities) const {
    std::string result = "";
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            char symbol = m_grid[y][x];
            std::string colorPrefix = "";
            
            // Determine color for the base map cell
            if (symbol == '#') colorPrefix = ANSI_COLOR_GRAY;
            else if (symbol == '>') colorPrefix = ANSI_COLOR_YELLOW;
            else if (symbol == '.') colorPrefix = ""; // Default floor

            // Check if any entity is at this position
            for (const auto& entity : entities) {
                if (entity.x == x && entity.y == y) {
                    symbol = entity.symbol;
                    if (symbol == '@') colorPrefix = ANSI_COLOR_GREEN;
                    else if (symbol == 'E') colorPrefix = ANSI_COLOR_RED;
                    break;
                }
            }
            
            if (colorPrefix != "") {
                result += colorPrefix + symbol + ANSI_COLOR_RESET;
            } else {
                result += symbol;
            }
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
    char cell = m_grid[y][x];
    return cell == '.' || cell == '>'; // Floor and Exit are walkable
}

bool Map::isExit(int x, int y) const {
    if (!isWithinBounds(x, y)) return false;
    return m_grid[y][x] == '>';
}
