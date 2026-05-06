#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <cassert>

void testDamageCalculation() {
    std::cout << "Running testDamageCalculation..." << std::endl;
    
    Entity enemy(0, 0, 'E', 50, 5);
    
    // Test initial HP
    assert(enemy.getHP() == 50);
    assert(enemy.isAlive() == true);
    
    // Test taking damage
    enemy.takeDamage(20);
    assert(enemy.getHP() == 30);
    assert(enemy.isAlive() == true);
    
    // Test lethal damage
    enemy.takeDamage(40);
    assert(enemy.getHP() == 0);
    assert(enemy.isAlive() == false);
    
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

int main() {
    testDamageCalculation();
    testPlayerStats();
    
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
