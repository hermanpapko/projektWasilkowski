#ifndef GOLD_CHEST_H
#define GOLD_CHEST_H

#include "Item.h"

class GoldChest : public Item {
public:
    GoldChest(int x, int y, int goldValue = 50);
    int getGoldValue() const { return m_goldValue; }

private:
    int m_goldValue;
};

#endif
