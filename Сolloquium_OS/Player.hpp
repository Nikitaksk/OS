//
//  Player.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "AttackStrategy.hpp"
#include "Enemy.hpp"
#include <string>

class Player {
public:
    Player(std::string weaponType);
    void attack(Enemy* enemy);
private:
    AttackStrategy* attackStrategy;
};


#endif /* Player_hpp */
