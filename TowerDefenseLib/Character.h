/**
 * @file Character.h
 * @author Jackson White
 *
 * Character base class. Each hero will be derived from a Character
 */
 
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <optional>

/**
 * Each hero that destroys enemies will be of base type character, which holds a position
 */
class Character {
private:

    /// the image of the normal pirate
    sf::Sprite* mSprite = nullptr;

    /// the texture of the normal pirate
    sf::Texture* mTexture = nullptr;

    /// the frame of the gif we are on
    int mPictureFrame = 1;

    /// the amount of times Draw was called
    int mTimesCalled = 0;

    /// All of the possible actions the character can do
    enum class Action {Idle, Punching, Kicking, Knocked, Walking, Jumping};

    /// the current action the character is doing
    Action mAction;

    void Animate();

    /// the direction our character is facing. 1 = right, -1 = left
    int mFacingDirection;



public:

    Character();

    void Draw(sf::RenderWindow* window);

    void MoveRight();
    void MoveLeft();
    void Jump();

    void SetIdle();
    void AdjustJump();
    void Punch();
};



#endif //CHARACTER_H
