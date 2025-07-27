/**
 * @file MainMenu.cpp
 * @author Jackson White
 */
 
#include "MainMenu.h"
using namespace std;

MainMenu::MainMenu()
{
    CreateText();
    CreateButtons();
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
        for (auto sprite : mSprites)
        {
            window->draw(*sprite);
        }
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
}

void MainMenu::CreateButtons()
{
    shared_ptr<sf::Texture> playTexture = std::make_shared<sf::Texture>();
    if (playTexture->loadFromFile("images/play_button.png"))
    {
        shared_ptr<sf::Sprite> playButtonSprite = make_shared<sf::Sprite>(*playTexture);

        sf::FloatRect bounds = playButtonSprite->getLocalBounds();
        sf::Vector2f origin = sf::Vector2f(bounds.size.x / 2, bounds.size.y / 2);
        playButtonSprite->setOrigin(origin);
        playButtonSprite->setPosition(sf::Vector2f(1536 /2, 896 / 2.5));
        mSprites.push_back(playButtonSprite);
        mTextures.push_back(playTexture);
    }

    shared_ptr<sf::Texture> upArrowTexture = std::make_shared<sf::Texture>();
    if (upArrowTexture->loadFromFile("images/up_button.png"))
    {
        shared_ptr<sf::Sprite> upArrowPlayer1Sprite = make_shared<sf::Sprite>(*upArrowTexture);
        shared_ptr<sf::Sprite> upArrowPlayer2Sprite = make_shared<sf::Sprite>(*upArrowTexture);

        sf::FloatRect bounds = upArrowPlayer1Sprite->getLocalBounds();
        sf::Vector2f origin = sf::Vector2f(bounds.size.x / 2, bounds.size.y / 2);
        upArrowPlayer1Sprite->setOrigin(origin);
        upArrowPlayer1Sprite->setPosition(sf::Vector2f(150, 600));
        upArrowPlayer1Sprite->setScale(sf::Vector2f(0.25, 0.25));

        upArrowPlayer2Sprite->setOrigin(origin);
        upArrowPlayer2Sprite->setPosition(sf::Vector2f(1365, 600));
        upArrowPlayer2Sprite->setScale(sf::Vector2f(0.25, 0.25));

        mSprites.push_back(upArrowPlayer1Sprite);
        mSprites.push_back(upArrowPlayer2Sprite);
        mTextures.push_back(upArrowTexture);
    }
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

    auto playButtonSprite = mSprites[0];
    sf::FloatRect bounds = playButtonSprite->getLocalBounds();
    sf::Vector2f playPosition = playButtonSprite->getPosition();

    auto mouseX = mousePosition.x;
    auto mouseY = mousePosition.y;

    if ((playPosition.x - bounds.size.x / 2) <= mouseX &&
        (playPosition.x + bounds.size.x / 2) >= mouseX &&
        (playPosition.y - bounds.size.y / 2) <= mouseY &&
        (playPosition.y + bounds.size.y / 2) >= mouseY)
        {
            return true;
        }
    return false;

}