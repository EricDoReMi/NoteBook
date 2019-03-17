// FirstWin32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Tools.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	DWORD x = (DWORD)hInstance;
	DbgPrintf("Hello:%d,%d,%d\n",10,20,30);
	
	MessageBox((HWND)1,0,0,0);
	
	DWORD lastError=GetLastError();

	DbgPrintf("%d\n",lastError);

	return 0;
}



