/**
 * @file Monster.h
 * @author Jackson White
 *
 * Monster Character
 */
 
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"


/**
 * Monster character.
 *
 * Has all the same function as the base character, jump, attack, walk
 */
class Monster : public Character {
private:

public:
    Monster() = delete;
    Monster(int playerNum);
    void Animate();
    void AdjustJump();
};



#endif //MONSTER_H
