/**
 * @file Character.cpp
 * @author jacks
 */
 
#include "Character.h"

Character::Character(sf::Vector2f pos, int attackRate, double range) : mPosition(pos), mFireRate(attackRate), mRange(range)
{
    mTexture = new sf::Texture;
    if (mTexture->loadFromFile("images/cat_character.png"))
    {
        mSprite = new sf::Sprite(*mTexture);
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);
        mSprite->setScale(sf::Vector2f(5, 5));

    }
}

void Character::Draw(sf::RenderWindow* window)
{
    Idle();
    sf::Vector2f position(0, 500);
    mSprite->setPosition(position);
    window->draw(*mSprite);
}

void Character::Idle()
{
    mTimesCalled++;
    if (mTimesCalled == 60)
    {
        mPictureFrame = (mPictureFrame + 1) % 4;
        sf::Vector2 position(mPictureFrame * 64, 0);
        sf::Vector2 size(64, 64);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);
        mTimesCalled = 0;

    }
}
