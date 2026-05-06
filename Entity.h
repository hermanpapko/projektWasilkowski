#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    Entity(int x, int y, char symbol, int hp, int damage);
    virtual ~Entity() = default;

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    char getSymbol() const { return m_symbol; }
    int getHP() const { return m_hp; }
    int getDamage() const { return m_damage; }

    void setPosition(int x, int y) { m_x = x; m_y = y; }
    void takeDamage(int amount);
    bool isAlive() const { return m_hp > 0; }

protected:
    int m_x;
    int m_y;
    char m_symbol;
    int m_hp;
    int m_damage;
};

#endif
