/**
 * @file Map.h
 * @author Jackson White
 *
 * The map the player chose
 */
 
#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <optional>

#include "Item.h"


/**
 * The map the player chose
 */
class Map {
private:
    /// the image of the sky
    sf::Sprite* mSpriteSky = nullptr;

    /// the texture sky
    sf::Texture* mTextureSky = nullptr;

    /// the image ground
    sf::Sprite* mSpriteGround = nullptr;

    /// the texture ground
    sf::Texture* mTextureGround = nullptr;

    /// the image trees (left side)
    sf::Sprite* mSpriteTree = nullptr;

    /// the texture of trees (left side)
    sf::Texture* mTextureTree = nullptr;

    /// the image of the small trees (right)
    sf::Sprite* mSpriteTreeSmall = nullptr;

    /// the texture of the msmall trees (right)
    sf::Texture* mTextureTreeSmall = nullptr;


public:
    Map();

    void Draw(sf::RenderWindow* window);

};



#endif //MAP_H
