/**
 * @file Cat.cpp
 * @author jacks
 */
 
#include "Cat.h"

Cat::Cat() : Character("images/cat_character.png")
{

}

/**
 * Animate the character.
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
                return;
            }
            position = sf::Vector2(pictureFrame * 64, 960);
            sf::IntRect rect1(position, size);
            SetRectangleTexture(rect1);
        }
        SetTimesCalled(0);
    }
}