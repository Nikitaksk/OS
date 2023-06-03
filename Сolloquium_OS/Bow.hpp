//
//  Bow.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Bow_hpp
#define Bow_hpp

#include <stdio.h>
#include "Weapon.hpp"
#include "Enemy.hpp"
#include <iostream>

class Bow : public Weapon {
public:
    Bow();
    void attack(Enemy* enemy) override;
};


#endif /* Bow_hpp */
