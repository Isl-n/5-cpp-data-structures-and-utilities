#pragma once
#include "clsMyStack.h"

using namespace std;
class clsMyString
{
private:
	string _Value;
	clsMyStack<string> _MyStringMain;
	clsMyStack<string> _MyStringReserve;


public:
	clsMyString(string Value = "")
	{
		_Value = Value;
		_MyStringMain.push(_Value);
	}

	void SetValue(string Value)
	{
		_Value = Value;
		_MyStringMain.push(_Value);
	}

	string getValue()
	{
		return _Value;
	}

	void Undo()
	{ 
		_MyStringReserve.push( _MyStringMain.Top() );
		_MyStringMain.pop();

		_Value = _MyStringMain.Top();
	}

	void Redo()
	{
		_MyStringMain.push(_MyStringReserve.Top());
		_MyStringReserve.pop();

		_Value = _MyStringMain.Top();
	}

};

