//
//  BowAttackStrategy.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef BowAttackStrategy_hpp
#define BowAttackStrategy_hpp

#include <stdio.h>
#include "AttackStrategy.hpp"
#include "Bow.hpp"
#include "Enemy.hpp"

class BowAttackStrategy : public AttackStrategy {
public:
    void attack(Enemy* enemy) override;
};


#endif /* BowAttackStrategy_hpp */
