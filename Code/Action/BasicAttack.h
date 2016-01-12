#ifndef _BASICATTACK_H
#define _BASICATTACK_H

#include "Attack.h"

class BasicAttack: public Attack {
public: 

	BasicAttack();
	~BasicAttack();
	
	void doAction() override;

	void before() override;
	void during() override;
	void after() override;
};

#endif //_BASICATTACK_H