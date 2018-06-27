// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifndef DLLHANDLER_C_
#define DLLHANDLER_C_

#include <windows.h>
#include <winbase.h>
#include <windef.h>
#include <stdio.h>

typedef int(*TestFunc)(int);

#endif

int main()
{
	int status = 0;
	TestFunc _TestFunc;
	HINSTANCE testLibrary = LoadLibrary(L"test.dll");

	if (testLibrary)
	{
		_TestFunc = (TestFunc)GetProcAddress(testLibrary, "Test");
		if (_TestFunc)
		{
			status = _TestFunc(0);
		}
		FreeLibrary(testLibrary);
	}
	return status;
}
