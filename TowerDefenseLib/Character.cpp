/**
 * @file Character.cpp
 * @author jacks
 */
 
#include "Character.h"

/**
 * Custom Constructor for the character
 * @param pos the position of the character
 * @param attackRate
 * @param range
 */
Character::Character()
{
    mTexture = new sf::Texture;
    mAction = Action::Idle;
    mFacingDirection = 1;
    if (mTexture->loadFromFile("images/cat_character.png"))
    {
        mSprite = new sf::Sprite(*mTexture);
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);
        mSprite->setScale(sf::Vector2f(5 * mFacingDirection, 5));
        mSprite->setPosition(sf::Vector2f(0, 515));
    }
}

void Character::Draw(sf::RenderWindow* window)
{
    Animate();
    window->draw(*mSprite);
}

/**
 * Animate the character.
 *
 * Every 120 times we draw, the characters gif animation will change to make it look like the character is alive
 */
void Character::Animate()
{
    mTimesCalled++;
    AdjustJump();
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
        }

        else if (mAction == Action::Punching)
        {
            mPictureFrame++;
            if (mPictureFrame == 6)
            {
                mPictureFrame = 0;
                mTimesCalled = 0;
                mAction = Action::Idle;
                return;
            }
            position = sf::Vector2(mPictureFrame * 64, 960);
            sf::IntRect rect1(position, size);
            mSprite->setTextureRect(rect1);
        }
        mTimesCalled = 0;
    }
}

/**
 * Move the character Right
 *
 * Set the character to walking and move the character over a couple of pixels
 * if the character is currently jumping, move the character but don't switch the action
 */
void Character::MoveRight()
{
    if (mAction != Action::Walking && mAction != Action::Jumping && mAction != Action::Punching)
    {
        mPictureFrame = 0;
        mTimesCalled = 0;
        mAction = Action::Walking;
    }
    mFacingDirection = 1;
    sf::Vector2 position = mSprite->getPosition();
    if (position.x > 1280)
    {
        return;
    }
    mSprite->setScale(sf::Vector2f(5 * mFacingDirection, 5));

    sf::Vector2f origin = sf::Vector2f(0, 0);
    mSprite->setOrigin(origin);
    mSprite->setPosition(position + sf::Vector2f(0.3, 0));
}

/**
 * Move the character Left
 *
 * Set the character to walking and move the character over a couple of pixels
 * if the character is currently jumping, move the character but don't switch the action
 */
void Character::MoveLeft()
{
    if (mAction != Action::Walking && mAction != Action::Jumping && mAction != Action::Punching)
    {
        mPictureFrame = 0;
        mTimesCalled = 0;
        mAction = Action::Walking;
    }
    mFacingDirection = -1;
    sf::Vector2 position = mSprite->getPosition();
    if (position.x <= -128)
    {
        return;
    }

    mSprite->setScale(sf::Vector2f(5 * mFacingDirection, 5));

    sf::FloatRect bounds = mSprite->getLocalBounds();
    sf::Vector2f origin = sf::Vector2f(bounds.size.x, 0);
    mSprite->setOrigin(origin);
    mSprite->setPosition(position - sf::Vector2f(0.3, 0));
}

/**
 * Set the characters action to Jumping.
 * If the character is already jumping, don't do anything
 */
void Character::Jump()
{
    if (mAction == Action::Jumping || mAction == Action::Punching)
    {
        return;
    }
    mPictureFrame = 0;
    mTimesCalled = 0;
    mAction = Action::Jumping;
}

/**
 * Set the characters action to Idle
 */
void Character::SetIdle()
{
    if (mAction == Action::Idle || mAction == Action::Jumping || mAction == Action::Punching)
    {
        return;
    }
    mPictureFrame = 0;
    mTimesCalled = 0;
    mAction = Action::Idle;
}

/**
 * This gets called each time we draw the character.
 * If the character is Jumping, we need to move the character up, based on the frame of the character
 */
void Character::AdjustJump()
{
    if (mAction == Action::Jumping)
    {
        if (mPictureFrame < 8)
        {
            if (mPictureFrame == 3)
            {
                auto position = mSprite->getPosition();
                mSprite->setPosition(position - sf::Vector2f(0, 1));
            }
            if (mPictureFrame == 4)
            {
                auto position = mSprite->getPosition();
                mSprite->setPosition(position + sf::Vector2f(0, 1));
            }
            if (mPictureFrame == 7)
            {
                mAction = Action::Idle;
                mPictureFrame = 0;
                mTimesCalled = 0;
            }
        }
    }
}

void Character::Punch()
{
    if (mAction == Action::Punching || mAction == Action::Jumping)
    {
        return;
    }
    mPictureFrame = 0;
    mTimesCalled = 0;
    mAction = Action::Punching;
}