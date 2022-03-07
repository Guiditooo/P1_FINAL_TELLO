#include "Game.h"

#include <time.h>

Game::Game()
{
	limits = { 0, 0, FRAME_WIDTH, FRAME_HEIGHT };

	player = new Player(limits);
	hud = new Hud(player);
	
	isPlaying = true;

	for (short i = 0; i < ASTEROID_COUNT; i++)
	{
		Asteroid* ast = new Asteroid(i, rand() % ASTEROID_MAX_SPEED + ASTEROID_MIN_SPEED);
		asteroids.push_back(ast);
	}

	playerLose = false;

	Start();
}
Game::~Game()
{

	list<Asteroid*>::iterator posAsteroidIt = asteroids.begin();
	while (posAsteroidIt != asteroids.end())
	{
		delete* posAsteroidIt;
		++posAsteroidIt;
	}
	asteroids.clear();

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}

	if (hud != nullptr)
	{
		delete hud;
		hud = nullptr;
	}

	

}
void Game::Start()
{
	SetConfig();
}

void Game::Update()
{
	while (isPlaying)
	{
		Input();		// Chequea Input del Player.
		Movements();	// Mueve los Asteroides y las Balas.
		Draw();			// Se dibujan las entidades y la HUD.
		CheckWinCondition();
		miliSleep(100);
	}
}
void Game::Input()
{
	int keyPressed = getKey(false);

	if (keyPressed == KEY_ESC)
	{
		isPlaying = false;
	}
	else if (keyPressed == KEY_SPACE)
	{
		player->Shoot();
	}
	else if (keyPressed == KEY_A)
	{
		player->MoveLeft();
	}
	else if (keyPressed == KEY_D)
	{
		player->MoveRight();
	}
}
void Game::Movements()
{
	BulletsMovement();
	CheckCollisionBulletsAsteroids();

	AsteroidsMovement();
	CheckAsteroidsCollisions();
}
void Game::Draw()
{

	DrawAsteroids();

	DrawBullets();
		
	if (player != nullptr) player->Draw();

	if (hud != nullptr) hud->Draw();

}
void Game::End()
{
	// Mostrar el Game Over
	goToCoordinates(1, FRAME_HEIGHT + 5);
	cout << "Press a key to end the game!";
	getKey(true);
	// Que pulse una tecla para continuar
}
void Game::SetConfig()
{
	setTitle("P1 Final Tello.");
	srand(time(nullptr));
	hideCursor();
	drawFrame(limits.x, limits.y, limits.x2, limits.y2);
	player->Draw();
}
void Game::BulletsMovement()
{
	list<Bullet*>::iterator posBulletIt = player->bullets.begin();
	while (posBulletIt != player->bullets.end())
	{
		if ((*posBulletIt)->IsActive())
		{
			(*posBulletIt)->Update();
			if ((*posBulletIt)->GetPos().y < 1)
			{
				(*posBulletIt)->SetInactive();
			}
		}
		++posBulletIt;
	}
}
void Game::CheckCollisionBulletsAsteroids()
{
	list<Bullet*>::iterator posBulletIt = player->bullets.begin();

	while (posBulletIt != player->bullets.end())
	{
		if ((*posBulletIt)->IsActive())
		{
			list<Asteroid*>::iterator posAsteroidIt = asteroids.begin();
			while (posAsteroidIt != asteroids.end())
			{
				if ((*posAsteroidIt)->CheckCollision(*posBulletIt))
				{
					(*posAsteroidIt)->Clear();
					(*posAsteroidIt)->ResetAsteroid();
					(*posBulletIt)->SetInactive();
					player->AddPoint();
					hud->Refresh();
				}

				++posAsteroidIt;

			}

		}

		++posBulletIt;

	}
}
void Game::AsteroidsMovement()
{
	list<Asteroid*>::iterator posAsteroidIt = asteroids.begin();
	while (posAsteroidIt != asteroids.end())
	{
		(*posAsteroidIt)->Update();
		++posAsteroidIt;
	}
}
void Game::CheckAsteroidsCollisions()
{
	if (!asteroids.empty())
	{
		list<Asteroid*>::iterator posAsteroidIt = asteroids.begin();
		while (posAsteroidIt != asteroids.end())
		{
			if ((player)->CheckCollision(*posAsteroidIt))
			{
				(*posAsteroidIt)->ResetAsteroid();
				player->RemoveOneLife();
				hud->Refresh();
			}
			else if ((*posAsteroidIt)->GetPos().y >= FRAME_HEIGHT)
			{
				(*posAsteroidIt)->ResetAsteroid();
			}
			else
			{
				list<Bullet*>::iterator posBulletIt = player->bullets.begin();
				while (posBulletIt != player->bullets.end())
				{
					if ((*posBulletIt)->IsActive())
					{

						if ((*posAsteroidIt)->CheckCollision(*posBulletIt))
						{
							(*posAsteroidIt)->Clear();
							(*posAsteroidIt)->ResetAsteroid();
							(*posBulletIt)->SetInactive();
							player->AddPoint();
							hud->Refresh();
						}

					}

					++posBulletIt;

				}
			}
			++posAsteroidIt;
		}
	}
}

void Game::DrawBullets()
{
	list<Bullet*>::iterator posBulletIt = player->bullets.begin();
	while (posBulletIt != player->bullets.end())
	{
		if ((*posBulletIt)->IsActive())
		{
			(*posBulletIt)->Clear();
			(*posBulletIt)->Draw();
		}
		++posBulletIt;
	}
}

void Game::DrawAsteroids()
{
	list<Asteroid*>::iterator posAsteroidIt = asteroids.begin();
	while (posAsteroidIt != asteroids.end())
	{
		(*posAsteroidIt)->Draw();
		++posAsteroidIt;
	}
}

void Game::CheckWinCondition()
{
	if (player->GetLives() <= 0)
	{
		playerLose = true;
		isPlaying = false;
		hud->LoseMessage();
		End();
	}
	if (player->GetPoints() >= TARGET_WIN_CONDITION)
	{
		playerLose = false;
		isPlaying = false;
		hud->WinMessage();
		End();
	}
}

void Game::Run()
{
	Start();
	Update();
	End();
}