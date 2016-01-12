#include "Jump.h"
#include "game/GameManager.h"

Jump::Jump()
{
	_JumpHeight = DEFAULT_JUMP_HEIGHT;
}

Jump::~Jump()
{
}

void Jump::doAction() {
	Vector2* position = (*next(GameManager::GetInstance()->_players->begin(), GameManager::GetInstance()->_currentTurn))->_position;
	Zone* z = GameManager::GetInstance()->_arena;
	if (position->_y + _JumpHeight <= z->_mapWidth / 2 && position->_y + _JumpHeight >= -z->_mapWidth / 2)
	{
		position->_y += _JumpHeight;
	}
}