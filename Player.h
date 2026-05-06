#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class Player : public Entity {
public:
    Player(int x, int y, const std::string& name);

    std::string getName() const { return m_name; }

private:
    std::string m_name;
};

#endif
