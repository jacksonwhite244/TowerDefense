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

class Game;
/**
 * Each hero that destroys enemies will be of base type character, which holds a position
 */
class Character {
private:
    /// the game object the character belongs to
    Game * mGame = nullptr;
    /// the image of the normal pirate
    sf::Sprite* mSprite = nullptr;

    /// the texture of the normal pirate
    sf::Texture* mTexture = nullptr;

    /// the player number (either player 1 or 2)
    int mPlayerNum;

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

    /// the health the player has
    int mHealth;

    /// all of the text that appears for the health
    std::vector<std::shared_ptr<sf::Text>> mTexts;

    /// all of the different fonts used for text
    std::vector<std::shared_ptr<sf::Font>> mFonts;

    void CreateHealth();

public:
    Character(std::string fileName, int playerNum, Game* game);

    void Draw(sf::RenderWindow* window);

    void MoveRight();
    void MoveLeft();
    void Jump();
    void SetIdleFromMenu();
    virtual void AdjustJump() = 0;
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

    sf::Vector2f GetPosition() { return mSprite->getPosition(); }
    void SetPosition(sf::Vector2f position) { mSprite->setPosition(position); }

    /**
     * Get the game the character belongs to
     * @return a pointer to the game object
     */
    Game* GetGame() { return mGame; }

    /**
     * Get the area where the character can be injured
     * @return a box representing an area where the player can be injured
     */
    virtual sf::FloatRect GetHurtbox() = 0;

    sf::FloatRect GetHitBox() const;


    void DrawHitboxes(sf::RenderWindow* window);
    void DrawHurtBoxes(sf::RenderWindow* window);
    void TakeDamage();

    sf::Sprite * GetSprite() { return mSprite; }

    int GetFacingDirection() { return mFacingDirection; }

};



#endif //CHARACTER_H
