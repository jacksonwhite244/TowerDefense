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

    /// the first player character they selected
    int mFirstPlayerCharacter = 0;

    /// the second player character they selected
    int mSecondPlayerCharacter = 0;

    /// all of the text that appears for the menu
    std::vector<std::shared_ptr<sf::Text>> mTexts;

    /// all of the text that shows up for the winner
    std::vector<std::shared_ptr<sf::Text>> mWinningText;

    /// all of the different fonts used for text
    std::vector<std::shared_ptr<sf::Font>> mFonts;

    /// boolean turns true when the menu is showing a popup depicting the winner of the game (game over)
    bool mShowingWinner = false;

    /// timer to track how long the winner message has been showing
    int mWinnerShowingTimer = 0;

    /// the sprite of the play button
    sf::Sprite * mPlayButtonSprite = nullptr;

    /// the texture of the play button
    sf::Texture * mPlayButtonTexture = nullptr;
public:
    MainMenu();
    void Render(sf::RenderWindow* window);
    void CreateText();
    void Winner(int playerNum);

    bool HitPlay(sf::Vector2i mousePosition);

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

    void AddFirstPlayerCharacter() { mFirstPlayerCharacter++; }

    void AddSecondPlayerCharacter() { mSecondPlayerCharacter++; }

    void SubtractFirstPlayerCharacter() { mFirstPlayerCharacter--; }

    void SubtractSecondPlayerCharacter() { mSecondPlayerCharacter--; }

    int GetFirstPlayerCharacter() const { return mFirstPlayerCharacter; }

    int GetSecondPlayerCharacter() const { return mSecondPlayerCharacter; }
};



#endif //MAINMENU_H
