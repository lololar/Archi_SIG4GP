#ifndef _CROUCH_H
#define _CROUCH_H

#include "Action.h"


class Crouch: public Action {
public:

	Crouch();
	~Crouch();

	int _CrouchHeight;
	
	void doAction() override;
};

#endif //_CROUCH_H