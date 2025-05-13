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
class Map : public Item {
private:
public:
    Map() = delete;

    Map(std::string imageName);

};



#endif //MAP_H
