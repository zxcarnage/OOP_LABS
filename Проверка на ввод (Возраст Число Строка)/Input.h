#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using std::exception;
using std::numeric_limits;
using std::streamsize;
using std::cout;
using std::cin;
using std::endl;
using std::string;

enum InputType
{
	Number,
	Age,
	Answer
};

class InputException : public exception
{
	float _errorData;
public:
	InputException(const char* msg) : exception(msg){}
	InputException(const char* msg, float errorData) : exception(msg)
	{
		_errorData = errorData;
	}
	float GetErrorData();
};

void StringInput(string* data, string dataName);
void CharInput(char data[], string dataName);

void Input(float* data, string dataName, InputType inputType);


