#include "BasicAttack.h"

BasicAttack::BasicAttack()
{
	_direction = new Vector2(1.0, 0.0);
	_damage = 25;
}

BasicAttack::~BasicAttack()
{
	delete _direction;
}

void BasicAttack::doAction()
{
	if (isReady())
	{
		isActive = true;
		_lastTimeActivated = TimeManager::GetInstance()->time;
	}

	Actions();
}

void BasicAttack::before()
{
	
}

void BasicAttack::during()
{
	
}

void BasicAttack::after()
{
	
}