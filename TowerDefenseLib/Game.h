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
#include <optional>
#include <memory>

#include "Map.h"
#include "Cat.h"

/**
 * Game class that runs / controls the game
 */
class Game {
private:
    /// the window that portrays the game
    sf::RenderWindow* mWindow;

    /// the size of the screen
    sf::VideoMode mVideoMode;

    void InitializeWindow();

    void InitializeVariables();

    std::shared_ptr<Cat> mCharacter1;

    /// The map the game is on
    std::shared_ptr<Map> mMap;

public:
    /// constructor
    Game();

    /// virtual destructor
    virtual ~Game();

    void Update();

    void Render();

    bool GameRunning() const;

    void CheckEvents();
};



#endif //GAME_H
