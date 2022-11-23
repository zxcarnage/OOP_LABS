#include "Account_test.h"
template<typename T>
Account_test<T>::Account_test()
{
	_data = T();
}

template<typename T>
void Account_test<T>::SetData(T data)
{
	_data = data;
}

template<typename T>
T Account_test<T>::GetData()
{
	return _data;
}
