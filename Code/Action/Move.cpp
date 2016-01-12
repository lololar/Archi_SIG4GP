#include "Move.h"
#include "Game\GameManager.h"

Move::Move()
{
}

Move::~Move()
{
}

void Move::doAction()
{
	Vector2* position = (*next(GameManager::GetInstance()->_players->begin(), GameManager::GetInstance()->_currentTurn))->_position;
	Zone* z = GameManager::GetInstance()->_arena;
	if (position->_x + _direction <= z->_mapWidth / 2 && position->_x + _direction >= -z->_mapWidth / 2)
	{
		position->_x += _direction;
	}
}