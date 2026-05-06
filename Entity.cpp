#include "Entity.h"
#include <algorithm>

Entity::Entity(int x, int y, char symbol, int hp, int damage)
    : m_x(x), m_y(y), m_symbol(symbol), m_hp(hp), m_damage(damage) {}

void Entity::takeDamage(int amount) {
    m_hp -= amount;
    if (m_hp < 0) m_hp = 0;
}
