//
//  Sword.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Sword.hpp"


Sword::Sword() {
    damage = 5;
}

void Sword::attack(Enemy* enemy) {
    std::cout << "Sword attacks "<<  enemy->getType() << "! (-5)" << std::endl;
    enemy->takeDamage(damage);
}
