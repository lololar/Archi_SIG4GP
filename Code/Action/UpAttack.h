#ifndef _UPATTACK_H
#define _UPATTACK_H

#include "Attack.h"


class UpAttack: public Attack {
public:

	UpAttack();
	~UpAttack();
	
	void doAction() override;

	void before() override;
	void during() override;
	void after() override;
};

#endif //_UPATTACK_H