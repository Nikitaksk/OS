//
//  BowAttackStrategy.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "BowAttackStrategy.hpp"
#include "Enemy.hpp"

void BowAttackStrategy::attack(Enemy* enemy) {
    Bow bow;
    std::cout << "Player attacks with a bow! \t";
    bow.attack(enemy);
}
