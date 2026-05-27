#ifndef ENTITY_H
#define ENTITY_H

/**
 * @class Entity
 * @brief Base class for all game entities (Player, Enemies).
 * 
 * Handles position, health points, damage, and basic interactions.
 */
class Entity {
public:
    /**
     * @brief Constructs a new Entity.
     * @param x Initial X coordinate.
     * @param y Initial Y coordinate.
     * @param symbol Character symbol representing the entity.
     * @param hp Initial health points.
     * @param damage Damage dealt by this entity.
     */
    Entity(int x, int y, char symbol, int hp, int damage);
    virtual ~Entity() = default;

    /** @brief Gets the current X coordinate. */
    int getX() const { return m_x; }
    
    /** @brief Gets the current Y coordinate. */
    int getY() const { return m_y; }
    
    /** @brief Gets the entity's symbol character. */
    char getSymbol() const { return m_symbol; }
    
    /** @brief Gets the current health points. */
    int getHP() const { return m_hp; }
    
    /** @brief Gets the maximum health points. */
    int getMaxHP() const { return m_maxHp; }
    
    /** @brief Gets the attack damage. */
    int getDamage() const { return m_damage; }

    /**
     * @brief Updates the entity's position.
     */
    void setPosition(int x, int y) { m_x = x; m_y = y; }

    /**
     * @brief Reduces entity's health.
     * @param amount The amount of damage to subtract. HP will not go below 0.
     */
    void takeDamage(int amount);

    /**
     * @brief Checks if the entity is still alive.
     * @return true if HP > 0, false otherwise.
     */
    bool isAlive() const { return m_hp > 0; }

protected:
    int m_x;
    int m_y;
    char m_symbol;
    int m_hp;
    int m_maxHp;
    int m_damage;
};

#endif
