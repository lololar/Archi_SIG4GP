#include "FabriquePlayer.h"

Entity* FabriquePlayer::generateEntity(int life, Vector2 * position)
{

	//SET PLAYER

	Player* player = new Player();

	player->_life = life;
	player->_position = position;

	//SET ACTIONS

	Move * move = new Move();
	Jump * jump = new Jump();
	Crouch * crouch = new Crouch();
	Block * block = new Block();

	player->SetAction(move);
	player->SetAction(jump);
	player->SetAction(crouch);
	player->SetAction(block);

	//SET ATTACKS

	BasicAttack * basicAttack = new BasicAttack();
	UpAttack * upAttack = new UpAttack();
	LowAttack * lowAttack = new LowAttack();

	basicAttack->_latency = 0.3;
	basicAttack->_activeTime = 0.5;
	basicAttack->_cooldown = 0.2;

	upAttack->_latency = 0.4;
	upAttack->_activeTime = 0.3;
	upAttack->_cooldown = 0.3;

	lowAttack->_latency = 0.3;
	lowAttack->_activeTime = 0.3;
	lowAttack->_cooldown = 0.4;

	player->SetAttack(basicAttack);
	player->SetAttack(upAttack);
	player->SetAttack(lowAttack);

	//SET COMBOS

	Combo* combo = new Combo();
	combo->AddAction(basicAttack);
	combo->AddAction(upAttack);

	combo->_latency = (upAttack->_latency + upAttack->_latency) / 2;
	combo->_activeTime = (upAttack->_activeTime + upAttack->_activeTime) / 2;
	combo->_cooldown = (upAttack->_cooldown + upAttack->_cooldown) / 2;

	player->SetCombo(combo);

	return player;
}
