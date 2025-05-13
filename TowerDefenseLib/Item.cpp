/**
 * @file Item.cpp
 * @author jacks
 */
 
#include "Item.h"

Item::Item(std::string imageName, sf::Vector2f scale)
{
    mTexture = new sf::Texture();
    if (mTexture->loadFromFile(imageName))
    {
        mSprite = new sf::Sprite(*mTexture);
        mSprite->scale(scale);
    }
}
