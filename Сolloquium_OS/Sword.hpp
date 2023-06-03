//
//  Sword.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Sword_hpp
#define Sword_hpp

#include <stdio.h>
#include "Weapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Sword : public Weapon {
public:
    Sword();
    void attack(Enemy* enemy) override;
};


#endif /* Sword_hpp */
