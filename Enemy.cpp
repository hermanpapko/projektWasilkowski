#include "Enemy.h"
#include <random>

Enemy::Enemy(int x, int y, char symbol, int hp, int damage)
    : Entity(x, y, symbol, hp, damage) {}

void Enemy::moveRandomly(const Map& map) {
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

    if (map.isWalkable(nextX, nextY)) {
        m_x = nextX;
        m_y = nextY;
    }
}
