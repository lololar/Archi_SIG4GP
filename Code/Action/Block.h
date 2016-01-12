#ifndef _BLOCK_H
#define _BLOCK_H

#include "Action.h"


class Block: public Action {
public:

	Block();
	~Block();
	
	void doAction() override;
};

#endif //_BLOCK_H