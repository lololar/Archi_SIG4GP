#include "LowAttack.h"
#include "game/GameManager.h"

LowAttack::LowAttack()
{
	_direction = new Vector2(1.0, -DEFAULT_CROUCH_HEIGHT);
	_damage = 15;
}

LowAttack::~LowAttack()
{
	delete _direction;
}

void LowAttack::doAction() {

	if (isReady())
	{
		isActive = true;
		_lastTimeActivated = TimeManager::GetInstance()->time;
	}

	Actions();
}

void LowAttack::before()
{
	
}

void LowAttack::during()
{
	
}

void LowAttack::after()
{
	
}