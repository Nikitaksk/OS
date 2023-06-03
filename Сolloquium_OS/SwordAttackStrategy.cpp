//
//  SwordAttackStrategy.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "SwordAttackStrategy.hpp"


void SwordAttackStrategy::attack(Enemy* enemy) {
    Sword sword;
    std::cout << "Player attacks with a sword! \t";
    sword.attack(enemy);
}
