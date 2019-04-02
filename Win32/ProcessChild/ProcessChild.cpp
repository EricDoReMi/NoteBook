// ProcessChild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char szBuffer[256] = {0};			
	char szHandle[8] = {0};			
				
	SECURITY_ATTRIBUTES ie_sa_p;			
	ie_sa_p.nLength = sizeof(ie_sa_p);			
	ie_sa_p.lpSecurityDescriptor = NULL;			
	ie_sa_p.bInheritHandle = TRUE; 			
				
	SECURITY_ATTRIBUTES ie_sa_t;			
	ie_sa_t.nLength = sizeof(ie_sa_t);			
	ie_sa_t.lpSecurityDescriptor = NULL;			
	ie_sa_t.bInheritHandle = TRUE; 			
	//创建一个可以被继承的内核对象,此处是个进程			
	STARTUPINFO ie_si = {0};   			
	PROCESS_INFORMATION ie_pi;			
	ie_si.cb = sizeof(ie_si);			
				
	TCHAR szCmdline[] =TEXT("c://program files//internet explorer//iexplore.exe");			
	CreateProcess(			
		NULL, 		
		szCmdline, 		
		&ie_sa_p, 		
		&ie_sa_t, 		
		FALSE, 		
		CREATE_NEW_CONSOLE, 		
		NULL, 		
		NULL, &ie_si, &ie_pi); 		
				
	//组织命令行参数			
	sprintf(szHandle,"%x %x",ie_pi.hProcess,ie_pi.hThread);			
	sprintf(szBuffer,"C:/ProcessChildChild.exe %s",szHandle);			
				
	//定义创建进程需要用的结构体			
	STARTUPINFO si = {0};   			
	PROCESS_INFORMATION pi;			
	si.cb = sizeof(si);			
				
	//创建子进程			
	BOOL res = CreateProcess(			
		NULL, 		
		szBuffer, 		
		NULL, 		
		NULL, 		
		TRUE, 		
		CREATE_NEW_CONSOLE, 		
		NULL, 		
		NULL, &si, &pi); 		

	return 0;
}


