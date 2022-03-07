#include "Hud.h"

Hud::Hud(Player* player)
{
	this->player = player;
	reDraw = true;
}

Hud::~Hud()
{
}

void Hud::Refresh()
{
	reDraw = true;
}

void Hud::Draw()
{
	if (!reDraw) return;
		
	for (short i = 0; i < HUD_WIDTH; i++)
	{
		for (short j = 0; j < HUD_HEIGHT; j++)
		{
			goToCoordinates(HUD_POS_X + i, HUD_POS_Y + j);
			cout << " ";
		}
	}

	drawFrame(HUD_POS_X, HUD_POS_Y, HUD_POS_X + HUD_WIDTH, HUD_POS_Y + HUD_HEIGHT);
	goToCoordinates(HUD_POS_X + 8, HUD_POS_Y + 2);

	cout << "Lives";
	goToCoordinates(HUD_POS_X + 7, HUD_POS_Y + 4);
	for (short i = 1; i < player->GetLives() + 1; i++)
	{
		cout << (char)HUD_HEART_ID << "  ";
	}

	goToCoordinates(HUD_POS_X + 6, HUD_POS_Y + 8);
	cout << "Asteroids";
	goToCoordinates(HUD_POS_X + 4, HUD_POS_Y + 10);
	for (short i = 0; i < Asteroid::GetAmount() / 2; i++)
	{
		cout << "*  ";
	}
	goToCoordinates(HUD_POS_X + 4, HUD_POS_Y + 12);
	for (short i = 0; i < Asteroid::GetAmount() / 2; i++)
	{
		cout << "*  ";
	}

	goToCoordinates(HUD_POS_X + 7, HUD_POS_Y + 16);
	cout << "Points";

	if (player->GetPoints() % 10 == 1)
	{
		goToCoordinates(HUD_POS_X + HUD_WIDTH / 2 - 2, HUD_POS_Y + 18);
	}
	else
	{
		goToCoordinates(HUD_POS_X + HUD_WIDTH / 2 - 3, HUD_POS_Y + 18);
	}
	cout << player->GetPoints() << " / " << TARGET_WIN_CONDITION;

	reDraw = false;

}

void Hud::WinMessage()
{
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 10);
	cout << "__  __";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 11);
	cout << "\\ \\/  /___   __ __";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 12);
	cout << " \\  / / _ \\ / // /";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 13);
	cout << " /_/  \\___/ \\_,_/";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 15);
	cout << " _      __ ";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 16);
	cout << "| | /| / / (_) ___";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 17);
	cout << "| |/ |/ / / / / _ \\";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 18);
	cout << "|__/|__/ /_/ /_//_/";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 19);

//  .__..__..........................._.......
//  .\.\/./.___..__.__......_....__..(_)..___.
//  ..\.././._.\/.//./.....|.|/|/./././../._.\
//  ../_/..\___/\_,_/......|__,__/./_/../_//_/
//  ..........................................

}

void Hud::LoseMessage()
{

	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 10);
	cout << "__   __";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 11);
	cout << "\\ \\/  /___   __ __";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 12);
	cout << " \\  / / _ \\ / // /";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 13);
	cout << " /_/  \\___/ \\_,_/";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 15);
	cout << " _";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 16);
	cout << "| |     ___   ___  ___ ";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 17);
	cout << "| |__  / _ \\ (_-< / -_)";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 18);
	cout << "|____| \\___/ /__/ \\___|";
	goToCoordinates(HUD_POS_X + 3, HUD_POS_Y + HUD_HEIGHT + 19);

//  __   __
//  \ \ / /  ___   _  _    
//   \ V /  / _ \ | || |   
//    |_|   \___/  \_,_|   
//   _
//  | |     ___   ___  ___ 
//  | |__  / _ \ (_-< / -_)
//  |____| \___/ /__/ \___|

}
