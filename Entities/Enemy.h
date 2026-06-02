#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Map.h"
#include <vector>
#include <memory>

class Player; // Forward declaration

/**
 * @class Enemy
 * @brief Represents hostile entities that move and attack the player.
 */
class Enemy : public Entity {
public:
    /**
     * @brief Constructs a new Enemy.
     * @param x Initial X coordinate.
     * @param y Initial Y coordinate.
     * @param symbol Character symbol (defaults to 'E').
     * @param hp Initial health (defaults to 30).
     * @param damage Attack damage (defaults to 5).
     */
    Enemy(int x, int y, char symbol = 'E', int hp = 30, int damage = 5);

    /**
     * @brief Executes a random movement step or attacks the player.
     * @param map The current game map for collision checks.
     * @param enemies List of all enemies to prevent overlapping.
     * @param player Reference to the player for combat detection.
     * @return true if an attack occurred, false otherwise.
     */
    bool moveRandomly(const Map& map, const std::vector<std::unique_ptr<Enemy>>& enemies, Player& player);
};

#endif
