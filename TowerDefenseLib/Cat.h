/**
 * @file Cat.h
 * @author jacks
 *
 * Cat character that can fight
 */
 
#ifndef CAT_H
#define CAT_H

#include "Character.h"

/**
 * Cat character
 *
 * can be controlled by the user to fight other characters
 */
class Cat : public Character {
private:

public:
    Cat() = delete;

    Cat(int playerNum);
    void Animate();
    void AdjustJump();
};



#endif //CAT_H
