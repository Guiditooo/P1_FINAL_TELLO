#ifndef ENTITY_H
#define ENTITY_H

#include "../lib/AwesomeLibrary.h"

#include "Constants.h"

class Entity
{
protected:
	Vector2 position;
	int width;
	int height;
public:
	virtual void Draw() = 0;
	virtual void Clear() = 0;
	virtual void Update() = 0;
	bool CheckCollision(Entity* other);
	Vector2 GetSize();
	Vector2 GetPos() { return position; }
	void SetSize(Vector2 newSize);
	Entity();
	~Entity();
};
#endif