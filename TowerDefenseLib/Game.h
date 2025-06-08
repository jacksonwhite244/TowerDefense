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
#include "Monster.h"
#include "MainMenu.h"

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

    std::shared_ptr<Character> mCharacter1;

    std::shared_ptr<Character> mCharacter2;

    /// The map the game is on
    std::shared_ptr<Map> mMap;

    /// the main menu
    MainMenu mMainMenu;

    /// character 1 switch time counter
    int mChar1SwitchTime = 0;

    /// is the character1 currently switching
    bool mChar1Switching = false;

    /// character2 switch time counter
    int mChar2SwitchTime = 0;

    /// is the character 2 currently switching
    bool mChar2Switching = false;

public:
    /// constructor
    Game();

    /// virtual destructor
    virtual ~Game();

    void Update();

    void Render();

    bool GameRunning() const;

    void CheckEvents();
    void CheckSwitches();
    std::shared_ptr<Character> GetOpponent(Character* character);
};



#endif //GAME_H
