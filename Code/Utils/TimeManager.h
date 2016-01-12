#ifndef _STRUCTIME_H
#define _STRUCTIME_H

#include "Game\Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
public:
	double start;
	double time;
	double deltaTime;
};

#endif