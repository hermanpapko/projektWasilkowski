#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Map.h"
#include <vector>
#include <memory>

class Player; // Forward declaration

class Enemy : public Entity {
public:
    Enemy(int x, int y, char symbol = 'E', int hp = 30, int damage = 5);

    bool moveRandomly(const Map& map, const std::vector<std::unique_ptr<Enemy>>& enemies, Player& player);
};

#endif
