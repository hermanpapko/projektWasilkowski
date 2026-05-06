#include "Player.h"

Player::Player(int x, int y, const std::string& name)
    : Entity(x, y, '@'), m_name(name) {}
