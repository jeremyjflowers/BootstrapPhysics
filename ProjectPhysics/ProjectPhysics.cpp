#include "PhysicGame.h"

int main()
{
    PhysicGame* game = new PhysicGame();
    game->run("PhyscisGame", 1280, 720, false);
    delete game;
    return 0;
}
