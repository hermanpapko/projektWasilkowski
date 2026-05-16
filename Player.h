#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class Player : public Entity {
public:
    Player(int x, int y, const std::string& name);

    std::string getName() const { return m_name; }
    int getLevel() const { return m_level; }
    int getScore() const { return m_score; }
    
    void addScore(int points) { m_score += points; }
    void levelUp() { m_level++; }

private:
    std::string m_name;
    int m_level;
    int m_score;
};

#endif
