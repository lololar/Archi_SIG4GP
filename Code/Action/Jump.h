#ifndef _JUMP_H
#define _JUMP_H

#include "Action.h"


class Jump: public Action {
public:

	Jump();
	~Jump();
	
	int _JumpHeight;

	void doAction() override;
};

#endif //_JUMP_H