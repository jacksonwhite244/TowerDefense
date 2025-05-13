/**
 * @file Game.cpp
 * @author Jackson White
 */
 
#include "Game.h"

/**
 * Base constructor for the game, Initializes variables and creates the window
 */
Game::Game()
{
    InitializeVariables();
    InitializeWindow();
}

/**
 * Game destructor needs to delete all of the dynamically allocated memory
 */
Game::~Game()
{
    delete mWindow;
}

/**
 * Update the game
 */
void Game::Update()
{
    CheckEvents();
}

/**
 * visualize the game
 */
void Game::Render()
{
    mWindow->clear(sf::Color::Transparent);

    /// draw game
    mWindow->draw(mMap->GetSprite());
    mWindow->draw(mNormalPirate.GetSprite());
    mNormalPirate.Draw(mWindow);

    mWindow->display();
}

/**
 * Initialize all the variables of the game
 */
void Game::InitializeVariables()
{
    mWindow = nullptr;
    mMap = std::make_shared<Map>("images/map1.png");
}

/**
 * Initialize the window with a certain size
 */
void Game::InitializeWindow()
{
    mVideoMode.size = {1250, 800};
    mWindow = new sf::RenderWindow(mVideoMode, "Tower Defense!", sf::Style::Titlebar | sf::Style::Close);

}

bool Game::GameRunning() const
{
    return mWindow->isOpen();
}

void Game::CheckEvents()
{
    while (std::optional<sf::Event> event = mWindow->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            mWindow->close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                mWindow->close();
        }
    }
}


