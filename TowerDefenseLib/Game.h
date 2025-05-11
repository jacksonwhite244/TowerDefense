/**
 * @file Game.h
 * @author Jackson White
 *
 * Game class that runs the game
 */
 
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/**
 * Game class that runs / controls the game
 */
class Game {
private:
    void MakeWindow();

public:
    /// constructor
    Game();

    /// virtual destructor
    virtual ~Game();

    void Update();

    void Render();

};



#endif //GAME_H
