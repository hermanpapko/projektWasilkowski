#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cassert>

void testDamageCalculation() {
    std::cout << "Running testDamageCalculation..." << std::endl;
    
    Entity entity(0, 0, 'E', 50, 5);
    
    // Test initial HP
    assert(entity.getHP() == 50);
    assert(entity.isAlive() == true);
    
    // Test taking damage
    entity.takeDamage(20);
    assert(entity.getHP() == 30);
    assert(entity.isAlive() == true);
    
    // Test lethal damage
    entity.takeDamage(40);
    assert(entity.getHP() == 0);
    assert(entity.isAlive() == false);
    
    std::cout << "testDamageCalculation passed!" << std::endl;
}

void testPlayerStats() {
    std::cout << "Running testPlayerStats..." << std::endl;
    
    Player player(5, 5, "Hero");
    assert(player.getHP() == 100);
    assert(player.getDamage() == 10);
    assert(player.getSymbol() == '@');
    assert(player.getName() == "Hero");
    
    std::cout << "testPlayerStats passed!" << std::endl;
}

void testEnemyStats() {
    std::cout << "Running testEnemyStats..." << std::endl;
    
    Enemy enemy(10, 10);
    assert(enemy.getHP() == 30);
    assert(enemy.getDamage() == 5);
    assert(enemy.getSymbol() == 'E');
    assert(enemy.getX() == 10);
    assert(enemy.getY() == 10);
    
    Enemy strongEnemy(2, 2, 'S', 100, 20);
    assert(strongEnemy.getHP() == 100);
    assert(strongEnemy.getDamage() == 20);
    assert(strongEnemy.getSymbol() == 'S');
    
    std::cout << "testEnemyStats passed!" << std::endl;
}

int main() {
    testDamageCalculation();
    testPlayerStats();
    testEnemyStats();
    
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
