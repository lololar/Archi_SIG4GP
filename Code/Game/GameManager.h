#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H


#define MAX_CHAR_IN_CIN 20
#define ESC 27
#define DEFAULT_HEIGHT_PLAYER 2
#define DEFAULT_JUMP_HEIGHT 2
#define DEFAULT_CROUCH_HEIGHT 2

#include "Singleton.h"
#include "Game\FabriquePlayer.h"
#include "Adventure.h"
#include "Tournament.h"
#include "QuickFight.h"
#include "Zone.h"

using namespace std;

class GameManager: public Singleton<GameManager> {
public: 
	TimeManager* _timeManager;
	InputManager* _inputManager;

	list<Player*>* _players;
	GameMode * _gameMode;
	float _timeLeft;
	Zone * _arena;

	int _currentTurn = 0;

	void SetGameMode(GameMode* gameMode);
	void EndGame();

	GameManager();
	~GameManager();
	
	void Run();
};

#endif //_GAMEMANAGER_H