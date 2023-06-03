//
//  EnemyFactory.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef EnemyFactory_hpp
#define EnemyFactory_hpp

#include <stdio.h>
#include "Enemy.hpp"
#include "Goblin.hpp"
#include "Orc.hpp"
#include "Dragon.hpp"

class EnemyFactory {
public:
    static Enemy* createEnemy(std::string type) {
        if (type == "Goblin") {
            return new Goblin();
        }
        else if (type == "Orc") {
            return new Orc();
        }
        else if (type == "Dragon") {
            return new Dragon();
        }
        else {
            return nullptr;
        }
    }
};

#endif /* EnemyFactory_hpp */
