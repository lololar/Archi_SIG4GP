#ifndef _LOWATTACK_H
#define _LOWATTACK_H

#include "Attack.h"


class LowAttack: public Attack {
public:

	LowAttack();
	~LowAttack();
	
	void doAction() override;

	void before() override;
	void during() override;
	void after() override;
};

#endif //_LOWATTACK_H