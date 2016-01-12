#ifndef _FABRIQUEPLAYER_H
#define _FABRIQUEPLAYER_H

#include "FabriqueEntity.h"

#include "Player\Player.h"

class FabriquePlayer: public FabriqueEntity {
public:
	FabriquePlayer() {};
	~FabriquePlayer() {};
	
	Entity * generateEntity(int life, Vector2* position) override;
};

#endif //_FABRIQUEPLAYER_H