#ifndef _FABRIQUEENTITY_H
#define _FABRIQUEENTITY_H

#include "Player\Entity.h"

class FabriqueEntity {
public:
	FabriqueEntity() {};
	~FabriqueEntity() {};
	
	virtual Entity * generateEntity(int life, Vector2* position) = 0;
};

#endif //_FABRIQUEENTITY_H