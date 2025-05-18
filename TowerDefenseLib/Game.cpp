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
    mMap->Draw(mWindow);

    mCharacter1->Draw(mWindow);

    mWindow->display();
}

/**
 * Initialize all the variables of the game
 */
void Game::InitializeVariables()
{
    mWindow = nullptr;
    mMap = std::make_shared<Map>();
    mCharacter1 = std::make_shared<Character>();
}

/**
 * Initialize the window with a certain size
 */
void Game::InitializeWindow()
{
    mVideoMode.size = {1536, 896};
    mWindow = new sf::RenderWindow(mVideoMode, "Fight!", sf::Style::Titlebar | sf::Style::Close);

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
    int eventsMet = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        mCharacter1->MoveRight();
        eventsMet++;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        mCharacter1->MoveLeft();
        eventsMet++;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        mCharacter1->Jump();
        eventsMet++;
    }

    if (eventsMet == 0)
    {
        mCharacter1->SetIdle();
    }

}


