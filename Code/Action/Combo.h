#pragma once
#include "Attack.h"

using namespace std;

class Combo : public Attack
{
public:
	Combo();
	~Combo();

	void AddAction(Action * action);
	void RemoveAction();
	Action * GetChildren(int index);

	void doAction() override;

	void before() override;
	void during() override;
	void after() override;

private:
	list<Action*>* _actions;
};

