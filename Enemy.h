#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Map.h"

class Enemy : public Entity {
public:
    Enemy(int x, int y, char symbol = 'E', int hp = 30, int damage = 5);

    void moveRandomly(const Map& map);
};

#endif
