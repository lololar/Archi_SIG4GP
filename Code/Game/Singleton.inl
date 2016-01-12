#include "Singleton.h"

template<class T>
T* Singleton<T>::mInstance = nullptr;

template<class T>
Singleton<T>::Singleton()
{
}

template<class T>
Singleton<T>::~Singleton()
{
	//DestroySingleton();
}

template<class T>
T* Singleton<T>::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new T();
	}
	return static_cast<T*>(mInstance);
}

template<class T>
void Singleton<T>::DestroySingleton()
{
	if (mInstance != nullptr)
	{
		delete mInstance;
		mInstance = nullptr;
	}
}
