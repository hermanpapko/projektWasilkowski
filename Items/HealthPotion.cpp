#include "HealthPotion.h"

HealthPotion::HealthPotion(int x, int y, int healAmount)
    : Item(x, y, '+', "Health Potion"), m_healAmount(healAmount) {}
