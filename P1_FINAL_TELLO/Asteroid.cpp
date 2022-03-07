#include "Asteroid.h"

#include <iostream>

int Asteroid::amountAsteroids = 0;

Asteroid::Asteroid(int delay, int fallSpeed)
{
	ResetAsteroid();
	this->delay = delay;
	frameCounter = 0;
	this->fallSpeed = fallSpeed;

	amountAsteroids++;

	width = 0;
	height = 0;
}
Asteroid::~Asteroid()
{
	amountAsteroids--;
}
void Asteroid::Draw()
{
	goToCoordinates(position.x, position.y);
	std::cout << "*";
}
void Asteroid::Clear()
{
	goToCoordinates(position.x, position.y);
	std::cout << " ";
}
void Asteroid::Update()
{
	frameCounter++;
	if (frameCounter % fallSpeed == 0)
	{
		Clear();
		position.y++;
	}
}

void Asteroid::ResetAsteroid()
{
	position.x = rand() % (FRAME_WIDTH - 2) + 1;
	position.y = 1;
}

bool Asteroid::IsMoving()
{
	return moving;
}

void Asteroid::SetMovement(bool movement)
{
	moving = movement;
}
