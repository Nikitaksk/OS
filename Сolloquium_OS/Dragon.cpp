//
//  Dragon.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#include "Dragon.hpp"
#include <iostream>
#include <string>


Dragon::Dragon() : health(50), speed(5){
    std::cout << "Dragon was spawned!" << std::endl;
}

int Dragon::getHealth() const {
    return 50;
}

int Dragon::getSpeed() const {
    return 1;
}

void Dragon::takeDamage(int damage) {
    health -= damage;
        if (health < 0) {
            health = 0;
        }
}

std::string Dragon::getType() const {
    return "Dragon";
}
void Dragon::attack() const {
        std::cout << "Dragon attacks with claws!" << std::endl;
    }
