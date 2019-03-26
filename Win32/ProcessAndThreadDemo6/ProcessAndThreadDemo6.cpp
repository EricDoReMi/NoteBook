// ProcessAndThreadDemo6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadProc1(LPVOID lpParameter)				
{				
	for(int i=0;i<5;i++)			
	{			
		printf("+++++++++\n");		
		Sleep(1000);		
	}			
	return 0;			
}				
				
DWORD WINAPI ThreadProc2(LPVOID lpParameter)				
{				
	for(int i=0;i<3;i++)			
	{			
		printf("---------\n");		
		Sleep(1000);		
	}			
				
	return 0;			
}				


int main(int argc, char* argv[])
{
	HANDLE hArray[2];			
			
	//创建一个新的线程			
	HANDLE hThread1 = ::CreateThread(NULL, 0, ThreadProc1, 			
		NULL, 0, NULL);		
				
	//创建一个新的线程			
	HANDLE hThread2 = ::CreateThread(NULL, 0, ThreadProc2, 			
		NULL, 0, NULL);		
				
	hArray[0] = hThread1;			
	hArray[1] = hThread2;			
				
	DWORD dwCode = ::WaitForMultipleObjects(2, hArray,FALSE,2);			
				
	::CloseHandle(hThread1);			
	::CloseHandle(hThread2);			
				
	MessageBox(0,0,0,0);			

	return 0;
}
