#include "Bullet.h"

int Bullet::frameCounter = 0;

Bullet::Bullet(Vector2 position)
{
	this->position = position;
	direction = -1;
	active = false;
	width = 0;
	height = 0;
}
void Bullet::Draw()
{
	goToCoordinates(position.x, position.y);
	cout << static_cast<char>(94);
}
void Bullet::Clear()
{
	goToCoordinates(position.x , position.y);
	cout << " ";
}
void Bullet::Update()
{
	frameCounter++;
	if (frameCounter % 1 == 0)
	{
		Clear();
		position.y += direction;
	}
	
}

void Bullet::SetPos(Vector2 newPos)
{
	position = newPos;
}

void Bullet::SetActive()
{
	active = true;
}

void Bullet::SetInactive()
{
	active = false;
}
