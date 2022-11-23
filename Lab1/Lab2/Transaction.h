#pragma once
#include <iostream>
#include "SmartPointer.h"
using std::cout;
using std::cin;
using std::endl;
template<typename T>
class Transaction
{
	SmartPointer<T> _previousState;
	SmartPointer<T> _currentState;
public:
	Transaction();
	Transaction(Transaction<T> && other);

	void operator=(Transaction<T>&& other);
	T* operator->();

	void Show();
	bool Begin(T newState);
	void Commit();
	bool Undo();
};
