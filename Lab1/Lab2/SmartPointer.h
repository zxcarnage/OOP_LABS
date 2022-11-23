#pragma once

template<typename T>
class SmartPointer
{
	T* _pointer;

public:
	SmartPointer();
	SmartPointer(T object);
	SmartPointer(T* pointer);
	SmartPointer(SmartPointer& other);
	~SmartPointer();
	
	T& operator*();
	void operator=(SmartPointer && other);
	T* operator->();
private:
	void CleanUp();
};

