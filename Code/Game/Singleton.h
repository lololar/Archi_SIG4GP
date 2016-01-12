#ifndef SINGLETON_H
#define SINGLETON_H

template<class T>
class Singleton
{
protected:
	Singleton();
	~Singleton();

public:
	static T* GetInstance();
	static void DestroySingleton();

private:
	static T* mInstance;
};

#include "Singleton.inl"

#endif
