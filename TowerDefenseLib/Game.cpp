/**
 * @file Game.cpp
 * @author Jackson White
 */
 
#include "Game.h"
#include "Character.h"

using namespace std;
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
    if (mMainMenu.IsActive())
    {
        mMainMenu.Render(mWindow);
    }

    mCharacter1->Draw(mWindow);

    mCharacter2->Draw(mWindow);

    mWindow->display();
}

/**
 * Initialize all the variables of the game
 */
void Game::InitializeVariables()
{
    mWindow = nullptr;
    mMap = std::make_shared<Map>();
    mCharacter1 = std::make_shared<Cat>(1, this);
    mCharacter2 = std::make_shared<Monster>(2, this);
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
    CheckSwitches();
    /// player has started the game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Enter) && mMainMenu.IsActive())
    {
        mMainMenu.SetInactive();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) && mMainMenu.IsActive())
    {
        if (mChar1SwitchTime == 0)
        {
            mChar1Switching = true;
            mMainMenu.AddFirstPlayerCharacter();

            int char1 = mMainMenu.GetFirstPlayerCharacter();
            if (char1 % 2 == 0)
            {
                mCharacter1 = std::make_shared<Cat>(1, this);
            }
            else
            {
                mCharacter1 = std::make_shared<Monster>(1, this);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S) && mMainMenu.IsActive())
    {
        if (mChar1SwitchTime == 0)
        {
            mChar1Switching = true;
            mMainMenu.SubtractFirstPlayerCharacter();

            int char1 = mMainMenu.GetFirstPlayerCharacter();
            if (char1 % 2 == 0)
            {
                mCharacter1 = std::make_shared<Cat>(1, this);
            }
            else
            {
                mCharacter1 = std::make_shared<Monster>(1, this);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up) && mMainMenu.IsActive())
    {
        if (mChar2SwitchTime == 0)
        {
            mChar2Switching = true;
            mMainMenu.AddSecondPlayerCharacter();
            int char1 = mMainMenu.GetSecondPlayerCharacter();
            if (char1 % 2 == 0)
            {
                mCharacter2 = std::make_shared<Cat>(2, this);
            }
            else
            {
                mCharacter2 = std::make_shared<Monster>(2, this);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down) && mMainMenu.IsActive())
    {
        if (mChar2SwitchTime == 0)
        {
            mChar2Switching = true;
            mMainMenu.SubtractSecondPlayerCharacter();
            int char1 = mMainMenu.GetSecondPlayerCharacter();
            if (char1 % 2 == 0)
            {
                mCharacter2 = std::make_shared<Cat>(2, this);
            }
            else
            {
                mCharacter2 = std::make_shared<Monster>(2, this);
            }
        }
    }


    /// moving right and jumping at the same time (Character Left)
    /// <----------------------------------------------------------------------------------------------->
    /// if the menu is active, none of the characters will move
    if (mMainMenu.IsActive())
    {
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        mCharacter2->Jump();
        mCharacter2->MoveRight();
    }

    /// move left and jump
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        mCharacter2->Jump();
        mCharacter2->MoveLeft();
    }

    /// move right and punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Numpad0))
    {
        mCharacter2->Punch();
        mCharacter2->MoveRight();
    }

    /// move left and punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Numpad0))
    {
        mCharacter2->Punch();
        mCharacter2->MoveLeft();
    }

    /// move right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        mCharacter2->MoveRight();
    }

    /// move left
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        mCharacter2->MoveLeft();
    }

    /// jump
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        mCharacter2->Jump();
    }

    /// punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Numpad0))
    {
        mCharacter2->Punch();
    }

    /// nothing
    else
    {
        mCharacter2->SetIdleFromMenu();
    }


    /// moving right and jumping at the same time (Character Right)
    /// <----------------------------------------------------------------------------------------------->

    /// moving right and jumping at the same time
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
    {
        mCharacter1->Jump();
        mCharacter1->MoveRight();
    }

    /// move left and jump
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
    {
        mCharacter1->Jump();
        mCharacter1->MoveLeft();
    }

    /// move right and punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        mCharacter1->Punch();
        mCharacter1->MoveRight();
    }

    /// move left and punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        mCharacter1->Punch();
        mCharacter1->MoveLeft();
    }

    /// move right
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
    {
        mCharacter1->MoveRight();
    }

    /// move left
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
    {
        mCharacter1->MoveLeft();
    }

    /// jump
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
    {
        mCharacter1->Jump();
    }

    /// punch
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        mCharacter1->Punch();
    }

    /// nothing
    else
    {
        mCharacter1->SetIdleFromMenu();
    }
}

void Game::CheckSwitches()
{
    if (mChar1Switching)
    {
        mChar1SwitchTime ++;
        if (mChar1SwitchTime > 160)
        {
            mChar1Switching = false;
            mChar1SwitchTime = 0;
        }
    }
    if (mChar2Switching)
    {
        mChar2SwitchTime ++;
        if (mChar2SwitchTime > 160)
        {
            mChar2Switching = false;
            mChar2SwitchTime = 0;
        }
    }
}

shared_ptr<Character> Game::GetOpponent(Character* character)
{
    if (character ==  mCharacter1.get())
    {
        return mCharacter2;
    }
    return mCharacter1;
}
