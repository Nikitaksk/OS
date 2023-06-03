//
//  Dragon.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Dragon_hpp
#define Dragon_hpp

#include <stdio.h>

#include "Enemy.hpp"

class Dragon : public Enemy {
public:
    Dragon();
    
    int getHealth() const override;
    int getSpeed() const override;
    void takeDamage(int damage) override;
    std::string getType() const override;
    void attack() const override;
protected:
    int health;
    int speed;
};


#endif /* Dragon_hpp */
