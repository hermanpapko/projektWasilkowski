#include "Entity.h"
#include <algorithm>

Entity::Entity(int x, int y, char symbol, int hp, int damage)
    : m_x(x), m_y(y), m_symbol(symbol), m_hp(hp < 0 ? 0 : hp), m_maxHp(hp < 0 ? 0 : hp), m_damage(damage < 0 ? 0 : damage) {}

void Entity::takeDamage(int amount) {
    if (amount <= 0) return;
    m_hp = std::max(0, m_hp - amount);
}
