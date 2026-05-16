#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

struct RenderEntity {
    int x;
    int y;
    char symbol;
};

class Map {
public:
    Map(int width, int height);
    ~Map();

    void initialize();
    std::string render(const std::vector<RenderEntity>& entities) const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    bool isWithinBounds(int x, int y) const;
    bool isWalkable(int x, int y) const;
    bool isExit(int x, int y) const;

private:
    int m_width;
    int m_height;
    std::vector<std::string> m_grid;
};

#endif
