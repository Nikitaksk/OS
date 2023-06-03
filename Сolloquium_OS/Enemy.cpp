//
//  Enemy.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Enemy.hpp"


Enemy::Enemy() {}

void Enemy::takeDamage(int damage) {
    health -= damage;
}

int Enemy::getHealth() const {
    return health;
}


