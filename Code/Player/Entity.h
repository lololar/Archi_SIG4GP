#ifndef _ENTITY_H
#define _ENTITY_H

#include "Utils\Vector2.h"
#include "Action\UpAttack.h"
#include "Action\LowAttack.h"
#include "Action\BasicAttack.h"
#include "Action\Move.h"
#include "Action\Jump.h"
#include "Action\Crouch.h"
#include "Action\Block.h"

class Entity {
public: 
	int _life;
	Vector2 * _position;

	Entity();
	~Entity();
	
	void Hit(int damage);
	virtual void Run() = 0;
};

#endif //_ENTITY_H