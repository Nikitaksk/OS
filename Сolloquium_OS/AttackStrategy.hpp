//
//  AttackStrategy.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef AttackStrategy_hpp
#define AttackStrategy_hpp

#include <stdio.h>
#include "Enemy.hpp"

class AttackStrategy {
public:
    virtual void attack(Enemy* enemy) = 0;
};

#endif /* AttackStrategy_hpp */
