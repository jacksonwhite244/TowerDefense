/**
 * @file MainMenu.h
 * @author Jackson White
 *
 * Main Menu to select the player/character you want to use
 */
 
#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/**
 * Main Menu to select the character you want to use. Should be able ot press a start button to start the game
 */
class MainMenu {
private:
    /// is the menu active or not?
    bool mIsShowing = true;
public:
    MainMenu();
    void Render(sf::RenderWindow* window);

    /**
     * Is the menu currently being shown?
     * @return true/false depending on if the menu is currently being shown
     */
    bool IsActive() { return mIsShowing; }

    /**
     * Set the menu to inactive (game playing)
     */
    void SetInactive() { mIsShowing = false; }

    /**
     * set the menu to active (game not playing)
     */
    void SetActive() { mIsShowing = true; }
};



#endif //MAINMENU_H
