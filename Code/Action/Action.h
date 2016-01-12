#ifndef _ACTION_H
#define _ACTION_H

#include "Utils\InputManager.h"
#include "Utils\TimeManager.h"
#include "Utils\Vector2.h"

class Action {
public: 

	bool isActive = false;

	Action();
	~Action();
	virtual void doAction() = 0;

};

#endif //_ACTION_H