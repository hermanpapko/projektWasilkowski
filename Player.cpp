#include "Player.h"

Player::Player(int x, int y, const std::string& name)
    : Entity(x, y, '@', 100, 10), m_name(name), m_level(1), m_score(0) {}
