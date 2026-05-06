#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity(int x, int y, char symbol);
    virtual ~Entity() = default;

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    char getSymbol() const { return m_symbol; }

    void setPosition(int x, int y) { m_x = x; m_y = y; }

protected:
    int m_x;
    int m_y;
    char m_symbol;
};

#endif
