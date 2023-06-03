//
//  Bow.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Bow.hpp"


Bow::Bow() {
    damage = 3;
}

void Bow::attack(Enemy* enemy) {
    std::cout << "Bow attacks "<<  enemy->getType() << "! (-3)" << std::endl;
    enemy->takeDamage(damage);
}
