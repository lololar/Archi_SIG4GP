#include "Combo.h"

Combo::Combo()
{
	_actions = new list<Action*>();
	_direction = new Vector2(0.0, 0.0);
	_damage = 0;
}


Combo::~Combo()
{
	_actions->clear();
	delete _actions;
	delete _direction;
}

void Combo::AddAction(Action * action)
{
	if (action != nullptr)
	{
		_actions->push_back(action);
	}
}

void Combo::RemoveAction()
{
	_actions = nullptr;
}

Action * Combo::GetChildren(int index)
{
	return (*next(_actions->begin(), index));
}

void Combo::doAction()
{
	bool isActive = true;
	for (list<Action*>::iterator it = _actions->begin(); it != _actions->end(); it++)
	{
		isActive &= !reinterpret_cast<Attack*>(*it)->isReady();
	}
	if (!this->isActive && isActive && isReady())
	{
		_lastTimeActivated = TimeManager::GetInstance()->time;
	}
	this->isActive = isActive;

	Actions();
}

void Combo::before()
{
	
}

void Combo::during()
{
	int combo = 0;
	for (list<Action*>::iterator it = _actions->begin(); it != _actions->end(); it++)
	{
		_direction->_x = 0.0;
		_direction->_y = 0.0;
		Attack* att = reinterpret_cast<Attack*>(*it);
		if (att)
		{
			combo += att->_damage / 10;
			_direction = att->_direction;
		}
		combo += 1;
		_damage = combo;
		Hit();
	}

	_direction->_x = 0.0;
	_direction->_y = 0.0;
}

void Combo::after()
{
	
}