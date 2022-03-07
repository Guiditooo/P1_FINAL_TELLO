#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Hud.h"
#include "Asteroid.h"

#include <time.h>

class Game
{
protected:
	Vector4 limits;
private:
	Hud* hud;
	Player* player;
	std::list <Asteroid*> asteroids;
	bool isPlaying;
	bool playerLose;
	
	void Start();
	void Update();
	void Input();
	void Movements();
	void Draw();
	void End();
	void SetConfig();

	void BulletsMovement();
	void CheckCollisionBulletsAsteroids();

	void AsteroidsMovement();
	void CheckAsteroidsCollisions();

	void DrawBullets();
	void DrawAsteroids();

	void CheckWinCondition();

public:
	Game();
	~Game();
	void Run();
};
#endif