#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

/**
 * @class Player
 * @brief Represents the player character controlled by the user.
 * 
 * Inherits from Entity and adds name, level, and score management.
 */
class Player : public Entity {
public:
    /**
     * @brief Constructs a new Player.
     * @param x Initial X coordinate.
     * @param y Initial Y coordinate.
     * @param name Name of the hero.
     */
    Player(int x, int y, const std::string& name);

    /** @brief Gets the player's name. */
    std::string getName() const { return m_name; }
    
    /** @brief Gets the player's current level. */
    int getLevel() const { return m_level; }
    
    /** @brief Gets the player's current score. */
    int getScore() const { return m_score; }
    
    /**
     * @brief Adds points to the player's score.
     */
    void addScore(int points) { m_score += points; }
    
    /**
     * @brief Increases the player's level.
     */
    void levelUp() { m_level++; }

private:
    std::string m_name;
    int m_level;
    int m_score;
};

#endif
