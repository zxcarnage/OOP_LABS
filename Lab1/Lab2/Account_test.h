#pragma once
template <typename T>
class Account_test {
	T _data;
public:
	Account_test();
	void SetData(T data);
	T GetData();
};
