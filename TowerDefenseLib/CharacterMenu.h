/**
 * @file CharacterMenu.h
 * @author Jackson White
 *
 * The character menu is where you will buy the monkey
 */
 
#ifndef CHARACTERMENU_H
#define CHARACTERMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <optional>

/**
 * Character menu where you purchase then building you want
 */
class CharacterMenu {
private:
    /// the image of the normal pirate
    sf::Sprite* mSprite = nullptr;

    /// the texture of the normal pirate
    sf::Texture* mTexture = nullptr;
public:

};



#endif //CHARACTERMENU_H
