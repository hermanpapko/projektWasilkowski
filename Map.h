#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map {
public:
    Map(int width, int height);
    ~Map();

    void initialize();
    void render() const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

private:
    int m_width;
    int m_height;
    std::vector<std::string> m_grid;
};

#endif
