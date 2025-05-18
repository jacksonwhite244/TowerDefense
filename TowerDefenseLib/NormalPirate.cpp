/**
 * @file NormalPirate.cpp
 * @author Jackson White
 */
 
#include "NormalPirate.h"

NormalPirate::NormalPirate() : Character(), mTexture()
{
    mTexture = new sf::Texture;
    if (mTexture->loadFromFile("images/sniper_monkey.png"))
    {
        mSprite = new sf::Sprite(*mTexture);
        sf::Vector2 position(101, 0);
        sf::Vector2 size(101, 124);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);

    }

}
