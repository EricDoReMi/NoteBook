// 线程死锁问题
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

CRITICAL_SECTION cs;		
CRITICAL_SECTION g_cs;		


DWORD WINAPI ThreadA(PVOID pvParam) 				
	{				
	      EnterCriticalSection(&cs);			
			Sleep(1000);
			printf("ThreadA------\n");
		  EnterCriticalSection(&g_cs);
	
		  LeaveCriticalSection(&g_cs);
		  
	      LeaveCriticalSection(&cs);			
	   return(0);				
	}				
					
					
DWORD WINAPI ThreadB(PVOID pvParam) 				
	{				
	      EnterCriticalSection(&g_cs);	
			Sleep(1000);
			printf("ThreadB------\n");
			EnterCriticalSection(&cs);
			
			LeaveCriticalSection(&cs);
					
	      LeaveCriticalSection(&g_cs);				
	   return(0);				
	}				


int main(int argc, char* argv[])
{
	InitializeCriticalSection(&cs);
	InitializeCriticalSection(&g_cs);
	
	HANDLE hThread1 = ::CreateThread(NULL, 0, ThreadA,NULL, 0, NULL);				
					
				
	HANDLE hThread2 = ::CreateThread(NULL, 0, ThreadB,NULL, 0, NULL);				

	
	::CloseHandle(hThread1);					
	::CloseHandle(hThread2);
	
	 EnterCriticalSection(&cs);
		Sleep(1000);		
	 LeaveCriticalSection(&cs);
	return 0;
}
