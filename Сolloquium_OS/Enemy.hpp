//
//  Enemy.hpp
//  Сolloquium_OS
//
//  Created by Nikita Kasiak on 26/04/2023.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <string>

class Enemy {
public:
    virtual ~Enemy() {}
    virtual void attack() const = 0;
    virtual int getHealth() const = 0;
    virtual int getSpeed() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual std::string getType() const = 0;
protected:
    Enemy();
    int health;
    int speed;
};

#endif /* Enemy_hpp */
