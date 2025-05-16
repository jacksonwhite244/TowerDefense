/**
 * @file Character.cpp
 * @author jacks
 */
 
#include "Character.h"

Character::Character(sf::Vector2f pos, int attackRate, double range) : mPosition(pos), mFireRate(attackRate), mRange(range)
{
    mTexture = new sf::Texture;
    mAction = Action::Idle;
    if (mTexture->loadFromFile("images/cat_character.png"))
    {
        mSprite = new sf::Sprite(*mTexture);
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);
        mSprite->setScale(sf::Vector2f(5, 5));
        mSprite->setPosition(sf::Vector2f(0, 500));
    }
}

void Character::Draw(sf::RenderWindow* window)
{
    Animate();
    window->draw(*mSprite);
}

void Character::Animate()
{
    mTimesCalled++;
    if (mTimesCalled == 120)
    {
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);

        if (mAction == Action::Idle)
        {
            mPictureFrame = (mPictureFrame + 1) % 4;
            position = sf::Vector2(mPictureFrame * 64, 0);
            sf::IntRect rect1(position, size);
            mSprite->setTextureRect(rect1);
        }
        else if (mAction == Action::Walking)
        {
            mPictureFrame = (mPictureFrame + 1) % 8;
            position = sf::Vector2(mPictureFrame * 64, 64);
            sf::IntRect rect1(position, size);
            mSprite->setTextureRect(rect1);
        }

        else if (mAction == Action::Jumping)
        {
            mPictureFrame = (mPictureFrame + 1) % 8;
            position = sf::Vector2(mPictureFrame * 64, 128);
            sf::IntRect rect1(position, size);
            mSprite->setTextureRect(rect1);
            AdjustJump();
        }
        mTimesCalled = 0;
    }
}

void Character::MoveRight()
{
    if (mAction != Action::Walking)
    {
        mTimesCalled = 0;
        mAction = Action::Walking;
    }
    sf::Vector2 position = mSprite->getPosition();
    if (position.x > 1280)
    {
        return;
    }

    mSprite->setPosition(position + sf::Vector2f(0.3, 0));
}

void Character::MoveLeft()
{
    if (mAction != Action::Walking)
    {
        mTimesCalled = 0;
        mAction = Action::Walking;
    }
    sf::Vector2 position = mSprite->getPosition();
    if (position.x <= -128)
    {
        return;
    }
    mSprite->setPosition(position - sf::Vector2f(0.3, 0));
}

void Character::Jump()
{
    if (mAction == Action::Jumping)
    {
        return;
    }
    mTimesCalled = 0;
    mAction = Action::Jumping;
}

void Character::SetIdle()
{
    if (mAction == Action::Idle || mAction == Action::Jumping)
    {
        return;
    }
    mTimesCalled = 0;
    mAction = Action::Idle;
}

void Character::AdjustJump()
{
    if (mAction == Action::Jumping)
    {
        if (mPictureFrame < 8)
        {
            if (mPictureFrame == 3)
            {
                auto position = mSprite->getPosition();
                mSprite->setPosition(position - sf::Vector2f(0, 70));
            }
            if (mPictureFrame == 4)
            {
                auto position = mSprite->getPosition();
                mSprite->setPosition(position + sf::Vector2f(0, 70));
            }
            if (mPictureFrame == 7)
            {
                mAction = Action::Idle;
                mTimesCalled = 0;
            }
        }
    }

}