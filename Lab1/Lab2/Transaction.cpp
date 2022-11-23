#include "Transaction.h"
template<typename T>
Transaction<T>::Transaction()
{
	_previousState();
	_currentState(new T);
}
template<typename T>
Transaction<T>::Transaction(Transaction<T> && other)
{
	other.*_previousState = *_previousState;
	other.*_currentState = *_currentState;
}

template<typename T>
void Transaction<T>::operator=(Transaction<T> && other)
{
	other.*_previousState = *_previousState;
	other.*_currentState = *_currentState;
}

template<typename T>
T* Transaction<T>::operator->()
{
	return _currentState;
}

template<typename T>
void Transaction<T>::Show()
{
	cout << "Previous state: " << *_previousState << endl;
	cout << "Current state :" << *_currentState << endl;
}

template<typename T>
bool Transaction<T>::Begin(T newState)
{
	_previousState = _currentState;
	_currentState(newState);
	if (_currentState == nullptr)
		return false;
	return true;
}

template<typename T>
void Transaction<T>::Commit()
{
	_previousState = nullptr;
}

template<typename T>
bool Transaction<T>::Undo()
{
	if (_previousState == nullptr)
		return false;
	_currentState = _previousState;
}
