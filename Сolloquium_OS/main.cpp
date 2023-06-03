//
//  main.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include <iostream>
#include <string>
#include "EnemyFactory.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"
#include "Player.hpp"

//class Bow : public Weapon {
//public:
//    Bow() {
//        damage = 3;
//    }
//    void attack(Enemy* enemy) override {
//        std::cout << "Bow attacks enemy!" << std::endl;
//        enemy->attack();
//    }
//};
//
//class BowAttackStrategy : public AttackStrategy {
//public:
//    void attack(Enemy* enemy) override {
//        Bow bow;
//        std::cout << "Player attacks with bow!" << std::endl;
//        bow.attack(enemy);
//    }
//};


int main() {
    Enemy* enemy1 = EnemyFactory::createEnemy("Goblin");
    Enemy* enemy2 = EnemyFactory::createEnemy("Orc");
    Enemy* enemy3 = EnemyFactory::createEnemy("Dragon");
    
    Player player1("Sword");
    
    Player player2("Bow");
    
    std::cout << "Current Goblin health: " << enemy1->getHealth() << std::endl;
    
    
    player1.attack(enemy1);
    
    std::cout << "Current Goblin health: " << enemy1->getHealth() << std::endl;
    
    player2.attack(enemy1);
    
    std::cout << "Current Goblin health: " << enemy1->getHealth() << std::endl;
    
    player2.attack(enemy1);
    
    std::cout << "Current Goblin health: " << enemy1->getHealth() << std::endl;
    
    delete enemy1;
    delete enemy2;
    delete enemy3;
    
    return 0;
}

