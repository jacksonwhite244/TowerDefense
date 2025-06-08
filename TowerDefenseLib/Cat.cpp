/**
 * @file Cat.cpp
 * @author jacks
 */
 
#include "Cat.h"
using namespace std;
class Game;

Cat::Cat(int playerNum, Game * game) : Character("images/cat_character.png", playerNum, game)
{

}

/**
 * Animate the cat character
 *
 * Every 120 times we draw, the characters gif animation will change to make it look like the character is alive
 */
void Cat::Animate()
{
    if (ReadyToAnimate())
    {
        sf::Vector2 position(0, 0);
        sf::Vector2 size(64, 64);

        int pictureFrame = GetPictureFrame();

        if (IsIdle())
        {
            SetPictureFrame((pictureFrame + 1) % 4);
            position = sf::Vector2(pictureFrame * 64, 0);
            sf::IntRect rect1(position, size);
            SetRectangleTexture(rect1);
        }
        else if (IsWalking())
        {
            SetPictureFrame((pictureFrame + 1) % 8);
            position = sf::Vector2(pictureFrame * 64, 64);
            sf::IntRect rect1(position, size);
            SetRectangleTexture(rect1);
        }

        else if (IsJumping())
        {
            SetPictureFrame((pictureFrame + 1) % 8);
            position = sf::Vector2(pictureFrame * 64, 128);
            sf::IntRect rect1(position, size);
            SetRectangleTexture(rect1);
        }

        else if (IsPunching())
        {
            SetPictureFrame(++pictureFrame);
            if (pictureFrame == 6)
            {
                SetPictureFrame(0);
                SetTimesCalled(0);
                SetIdle();

                Game * game = GetGame();
                shared_ptr<Character> otherOpponent = game->GetOpponent(this);
                if (GetHitBox().findIntersection(otherOpponent->GetHurtbox()))
                {
                    otherOpponent->TakeDamage();
                }

                return;
            }
            position = sf::Vector2(pictureFrame * 64, 960);
            sf::IntRect rect1(position, size);
            SetRectangleTexture(rect1);
        }
        SetTimesCalled(0);
    }
}

/**
 * Adjust the Jump based on the cats sprite sheet
 */
void Cat::AdjustJump()
{
    if (IsJumping())
    {
        int pictureFrame = GetPictureFrame();
        if (pictureFrame < 8)
        {
            auto position = GetPosition();
            if (pictureFrame == 3)
            {
                SetPosition(position - sf::Vector2f(0, 1));
            }
            if (pictureFrame == 4)
            {
                SetPosition(position + sf::Vector2f(0, 1));
            }

            if (pictureFrame == 7)
            {
                SetIdle();
                SetPictureFrame(0);
                SetTimesCalled(0);
            }
        }

    }
}

/**
 * Overriden function to retrieve the hitbox of the player. It depends on which way the character is facing
 * @return the hitbox
 */
sf::FloatRect Cat::GetHurtbox()
{
    sf::Vector2f pos = GetPosition();
    float width = 64;  // width of the punch range
    float height = 140;


    if (GetFacingDirection() == 1)
    {
        return sf::FloatRect(sf::Vector2(pos.x - GetSprite()->getLocalBounds().size.x / 2 - 5, pos.y + 128), sf::Vector2(width, height));

    }
    return sf::FloatRect(sf::Vector2(pos.x - GetSprite()->getLocalBounds().size.x / 2 + 10, pos.y + 128), sf::Vector2(width, height));

}