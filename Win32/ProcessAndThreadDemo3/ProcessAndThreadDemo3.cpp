// ProcessAndThreadDemo3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

CRITICAL_SECTION cs;

DWORD WINAPI ThreadProc1(LPVOID lpParameter)						
{						
	for(int x=0;x<1000;x++)					
	{					
		 EnterCriticalSection(&cs);				
		  				
		  Sleep(1000);				
						
		  printf("11111:%x %x %x\n",cs.LockCount,cs.RecursionCount,cs.OwningThread);				
		  				
		  LeaveCriticalSection(&cs);				
						
	}					
	return 0;					
}						
						
DWORD WINAPI ThreadProc2(LPVOID lpParameter)						
{						
	for(int x=0;x<1000;x++)					
	{					
		EnterCriticalSection(&cs);				
						
		Sleep(1000);				
						
		printf("22222:%x %x %x\n",cs.LockCount,cs.RecursionCount,cs.OwningThread);				
						
		LeaveCriticalSection(&cs);				
						
	}					
						
	return 0;					
}						
						
DWORD WINAPI ThreadProc3(LPVOID lpParameter)						
{						
	for(int x=0;x<1000;x++)					
	{					
		EnterCriticalSection(&cs);				
						
		Sleep(1000);				
						
		printf("33333:%x %x %x\n",cs.LockCount,cs.RecursionCount,cs.OwningThread);				
						
		LeaveCriticalSection(&cs);				
						
	}					
						
	return 0;					
}						
						
DWORD WINAPI ThreadProc4(LPVOID lpParameter)						
{						
	for(int x=0;x<1000;x++)					
	{					
		EnterCriticalSection(&cs);				
						
		Sleep(1000);				
						
		printf("44444:%x %x %x\n",cs.LockCount,cs.RecursionCount,cs.OwningThread);				
						
		LeaveCriticalSection(&cs);				
						
	}					
						
	return 0;					
}						
						
						
int main(int argc, char* argv[])
{
	
	InitializeCriticalSection(&cs);					
						
	//printf("主线程:%x %x %x\n",cs.LockCount,cs.RecursionCount,cs.OwningThread);					
						
	//创建一个新的线程					
	HANDLE hThread1 = ::CreateThread(NULL, 0, ThreadProc1, 					
		NULL, 0, NULL);				
						
	//创建一个新的线程					
	HANDLE hThread2 = ::CreateThread(NULL, 0, ThreadProc2, 					
		NULL, 0, NULL);				
						
	//创建一个新的线程					
	HANDLE hThread3 = ::CreateThread(NULL, 0, ThreadProc3, 					
		NULL, 0, NULL);				
						
	//创建一个新的线程					
	HANDLE hThread4 = ::CreateThread(NULL, 0, ThreadProc4, 					
		NULL, 0, NULL);				
						
	//如果不在其他的地方引用它 关闭句柄					
	::CloseHandle(hThread1);					
	::CloseHandle(hThread2);					
	::CloseHandle(hThread3);					
	::CloseHandle(hThread4);
						
	Sleep(1000*60*60);					
						
	return 0;					

}
