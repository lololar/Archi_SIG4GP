#include "Player.h"
#include "Game/GameManager.h"

Player::Player()
{
	_actions = new list<Action*>();
	_attacks = new list<Attack*>();
	_combos = new list<Combo*>();
	_state = new PlayerState();

	_currentAttack = nullptr;

	_state->SetState(StatePlayer::Normal);
}

Player::~Player()
{
	for (list<Action*>::iterator it = _actions->begin(); it != _actions->end(); ++it)
	{
		delete (*it);
	}
	_actions->clear();
	delete _actions;
	for (list<Attack*>::iterator it = _attacks->begin(); it != _attacks->end(); ++it)
	{
		delete (*it);
	}
	_attacks->clear();
	delete _attacks;
	for (list<Combo*>::iterator it = _combos->begin(); it != _combos->end(); ++it)
	{
		delete (*it);
	}
	_combos->clear();
	delete _combos;
	delete _state;
}

void Player::SetAction(Action * a)
{
	if (a != nullptr)
	{
		_actions->push_back(a);
	}
}

void Player::SetAttack(Attack * a)
{
	if (a != nullptr)
	{
		_attacks->push_back(a);
	}
}

void Player::SetCombo(Combo * c)
{
	if (c != nullptr)
	{
		_combos->push_back(c);
	}
}

void Player::Hit(int damage)
{
	Entity::Hit(damage);
	_state->SetState(Stuned);
	timeLastStun = TimeManager::GetInstance()->time;
}

void Player::Run()
{
	if (_state->GetState() != Stuned || _state->GetState() != Blocking)
	{
		for (int i = key_a; i <= key_z; i++)
		{
			if (InputManager::GetInstance()->charPress[i])
			{
				Move* move;
				char c = i;
				switch (c)
				{
				case key_a : // Basic Attack
					if (_currentAttack == nullptr)
					{
						(*next(_attacks->begin(), 0))->isActive = true;
						_currentAttack = (*next(_attacks->begin(), 0));
						_state->SetState(Attacking);
					}
					break;
				case key_z: // Up Attack
					if (_currentAttack == nullptr)
					{
						(*next(_attacks->begin(), 1))->isActive = true;
						_currentAttack = (*next(_attacks->begin(), 1));
						_state->SetState(Attacking);
					}
					break;
				case key_e: // Low Attack
					if (_currentAttack == nullptr)
					{
						(*next(_attacks->begin(), 2))->isActive = true;
						_currentAttack = (*next(_attacks->begin(), 2));
						_state->SetState(Attacking);
					}
					break;
				case key_r: // Block
					(*next(_actions->begin(), 3))->doAction();
					_state->SetState(Blocking);
					timeLastBlock = TimeManager::GetInstance()->time;
					break;
				case key_i: // Jump
					if (_position->_y == DEFAULT_HEIGHT_PLAYER)
					{
						(*next(_actions->begin(), 1))->doAction();
						timeLastJump = TimeManager::GetInstance()->time;
					}
					break;
				case key_j: // Left
					move = reinterpret_cast<Move*>(*next(_actions->begin(), 0));
					move->_direction = -1;
					move->doAction();
					break;
				case key_k: // Crouch
					if (_position->_y == DEFAULT_HEIGHT_PLAYER)
					{
						(*next(_actions->begin(), 2))->doAction();
						timeLastCrouch = TimeManager::GetInstance()->time;
					}
					break;
				case key_l: // Right
					move = reinterpret_cast<Move*>(*next(_actions->begin(), 0));
					move->_direction = 1;
					move->doAction();
					break;
				default:
					break;
				}
			}
		}
		if (_currentAttack != nullptr)
		{
			if (_currentAttack->isActive)
			{
				_currentAttack->doAction();
			}
			else
			{
				_currentAttack = nullptr;
				_state->SetState(Normal);
			}
		}
	}

	// Un soucis fait que le combo fonctionne, mais applique les dégats du premier coup à chaque tour.
	/*for (list<Combo*>::iterator it = _combos->begin(); it != _combos->end(); ++it)
	{
		(*it)->doAction();
	}*/

	if (timeLastStun + timeStunDelay < TimeManager::GetInstance()->time && _state->GetState() == Stuned)
	{
		_state->SetState(Normal);
	}

	if (timeLastBlock + timeBlockDelay < TimeManager::GetInstance()->time && _state->GetState() == Blocking)
	{
		_state->SetState(Normal);
	}

	if (timeLastJump + timeJump < TimeManager::GetInstance()->time && timeLastCrouch + timeCrouch < TimeManager::GetInstance()->time)
	{
		_position->_y = DEFAULT_HEIGHT_PLAYER;
	}
}