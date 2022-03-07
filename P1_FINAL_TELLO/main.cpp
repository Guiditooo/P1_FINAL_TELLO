#include "Game.h"

int main()
{
	Game* game = new Game();

	game->Run();

	if (game != nullptr)
	{
		delete game;
		game = nullptr;
	}
	return 0;
}