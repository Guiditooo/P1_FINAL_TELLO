#include "Entity.h"

bool Entity::CheckCollision(Entity* other)
{
	//Arriba al medio

	bool aux = false;

	if (other->GetPos().x + static_cast<int>((static_cast<float>(other->GetSize().x) / 2)) <= this->GetPos().x + static_cast<int>((static_cast<float>(this->GetSize().x) / 2)) 
	&&  other->GetPos().x + static_cast<int>((static_cast<float>(other->GetSize().x) / 2)) >= this->GetPos().x - static_cast<int>(static_cast<float>(this->GetSize().x) / 2))
	{
		if (other->GetPos().y + other->GetSize().y <= this->GetPos().y + this->GetSize().y &&  other->GetPos().y >= this->GetPos().y)
		{
			aux = true;
		}
	}

	return aux;
}

Vector2 Entity::GetSize()
{
	Vector2 size = { width,height };
	return size;
}

void Entity::SetSize(Vector2 newSize)
{
	width = newSize.x;
	height = newSize.y;
}

Entity::Entity()
{
	this->position = {0,0};
	width = 1;
	height = 1;
}
Entity::~Entity() { }