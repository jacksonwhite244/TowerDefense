/**
 * @file MainMenu.cpp
 * @author Jackson White
 */
 
#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu()
{
    CreateText();
}

/**
 * Show the main menu
 */
void MainMenu::Render(sf::RenderWindow* window)
{
    if (mShowingWinner)
    {
        mWinnerShowingTimer ++;
        for (auto text : mWinningText)
        {
            window->draw(*text);
        }
        if (mWinnerShowingTimer > 5000)
        {
            mShowingWinner = false;
            mWinnerShowingTimer = 0;
        }
    }
    else
    {
        for (auto text : mTexts)
        {
            window->draw(*text);
        }
        window->draw(*mPlayButtonSprite);
    }

}

void MainMenu::CreateText()
{
    shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->openFromFile("images/Lato-Bold.ttf"))
    {
        /// error has occured
        return;
    }
    /// add font to the vector of fonts
    mFonts.push_back(font);

    shared_ptr<sf::Text> text = make_shared<sf::Text>(*font);

    text->setString("Choose Your Fighter!");
    text->setCharacterSize(60);
    text->setFillColor(sf::Color::Black);

    /// set the origin + position
    text->setOrigin(sf::Vector2f(text->getLocalBounds().size.x /2,
        text->getLocalBounds().size.y / 2));

    text->setPosition(sf::Vector2f(1536/2, 896/ 4));
    mTexts.push_back(text);

    /// press enter to play
    /**
    shared_ptr<sf::Text> text2 = make_shared<sf::Text>(*font);
    text2->setString("Press Enter to Start");
    text2->setCharacterSize(40);
    text2->setFillColor(sf::Color::Black);
    text2->setOrigin(sf::Vector2f(text2->getLocalBounds().size.x /2,
        text2->getLocalBounds().size.y / 2));

    text2->setPosition(sf::Vector2f(1536 /2, 896 / 3));
    mTexts.push_back(text2);

*/
    mPlayButtonTexture = new sf::Texture();
    if (mPlayButtonTexture->loadFromFile("images/play_button.png")) {
        mPlayButtonSprite = new sf::Sprite(*mPlayButtonTexture);

        sf::FloatRect bounds = mPlayButtonSprite->getLocalBounds();
        sf::Vector2f origin = sf::Vector2f(bounds.size.x / 2, bounds.size.y / 2);
        mPlayButtonSprite->setOrigin(origin);
        mPlayButtonSprite->setPosition(sf::Vector2f(1536 /2, 896 / 2.5));
    }

    /// press w/s to switch character 1
    shared_ptr<sf::Text> text3 = make_shared<sf::Text>(*font);
    text3->setString("Use w/s to switch character 1");
    text3->setCharacterSize(20);
    text3->setFillColor(sf::Color::Black);
    text3->setOrigin(sf::Vector2f(text3->getLocalBounds().size.x /2,
        text3->getLocalBounds().size.y / 2));

    //text3.setPosition(sf::Vector2f(window->getSize().x /4, window->getSize().y / 3));
    text3->setPosition(sf::Vector2f(150, 600));
    mTexts.push_back(text3);

    /// press up/down to switch character 2
    shared_ptr<sf::Text> text4 = make_shared<sf::Text>(*font);
    text4->setString("Use w/s to switch character 1");
    text4->setCharacterSize(20);
    text4->setFillColor(sf::Color::Black);
    text4->setOrigin(sf::Vector2f(text3->getLocalBounds().size.x /2,
        text4->getLocalBounds().size.y / 2));

    //text3.setPosition(sf::Vector2f(window->getSize().x /4, window->getSize().y / 3));
    text4->setPosition(sf::Vector2f(1350, 600));
    mTexts.push_back(text4);
}

/**
 * A Character has won the game!
 *
 * Show a message depicting that the game is over and who the winner is
 */
void MainMenu::Winner(int playerNum)
{
    /// set the menu to showing and showing winner
    if (mIsShowing and mShowingWinner)
    {
        return;
    }
    mIsShowing = true;
    mShowingWinner = true;


    mWinningText.clear();

    shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->openFromFile("images/Lato-Bold.ttf"))
    {
        /// error has occured
        return;
    }
    /// add font to the vector of fonts
    mFonts.push_back(font);

    shared_ptr<sf::Text> text = make_shared<sf::Text>(*font);

    text->setString("Game Over!");
    text->setCharacterSize(60);
    text->setFillColor(sf::Color::Red);

    /// set the origin + position
    text->setOrigin(sf::Vector2f(text->getLocalBounds().size.x /2,
        text->getLocalBounds().size.y / 2));

    text->setPosition(sf::Vector2f(1536/2, 896/ 4));
    mWinningText.push_back(text);

    /// Select the winner
    shared_ptr<sf::Text> text2 = make_shared<sf::Text>(*font);
    if (playerNum == 1)
    {
        text2->setString("Player 1 Wins!");
    }
    else
    {
        text2->setString("Player 2 Wins!");

    }
    text2->setCharacterSize(40);
    text2->setFillColor(sf::Color::Black);
    text2->setOrigin(sf::Vector2f(text2->getLocalBounds().size.x /2,
        text2->getLocalBounds().size.y / 2));

    text2->setPosition(sf::Vector2f(1536 /2, 896 / 3));
    mWinningText.push_back(text2);
}

/**
 *
 * @param mousePosition the posiiton of the mouse
 * @return true if the user clicked the play button, false if not
 */
bool MainMenu::HitPlay(sf::Vector2i mousePosition)
{
    if (not IsActive())
    {
        return false;
    }

    sf::FloatRect bounds = mPlayButtonSprite->getLocalBounds();
    sf::Vector2f playPosition = mPlayButtonSprite->getPosition();

    auto mouseX = mousePosition.x;
    auto mouseY = mousePosition.y;

    auto lowX = playPosition.x - bounds.size.x / 2;
    auto highX = playPosition.x + bounds.size.x / 2;
    auto lowY = playPosition.y - bounds.size.y / 2;
    auto highY = playPosition.y + bounds.size.y / 2;

    if ((playPosition.x - bounds.size.x / 2) <= mouseX &&
        (playPosition.x + bounds.size.x / 2) >= mouseX &&
        (playPosition.y - bounds.size.y / 2) <= mouseY &&
        (playPosition.y + bounds.size.y / 2) >= mouseY)
        {
            return true;
        }
    return false;

}