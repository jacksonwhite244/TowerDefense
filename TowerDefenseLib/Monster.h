/**
 * @file Monster.h
 * @author Jackson White
 *
 * Monster Character
 */
 
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
class Game;


/**
 * Monster character.
 *
 * Has all the same function as the base character, jump, attack, walk
 */
class Monster : public Character {
private:

public:
    Monster() = delete;
    Monster(int playerNum, Game* game);
    void Animate();
    void AdjustJump();
    sf::FloatRect GetHurtbox() override;
};



#endif //MONSTER_H
