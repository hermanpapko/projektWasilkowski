#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include <iostream>
#include <cassert>
#include <vector>

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

void testMapRendering() {
    std::cout << "Running testMapRendering..." << std::endl;
    
    Map map(5, 5);
    
    std::vector<RenderEntity> entities = {
        {1, 1, '@'},
        {3, 3, 'E'}
    };
    
    std::string rendered = map.render(entities);
    
    assert(rendered.find('@') != std::string::npos);
    assert(rendered.find('E') != std::string::npos);
    
    assert(rendered[7] == '@');
    assert(rendered[21] == 'E');
    
    std::cout << "testMapRendering passed!" << std::endl;
}

void testEnemyAI() {
    std::cout << "Running testEnemyAI..." << std::endl;
    
    Map map(10, 10);
    std::vector<std::unique_ptr<Enemy>> enemies;
    enemies.push_back(std::make_unique<Enemy>(5, 5));
    
    Enemy* enemy = enemies[0].get();
    int initialX = enemy->getX();
    int initialY = enemy->getY();
    
    bool moved = false;
    for (int i = 0; i < 100; ++i) {
        enemy->moveRandomly(map, enemies);
        if (enemy->getX() != initialX || enemy->getY() != initialY) {
            moved = true;
            break;
        }
    }
    
    assert(moved == true);
    
    Enemy wallEnemy(1, 1); 
    std::vector<std::unique_ptr<Enemy>> wallEnemies;
    for (int i = 0; i < 100; ++i) {
        wallEnemy.moveRandomly(map, wallEnemies);
        assert(map.isWalkable(wallEnemy.getX(), wallEnemy.getY()));
    }

    std::vector<std::unique_ptr<Enemy>> collisionEnemies;
    collisionEnemies.push_back(std::make_unique<Enemy>(2, 2)); 
    collisionEnemies.push_back(std::make_unique<Enemy>(1, 2)); 
    
    Enemy* movingEnemy = collisionEnemies[1].get();
    for (int i = 0; i < 200; ++i) {
        movingEnemy->moveRandomly(map, collisionEnemies);
        assert(!(movingEnemy->getX() == 2 && movingEnemy->getY() == 2));
    }
    
    std::cout << "testEnemyAI passed!" << std::endl;
}

int main() {
    testDamageCalculation();
    testPlayerStats();
    testEnemyStats();
    testMapRendering();
    testEnemyAI();
    
    std::cout << "\nAll tests passed successfully!" << std::endl;
    return 0;
}
