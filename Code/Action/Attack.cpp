#include "Attack.h"
#include "game/GameManager.h"

Attack::Attack()
{
}

Attack::~Attack()
{
}

bool Attack::isReady()
{
	return _latency + _activeTime + _cooldown + _lastTimeActivated < TimeManager::GetInstance()->time;
}

void Attack::Actions()
{
	if (_activeTime + _latency + _cooldown + _lastTimeActivated > TimeManager::GetInstance()->time)
	{
		if (_latency + _lastTimeActivated > TimeManager::GetInstance()->time)
		{
			before();
		}
		else if (_latency + _activeTime + _lastTimeActivated > TimeManager::GetInstance()->time)
		{
			during();
			Hit();
		}
		else if (_latency + _activeTime + _cooldown + _lastTimeActivated > TimeManager::GetInstance()->time)
		{
			this->isActive = false;
			after();
		}
	}
}

void Attack::Hit()
{
	if (_direction->_x != 0.0 || _direction->_y != 0.0)
	{
		GameManager *gm = GameManager::GetInstance();
		Player* currentPlay = (*next(gm->_players->begin(), gm->_currentTurn));
		Player* otherPlay = (*next(gm->_players->begin(), gm->_currentTurn == 1 ? 0 : 1));
		Vector2* him = currentPlay->_position;
		Vector2* other = otherPlay->_position;
		if (abs(him->_x - other->_x) == _direction->_x && abs(him->_y - other->_y) == _direction->_y && otherPlay->_state->GetState() != Stuned)
		{
			otherPlay->Hit(_damage);
		}
	}
}
