/**
 * @file Item.h
 * @author Jackson White
 *
 * An item is anything that shows up on the screen
 */
 
#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <optional>

/**
 * An item is anything that shows up on the screen (image/character/background)
 */
class Item {
private:

    sf::Vector2f mPosition;

    /// the image of the menu
    sf::Sprite* mSprite = nullptr;

    /// the texture of the menu
    sf::Texture* mTexture = nullptr;
public:

    Item() = delete;
    Item(std::string imageName, sf::Vector2f scale);

    sf::Sprite GetSprite() { return *mSprite; }

    //virtual ~Item();
};



#endif //ITEM_H
