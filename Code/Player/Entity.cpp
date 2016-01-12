#include "Entity.h"
#include "game/GameManager.h"

Entity::Entity()
{

}

Entity::~Entity()
{
	delete _position;
}

void Entity::Hit(int damage)
{
	_life -= damage;
	if (_life <= 0)
	{
		GameManager::GetInstance()->EndGame();
	}
}
