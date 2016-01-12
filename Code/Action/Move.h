#ifndef _MOVE_H
#define _MOVE_H

#include "Action.h"


class Move: public Action {
public:

	Move();
	~Move();

	int _direction = 0;
	
	void doAction() override;
};

#endif //_MOVE_H