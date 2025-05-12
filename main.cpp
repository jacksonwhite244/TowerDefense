#include <iostream>
#include <Game.h>

int main()
{
    Game towerDefenseGame;;

    while (towerDefenseGame.GameRunning())
    {
        towerDefenseGame.Update();

        towerDefenseGame.Render();
    }
}
