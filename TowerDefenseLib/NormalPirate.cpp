/**
 * @file NormalPirate.cpp
 * @author Jackson White
 */
 
#include "NormalPirate.h"

NormalPirate::NormalPirate() : Character(sf::Vector2f(0, 0), 2, 20), mTexture()
{
    mTexture = new sf::Texture;
    bool x = mTexture->loadFromFile("images/normal_pirate.png", false, sf::IntRect({100, 150}, {102, 153}));
    if (mTexture->loadFromFile("images/normal_pirate.png"))
    {
        mSprite = new sf::Sprite(*mTexture);
    }

}
