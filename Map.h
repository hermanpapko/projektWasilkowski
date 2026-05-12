#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map {
public:
    Map(int width, int height);
    ~Map();

    void initialize();
    std::string render(int playerX, int playerY) const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    bool isWithinBounds(int x, int y) const;
    bool isWalkable(int x, int y) const;

private:
    int m_width;
    int m_height;
    std::vector<std::string> m_grid;
};

#endif
