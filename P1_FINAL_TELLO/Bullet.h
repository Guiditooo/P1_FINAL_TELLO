#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
private:
	static int amountBullet;
	static int frameCounter;
	int direction;
	bool active;
public:
	Bullet(Vector2 position);
	void Draw() override;
	void Clear() override;
	void Update() override;
	static int GetAmount() { return amountBullet; };
	void SetPos(Vector2 newPos);
	bool IsActive() { return active; }
	void SetActive();
	void SetInactive();
};
#endif