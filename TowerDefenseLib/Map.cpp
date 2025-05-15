/**
 * @file Map.cpp
 * @author jacks
 */
 
#include "Map.h"

Map::Map()
{
    sf::Vector2f scale = sf::Vector2f(4,4);
    mTextureSky = new sf::Texture();
    mTextureGround = new sf::Texture();
    mTextureTree = new sf::Texture();
    mTextureTreeSmall = new sf::Texture();

    if (mTextureSky->loadFromFile("images/country-platform-back.png"))
    {
        mSpriteSky = new sf::Sprite(*mTextureSky);
        mSpriteSky->scale(scale);
    }

    if (mTextureGround->loadFromFile("images/country-platform-tiles-example.png"))
    {
        mSpriteGround = new sf::Sprite(*mTextureGround);
        mSpriteGround->scale(scale);
    }

    if (mTextureTree->loadFromFile("images/country-platform-forest.png"))
    {
        mSpriteTree = new sf::Sprite(*mTextureTree);
        mSpriteTree->scale(scale);
    }

    if (mTextureTreeSmall->loadFromFile("images/country-platform-forest.png"))
    {
        mSpriteTreeSmall = new sf::Sprite(*mTextureTreeSmall);
        mSpriteTreeSmall->scale(scale);
        sf::Vector2 position(0, 0);
        sf::Vector2 size(256, 224);
        sf::IntRect rect1(position, size);
        mSpriteTreeSmall->setTextureRect(rect1);
    }
}

/**
 * Draw the map
 * @param window the window we are drawing the map to
 */
void Map::Draw(sf::RenderWindow* window)
{
    window->draw(*mSpriteSky);

    /// Draw all of the trees multiple times
    sf::Vector2f position(0, 0);
    sf::Vector2f size(160, 224);
    mSpriteTree->setPosition(position);
    window->draw(*mSpriteTree);

    position = sf::Vector2f(640, 0);
    mSpriteTree->setPosition(position);
    window->draw(*mSpriteTree);

    position = sf::Vector2f(1280, 0);
    mSpriteTreeSmall->setPosition(position);
    window->draw(*mSpriteTreeSmall);

    window->draw(*mSpriteGround);
}
