#include "Input.h"

void AgeInput(float tempData, string dataName)
{
	if (tempData < 0 || tempData > 120)
		throw InputException("Incorrect age amount", tempData);
}

void NumberInput(float tempData, string dataName)
{
	if (tempData < 0 || tempData > INT_MAX)
		throw InputException("Incorrect data", tempData);
}

void AnswerInput(float tempData, string dataName)
{
	if ((int)tempData != tempData)
		throw InputException("Incorrect type of answer, try int num", tempData);
}

void Input(float* data, string dataName, InputType inputType)
{
	float tempData;
	cout << "Enter " << dataName << endl;
	cin >> tempData;
	if (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw exception("Incorrect data type input!");
	}
	switch (inputType)
	{
	case Number:
		NumberInput(tempData, dataName);
		*data = tempData;
		break;
	case Age:
		AgeInput(tempData, dataName);
		*data = tempData;
		break;
	case Answer:
		AnswerInput(tempData, dataName);
		*data = tempData;
		break;
	default:
		throw exception("Incorrect InputType!!!");
		break;
	}
}

void CharInput(char data[], string dataName)
{
	char tempData[20];
	cout << "Enter " << dataName << endl;
	memset(tempData, 0, sizeof tempData);
	memset(data, 0, sizeof data);
	cin.get();
	cin.getline(tempData, 20);
	strcpy(data,tempData);
}

void StringInput(string* data, string dataName)
{
	string tempData;
	cout << "Enter " << dataName << endl;
	cin >> tempData;
	*data = tempData;
}

float InputException::GetErrorData()
{
	return _errorData;
}