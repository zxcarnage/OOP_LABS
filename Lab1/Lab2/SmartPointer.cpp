#include "SmartPointer.h"

template<typename T>
SmartPointer<T>::SmartPointer()
{
	_pointer = nullptr;
}

template<typename T>
SmartPointer<T>::SmartPointer(T object)
{
	*_pointer = object;
}

template<typename T>
SmartPointer<T>::SmartPointer(T* pointer)
{
	pointer = _pointer;
}

template<typename T>
SmartPointer<T>::SmartPointer(SmartPointer& other)
{
	*other = *_pointer;
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
	CleanUp();
}

template<typename T>
T& SmartPointer<T>::operator*()
{
	return *_pointer;
}

template<typename T>
void SmartPointer<T>::operator=(SmartPointer && other)
{
	CleanUp();
	_pointer = other._pointer;
	if(other._pointer)
		other._pointer = nullptr;
}

template<typename T>
T* SmartPointer<T>::operator->()
{
	return _pointer;
}

template<typename T>
void SmartPointer<T>::CleanUp()
{
	if (_pointer)
		delete _pointer;
}
