#include "Game.h"

Game::Game()
{

}
Game::~Game()
{
	if (this->GetNextTask() && !ge->GetDeleteEngine())
	{

	}
}
Game* Game::Create()
{
	return new Game();
}