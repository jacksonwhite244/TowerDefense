/**
 * @file Character.cpp
 * @author jacks
 */
 
#include "Character.h"

/**
 * Custom constructor for character
 * @param fileName the image pathname
 * @param playerNum playernumber (1 or 2)
 */
Character::Character(std::string fileName, int playerNum)
{
    int playerFirstLocation;
    mTexture = new sf::Texture;
    mAction = Action::Idle;
    if (playerNum == 1)
    {
        mFacingDirection = 1;
        playerFirstLocation = 0;
    }
    else
    {
        mFacingDirection = -1;
        playerFirstLocation = 1200;
    }

    if (mTexture->loadFromFile(fileName))
    {
        mSprite = new sf::Sprite(*mTexture);
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);
        sf::IntRect rect1(position, size);
        mSprite->setTextureRect(rect1);
        if (playerNum != 1)
        {
            sf::FloatRect bounds = mSprite->getLocalBounds();
            sf::Vector2f origin = sf::Vector2f(bounds.size.x, 0);
            mSprite->setOrigin(origin);
        }
        mSprite->setScale(sf::Vector2f(5 * mFacingDirection, 5));
        mSprite->setPosition(sf::Vector2f(playerFirstLocation, 515));
    }
}

/**
 * Draw to the window
 * @param window the window we are drawing on
 */
void Character::Draw(sf::RenderWindow* window)
{
    Animate();
    window->draw(*mSprite);
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
    auto check = position.x;
    if (position.x > 1200)
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
void Character::SetIdleFromMenu()
{
    if (mAction == Action::Idle || mAction == Action::Jumping || mAction == Action::Punching)
    {
        return;
    }
    mPictureFrame = 0;
    mTimesCalled = 0;
    mAction = Action::Idle;
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

/**
 * Check if the character is ready to animate
 * @return yes if the character is ready, no if not
 */
bool Character::ReadyToAnimate()
{
    mTimesCalled++;
    AdjustJump();
    if (mTimesCalled == 120)
    {
        return true;
    }
    return false;
}
