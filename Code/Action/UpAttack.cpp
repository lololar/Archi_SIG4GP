#include "UpAttack.h"
#include "game/GameManager.h"

UpAttack::UpAttack()
{
	_direction = new Vector2(1.0, DEFAULT_JUMP_HEIGHT);
	_damage = 45;
}

UpAttack::~UpAttack()
{
	delete _direction;
}

void UpAttack::doAction() {

	if (isReady())
	{
		isActive = true;
		_lastTimeActivated = TimeManager::GetInstance()->time;
	}

	Actions();
}

void UpAttack::before()
{
	
}

void UpAttack::during()
{
	
}

void UpAttack::after()
{
	
}