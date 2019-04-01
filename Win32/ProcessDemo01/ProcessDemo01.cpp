// ProcessDemo01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

VOID TestCreateProcessByAPPName()						
{						
	STARTUPINFO si = {0};   					
    	PROCESS_INFORMATION pi;					
						
	si.cb = sizeof(si);					
						
	TCHAR szApplicationName[] =TEXT("c://program files//internet explorer//iexplore.exe");					
						
	BOOL res = CreateProcess(					
		szApplicationName, 				
		NULL, 				
		NULL, 				
		NULL, 				
		FALSE, 				
		CREATE_NEW_CONSOLE, 				
		NULL, 				
		NULL, &si, &pi); 				
   						
}						
VOID TestCreateProcessByCmdline()						
{						
	STARTUPINFO si = {0};   					
    	PROCESS_INFORMATION pi;					
						
	si.cb = sizeof(si);					
						
	TCHAR szCmdline[] =TEXT("c://program files//internet explorer//iexplore.exe http://www.ifeng.com");					
						
	BOOL res = CreateProcess(					
		NULL, 				
		szCmdline, 				
		NULL, 				
		NULL, 				
		FALSE, 				
		CREATE_NEW_CONSOLE, 				
		NULL, 				
		NULL, &si, &pi); 				
}						
VOID TestCreateProcess()						
{						
	STARTUPINFO si = {0};   					
    	PROCESS_INFORMATION pi;					
						
	si.cb = sizeof(si);					
						
	TCHAR szCmdline[] =TEXT(" http://www.ifeng.com");					
						
	BOOL res = CreateProcess(					
		TEXT("c://program files//internet explorer//iexplore.exe"), 				
		szCmdline, 				
		NULL, 				
		NULL, 				
		FALSE, 				
		CREATE_NEW_CONSOLE, 				
		NULL, 				
		NULL, &si, &pi); 				
}						


int main(int argc, char* argv[])
{
	TestCreateProcessByAPPName();
	return 0;
}

