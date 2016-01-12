#include "GameManager.h"
#include <time.h>
#include <iterator>
#include <Windows.h>

void GameManager::Run() {

	/* Le temps est fake, étant donné le tour par tour.
	
	_timeManager->deltaTime = difftime(time(0), (time_t)_timeManager->start) - _timeManager->time;
	_timeManager->time += difftime(time(0), (time_t)_timeManager->start);*/

	for (int i = key_a; i <= key_z; i++)
	{
		_inputManager->charPress[i] = false;
	}

	cout << "Joueur " << _currentTurn + 1 << " :" << endl;
	cout << "A pour une attaque NORMALE" << endl;
	cout << "Z pour une attaque HAUTE" << endl;
	cout << "E pour une attaque BASSE" << endl;
	cout << "R pour BLOQUER" << endl;
	cout << "I pour SAUTER" << endl;
	cout << "J pour aller à GAUCHE" << endl;
	cout << "K pour SE BAISSER" << endl;
	cout << "L pour aller à DROITE" << endl;

	cout << endl;

	cout << "Vie J1 : " << (*next(_players->begin(), 0))->_life << " / Vie J2 : " << (*next(_players->begin(), 1))->_life << endl;
	cout << "Position J1 : " << (*next(_players->begin(), 0))->_position << " / Position J2 : " << (*next(_players->begin(), 1))->_position << endl;

	char* str = new char[25];

	cout << _timeManager->time << endl;

	cin >> str;
	
	for (unsigned int c = 0; c < string(str).size(); c++)
	{
		_inputManager->charPress[str[c]] = true;
		cout << str[c] << endl;
	}
	
	(*next(_players->begin(), _currentTurn))->Run();

	if (_currentTurn == 1)
	{
		_currentTurn = 0;

		_timeManager->deltaTime = 0.1;
		_timeManager->time += _timeManager->deltaTime;
	}
	else
	{
		_currentTurn = 1;
	}

	delete str;
}

GameManager::GameManager()
{
	_timeManager = TimeManager::GetInstance();
	//_timeManager->start = (double)time(0);
	_inputManager = InputManager::GetInstance();

	_arena = new Zone(20.0, 10.0);
	_players = new list<Player*>();
	FabriquePlayer fp = FabriquePlayer();
	_players->push_back((Player*)fp.generateEntity(100, new Vector2(-4, DEFAULT_HEIGHT_PLAYER)));
	_players->push_back((Player*)fp.generateEntity(100, new Vector2(4, DEFAULT_HEIGHT_PLAYER)));
}

void GameManager::SetGameMode(GameMode * gameMode)
{
	_gameMode = gameMode;
}

void GameManager::EndGame()
{
	cout << "Player " << _currentTurn + 1 << " win." << endl;
	_inputManager->charPress[key_q] = true;
	_inputManager->charPress[key_y] = true;
}

GameManager::~GameManager()
{
	_timeManager->DestroySingleton();
	_inputManager->DestroySingleton();

	if (_arena != nullptr)
	{
		delete _arena;
	}
	if (_players != nullptr)
	{
		for (list<Player*>::iterator it = _players->begin(); it != _players->end(); ++it)
		{
			delete (*it);
		}
		_players->clear();
		delete _players;
	}
	
	if (_gameMode != nullptr)
	{
		delete _gameMode;
	}
}

int main()
{
	GameManager *gameManager = GameManager::GetInstance();

	cout << "Choose your Game Mode : " << endl;
	cout << " - Type a to Adventure Mode" << endl;
	cout << " - Type f to Quick Fight Mode" << endl;
	cout << " - Type t to Tournament Mode" << endl;

	char c;

	cin >> c;

	cout << "You choose " << ((c == key_a) ? "Adventure" : (c == key_f) ? "Quick Fight" : (c == key_t) ? "Tournament" : "No") << " Mode." << endl;

	switch (c)
	{
	case key_a :
		gameManager->SetGameMode(new Adventure());
		break;
	case key_f:
		gameManager->SetGameMode(new QuickFight());
		break;
	case key_t:
		gameManager->SetGameMode(new Tournament());
		break;
	default:
		gameManager->SetGameMode(nullptr);
		break;
	}

	while (gameManager->_gameMode)
	{
		system("cls");
		gameManager->Run();
		if (InputManager::GetInstance()->charPress[key_q])
		{
			cout << "Would You like to Quit" << endl;
			char s;
			cin >> s;
			if (s == key_y || InputManager::GetInstance()->charPress[key_y])
			{
				break;
			}
		}
	}

	system("pause");

	delete gameManager;

	return 0;
}
