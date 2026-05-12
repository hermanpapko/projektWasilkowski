#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
    Enemy(int x, int y, char symbol = 'E', int hp = 30, int damage = 5);
};

#endif
