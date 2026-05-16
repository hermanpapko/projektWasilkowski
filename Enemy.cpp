#include "Enemy.h"
#include "Player.h"
#include <random>

Enemy::Enemy(int x, int y, char symbol, int hp, int damage)
    : Entity(x, y, symbol, hp, damage) {}

bool Enemy::moveRandomly(const Map& map, const std::vector<std::unique_ptr<Enemy>>& enemies, Player& player) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4); // 0: Stay, 1: Up, 2: Down, 3: Left, 4: Right

    int dir = dis(gen);
    int nextX = m_x;
    int nextY = m_y;

    switch (dir) {
        case 1: nextY--; break;
        case 2: nextY++; break;
        case 3: nextX--; break;
        case 4: nextX++; break;
        default: break; // Stay put
    }

    if (!map.isWalkable(nextX, nextY)) {
        return false;
    }

    // Check collision with player
    if (nextX == player.getX() && nextY == player.getY()) {
        // Combat logic: Enemy attacks player, player counter-attacks
        player.takeDamage(m_damage);
        this->takeDamage(player.getDamage());
        return true;
    }

    bool occupied = false;
    for (const auto& other : enemies) {
        if (other.get() != this && other->getX() == nextX && other->getY() == nextY) {
            occupied = true;
            break;
        }
    }

    if (!occupied) {
        m_x = nextX;
        m_y = nextY;
    }
    return false;
}
