//
//  SwordAttackStrategy.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef SwordAttackStrategy_hpp
#define SwordAttackStrategy_hpp

#include <stdio.h>
#include "AttackStrategy.hpp"
#include "Sword.hpp"

class SwordAttackStrategy : public AttackStrategy {
public:
    void attack(Enemy* enemy) override;
};


#endif /* SwordAttackStrategy_hpp */
