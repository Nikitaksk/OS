//
//  Goblin.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Goblin.hpp"
#include <iostream>
#include <string>

Goblin::Goblin() : health(10), speed(5) {
    std::cout << "Goblin was spawned!" << std::endl;
};

int Goblin::getHealth() const {
    return health;
}

int Goblin::getSpeed() const {
    return speed;
}

void Goblin::takeDamage(int damage) {
    health -= damage;
        if (health < 0) {
            health = 0;
        }
}

std::string Goblin::getType() const {
    return "Goblin";
}
void Goblin::attack() const {
        std::cout << "Goblin attacks with claws!" << std::endl;
    }


