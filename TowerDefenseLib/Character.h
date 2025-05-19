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

    /// pure virtual animation function
    virtual void Animate() = 0;

    /// the direction our character is facing. 1 = right, -1 = left
    int mFacingDirection;



public:

    Character(std::string fileName);

    void Draw(sf::RenderWindow* window);

    void MoveRight();
    void MoveLeft();
    void Jump();
    void SetIdleFromMenu();
    void AdjustJump();
    void Punch();
    virtual bool ReadyToAnimate();

    /**
     * This sets the rectangle in the sprite sheet of the exact frame of the character we want
     * @param rect the rectangle space we are selecting to be shown
     */
    void SetRectangleTexture(sf::IntRect rect) { mSprite->setTextureRect(rect); }

    bool IsIdle() { return mAction == Action::Idle; }
    bool IsPunching() { return mAction == Action::Punching; }
    bool IsKicking() { return mAction == Action::Kicking; }
    bool IsKnocked() { return mAction == Action::Knocked; }
    bool IsWalking() { return mAction == Action::Walking; }
    bool IsJumping() { return mAction == Action::Jumping; }
    int GetPictureFrame() { return mPictureFrame; }
    int GetTimesCalled() { return mTimesCalled; }
    void SetPictureFrame(int frame) { mPictureFrame = frame; }
    void SetTimesCalled(int timesCalled) { mTimesCalled = timesCalled; }

    void SetIdle() { mAction = Action::Idle; };


};



#endif //CHARACTER_H
