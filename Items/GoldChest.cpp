#include "GoldChest.h"

GoldChest::GoldChest(int x, int y, int goldValue)
    : Item(x, y, '$', "Gold Chest"), m_goldValue(goldValue) {}
