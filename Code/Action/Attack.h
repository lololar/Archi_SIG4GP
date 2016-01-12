#ifndef _ATTACK_H
#define _ATTACK_H

#include "Action.h"

class Player;

class Attack: public Action {
public: 
	double _latency;
	double _cooldown;
	double _activeTime;
	double _lastTimeActivated = DEFAULT_TIME;

	int _damage;
	Vector2* _direction;

	Attack();
	~Attack();
	
	bool isReady();

	void Actions();

	virtual void before() = 0;
	virtual void during() = 0;
	virtual void after() = 0;

	void Hit();

	virtual void doAction() = 0;
};

#endif //_ATTACK_H