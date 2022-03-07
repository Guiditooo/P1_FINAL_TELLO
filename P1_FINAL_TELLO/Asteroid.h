#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
private:
	static int amountAsteroids;
	int frameCounter;
	int fallSpeed;
	bool moving;
	int delay;
public:
	Asteroid(int delay, int fallSpeed);
	~Asteroid();
	void Draw() override;
	void Clear() override;
	void Update() override;
	static int GetAmount() { return amountAsteroids; }
	void ResetAsteroid();
	bool IsMoving();
	void SetMovement(bool movement);
};
#endif