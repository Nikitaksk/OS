//
//  Weapon.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "Enemy.hpp"


class Weapon {
public:
    virtual void attack(Enemy* enemy) = 0;
    int getDamage();

protected:
    int damage;
};

#endif /* Weapon_hpp */
