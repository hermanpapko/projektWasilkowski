#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

struct RenderEntity {
    int x;
    int y;
    char symbol;
};

/**
 * @class Map
 * @brief Represents the game world grid.
 * 
 * Manages the layout of walls, floors, and the exit.
 */
class Map {
public:
    /**
     * @brief Constructs a Map with specified dimensions.
     */
    Map(int width, int height);
    ~Map();

    /**
     * @brief Initializes the map with a perimeter and internal structures.
     */
    void initialize();

    /**
     * @brief Generates a console-friendly string representation of the map.
     * @param entities List of entities to include in the render.
     * @return String with ANSI color codes.
     */
    std::string render(const std::vector<RenderEntity>& entities) const;

    /**
     * @brief Retrieves the character symbol at a specific coordinate.
     */
    char getCell(int x, int y) const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    /**
     * @brief Checks if a position is within map boundaries.
     */
    bool isWithinBounds(int x, int y) const;

    /**
     * @brief Checks if a tile can be walked upon.
     */
    bool isWalkable(int x, int y) const;

    /**
     * @brief Checks if a tile is the exit.
     */
    bool isExit(int x, int y) const;

private:
    int m_width;
    int m_height;
    std::vector<std::string> m_grid;
};

#endif
