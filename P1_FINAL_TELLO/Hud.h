#ifndef HUD_H
#define HUD_H

#include "Asteroid.h"
#include "Player.h"

class Hud
{
private:
	Player* player;
	bool reDraw;
public:
	Hud(Player* player);
	~Hud();
	void Refresh();
	void Draw();
	void WinMessage();
	void LoseMessage();
};

#endif