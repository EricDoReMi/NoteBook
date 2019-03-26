// ProcessAndThreadDemo5.cpp : Defines the entry point for the console application.
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


int main(int argc, char* argv[])
{
	//创建一个新的线程						
	HANDLE hThread1 = ::CreateThread(NULL, 0, ThreadProc1, 						
		NULL, 0, NULL);					
							
	DWORD dwCode = ::WaitForSingleObject(hThread1, 1);

	CloseHandle(hThread1);
	
	if(dwCode==WAIT_OBJECT_0){
		MessageBox(0,TEXT("已通知"),0,0);							
	}
	
	if(dwCode==WAIT_TIMEOUT){
		MessageBox(0,TEXT("超时"),0,0);							
	}
							
	
						

	return 0;
}
