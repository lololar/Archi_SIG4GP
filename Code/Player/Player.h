#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"

#include "Action\Combo.h"
#include "PlayerState.h"
#include "Utils\InputManager.h"

using namespace std;

class Player: public Entity {
public: 
	list<Action*>* _actions;
	list<Attack*>* _attacks;
	list<Combo*>* _combos;
	PlayerState* _state;

	Attack* _currentAttack;

	double timeLastStun = DEFAULT_TIME;
	double timeStunDelay = .2;

	double timeLastBlock = DEFAULT_TIME;
	double timeBlockDelay = .5;

	double timeLastJump = DEFAULT_TIME;
	double timeJump = .5;

	double timeLastCrouch = DEFAULT_TIME;
	double timeCrouch = .5;

	Player();
	~Player();

	void SetAction(Action * a);
	void SetAttack(Attack * a);
	void SetCombo(Combo * c);
	void Hit(int damage);

	void Run() override;
};

#endif //_PLAYER_H