#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H

#include "StatePlayer.h"

class PlayerState {
public: 
	
	StatePlayer GetState();

	PlayerState();
	~PlayerState();
	
	void SetState(StatePlayer playerState);
private: 
	StatePlayer _state;
};

#endif //_PLAYERSTATE_H