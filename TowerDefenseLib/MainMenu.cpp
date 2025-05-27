/**
 * @file MainMenu.cpp
 * @author Jackson White
 */
 
#include "MainMenu.h"

MainMenu::MainMenu()
{

}

/**
 * Show the main menu
 */
void MainMenu::Render(sf::RenderWindow* window)
{
    sf::Font font;
    if (!font.openFromFile("images/Lato-Bold.ttf"))
    {
        /// error has occured
        return;
    }
    sf::Text text(font);
    text.setString("Choose Your Fighter!");
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Black);

    /// set the origin + position
    text.setOrigin(sf::Vector2f(text.getLocalBounds().size.x /2,
        text.getLocalBounds().size.y / 2));

    text.setPosition(sf::Vector2f(window->getSize().x /2, window->getSize().y / 4));
    window->draw(text);

    /// press enter to play t
    sf::Text text2(font);
    text2.setString("Press Enter to Start");
    text2.setCharacterSize(40);
    text2.setFillColor(sf::Color::Black);
    text2.setOrigin(sf::Vector2f(text2.getLocalBounds().size.x /2,
        text2.getLocalBounds().size.y / 2));

    text2.setPosition(sf::Vector2f(window->getSize().x /2, window->getSize().y / 3));
    window->draw(text2);

    /// press w/s to switch character 1
    sf::Text text3(font);
    text3.setString("Use w/s to switch character 1");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::Black);
    text3.setOrigin(sf::Vector2f(text3.getLocalBounds().size.x /2,
        text3.getLocalBounds().size.y / 2));

    //text3.setPosition(sf::Vector2f(window->getSize().x /4, window->getSize().y / 3));
    text3.setPosition(sf::Vector2f(150, 600));
    window->draw(text3);

}

