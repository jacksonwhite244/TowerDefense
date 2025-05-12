/**
 * @file NormalPirate.h
 * @author Jackson White
 *
 *  NormalPirate is a character (not an enemy)
 */
 
#ifndef NORMALPIRATE_H
#define NORMALPIRATE_H

#include "Character.h"

/**
 * Our first hero is a normal pirate. Most basic Character
 */
class NormalPirate : public Character {
private:
    /// the image of the normal pirate
    sf::Sprite* mSprite = nullptr;

    /// the texture of the normal pirate
    sf::Texture* mTexture = nullptr;

public:
    NormalPirate();

    sf::Sprite GetSprite() { return *mSprite; };

    void Draw(sf::RenderWindow* window) { window->draw(*mSprite); };

};



#endif //NORMALPIRATE_H
