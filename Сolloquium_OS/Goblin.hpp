//
//  Goblin.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Goblin_hpp
#define Goblin_hpp

#include <stdio.h>
#include "Enemy.hpp"

class Goblin : public Enemy {
public:
    Goblin();
    int getHealth() const override;
    int getSpeed() const override;
    void takeDamage(int damage) override;
    std::string getType() const override;
    void attack() const override;
protected:
    int health;
    int speed;
};



#endif /* Goblin_hpp */
