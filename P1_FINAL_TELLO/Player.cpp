#include "Player.h"

Player::Player(Vector4 limits)
{
	position = { limits.x2 / 2,limits.y2 - 3 };
	direction = 1;
	moveToDraw = 2;
	this->limits.x = limits.x + moveToDraw + 1;
	this->limits.x2 = limits.x2 - moveToDraw - 1;

	for (short i = 0; i < BULLET_COUNT; i++)
	{
		Bullet* bullet = new Bullet({0,0}); //Cuando creo el player, le asocio las balas inactivas
		bullets.push_back(bullet);
	}
	width = PLAYER_WIDTH;
	height = PLAYER_HEIGHT;

	lives = 3;
}
Player::~Player()
{
	list<Bullet*>::iterator posBulletIt =bullets.begin();
	while (posBulletIt != bullets.end())
	{
		delete* posBulletIt;
		++posBulletIt;
	}
	bullets.clear();
}
void Player::Draw()
{
	if (direction == 0)	return;	// Cierro el draw del player porque al no moverse, no hay nada que actualizar

	Clear();
	direction = 0;
	
	goToCoordinates(position.x - moveToDraw, position.y);
	cout << static_cast<char>(32) << static_cast<char>(32) << static_cast<char>(30) << static_cast<char>(32) << static_cast<char>(32);
	goToCoordinates(position.x - moveToDraw, position.y + 1);
	cout << static_cast<char>(32) << static_cast<char>(40) << static_cast<char>(206) << static_cast<char>(41) << static_cast<char>(32);
	goToCoordinates(position.x - moveToDraw, position.y + 2);
	cout << static_cast<char>(30) << static_cast<char>(188) << static_cast<char>(32) << static_cast<char>(200) << static_cast<char>(30);
}
void Player::Clear()
{
	for (int i = 0; i < 3; i++)
	{
		goToCoordinates(position.x - moveToDraw - direction, position.y + i);
		cout << "     ";
	}
}
void Player::Update()
{
	//Es preferible moverlo desde afuera, con los inputs del game.cpp
}
void Player::Shoot()
{

	list<Bullet*>::iterator posBulletIt = bullets.begin();
	while (posBulletIt != bullets.end())
	{
		if (!(*posBulletIt)->IsActive())
		{
			(*posBulletIt)->SetActive();

			Vector2 newBulletPos = position;
			newBulletPos.y--;

			(*posBulletIt)->SetPos(newBulletPos);

			posBulletIt = bullets.end();
		}
		else
		{
			++posBulletIt;
		}
	}

}
void Player::MoveRight()
{
	if (position.x < limits.x2)
	{
		direction++;
		position.x += direction;
	}
}
void Player::MoveLeft()
{
	if (position.x > limits.x)
	{
		direction--;
		position.x += direction;
	}
}

void Player::AddPoint()
{
	points++;
}

int Player::GetPoints()
{
	return points;
}

void Player::RemoveOneLife()
{
	lives--;
}

int Player::GetLives()
{
	return lives;
}
