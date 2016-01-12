#include "Crouch.h"
#include "game/GameManager.h"

Crouch::Crouch()
{
	_CrouchHeight = DEFAULT_CROUCH_HEIGHT;
}

Crouch::~Crouch()
{
}

void Crouch::doAction() {

	Vector2* position = (*next(GameManager::GetInstance()->_players->begin(), GameManager::GetInstance()->_currentTurn))->_position;
	Zone* z = GameManager::GetInstance()->_arena;
	if (position->_y - _CrouchHeight <= z->_mapWidth / 2 && position->_y - _CrouchHeight >= -z->_mapWidth / 2)
	{
		position->_y -= _CrouchHeight;
	}
}