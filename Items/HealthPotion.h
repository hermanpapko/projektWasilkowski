#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "Item.h"

class HealthPotion : public Item {
public:
    HealthPotion(int x, int y, int healAmount = 20);
    int getHealAmount() const { return m_healAmount; }

private:
    int m_healAmount;
};

#endif
