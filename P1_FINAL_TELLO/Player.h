#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"

#include <list>

class Player : public Entity
{
private:
	int direction;
	int moveToDraw;
	Vector4 limits;
	int points;
	int lives;
public:
	std::list<Bullet*> bullets;
	Player(Vector4 limits);
	~Player();
	void Draw() override;
	void Clear() override;
	void Update() override;
	void Shoot();
	void MoveRight();
	void MoveLeft();
	void AddPoint();
	int GetPoints();
	void RemoveOneLife();
	int GetLives();
};
#endif