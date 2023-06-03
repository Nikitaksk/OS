//
//  Orc.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Orc.hpp"
#include <iostream>
#include <string>

Orc::Orc() : health(20), speed(5) {
    std::cout << "Orc was spawned!" << std::endl;
};

int Orc::getHealth() const {
    return health;
}

int Orc::getSpeed() const {
    return speed;
}

void Orc::takeDamage(int damage) {
    health -= damage;
        if (health < 0) {
            health = 0;
        }
}

std::string Orc::getType() const {
    return "Orc";
}
void Orc::attack() const {
        std::cout << "Orc attacks with claws!" << std::endl;
    }
