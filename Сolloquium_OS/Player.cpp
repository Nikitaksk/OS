//
//  Player.cpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//
#include <iostream>
#include "Player.hpp"
#include "SwordAttackStrategy.hpp"
#include "BowAttackStrategy.hpp"


Player::Player(std::string weaponType) {
    if (weaponType == "Sword") {
        attackStrategy = new SwordAttackStrategy();
        std::cout << "Player with a sword was created!" << std::endl;
        
    }
    else if (weaponType == "Bow") {
            attackStrategy = new BowAttackStrategy();
        std::cout << "Player with a bow was created!" << std::endl;
    }
    else {
        attackStrategy = nullptr;
        std::cout << "Player without a weapon" << std::endl;
    }
}

void Player::attack(Enemy* enemy) {
    if (attackStrategy != nullptr) {
        attackStrategy->attack(enemy);
    }
}
