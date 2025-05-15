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
    /// the position of the character
    sf::Vector2f mPosition;

    int mFireRate;

    double mRange;

    /// the image of the normal pirate
    sf::Sprite* mSprite = nullptr;

    /// the texture of the normal pirate
    sf::Texture* mTexture = nullptr;

    int mPictureFrame = 1;

    int mTimesCalled = 0;
public:
    /**
     * Default constructor deleted
     */
    Character() = delete;

    /**
     * Custom constructor for characters
     *
     * @param pos the position of the character
     * @param attackRate the attack rate of the character
     * @param range the range of the character
     */
    Character(sf::Vector2f pos, int attackRate, double range);

    /**
     * Set the position of the character
     * @param position the position we are setting the character to
     */
    void SetPosition(sf::Vector2f position) { mPosition = position; };

    /**
     * Get the position of the character
     * @return The position of the character
     */
    sf::Vector2f GetPosition() { return mPosition; };

    /**
     * Set the range the character can attack
     * @param range the range we are setting the character to
     */
    void SetRange(double range) { mRange = range; };

    /**
     * Set the attack rate of the character
     * @param rate the rate at which the character will attack
     */
    void SetFireRate(int rate) { mFireRate = rate; };

    /**
     * Get the range the character can attack
     * @return the range of the character
     */
    double GetRange() { return mRange; };

    /**
     * Get the attack rate of the character
     * @return the attack rate of the character
     */
    int GetFireRate() { return mFireRate; };

    void Draw(sf::RenderWindow* window);
    void Idle();
};



#endif //CHARACTER_H
