// SUSPENDEDDemo01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	STARTUPINFO ie_si = {0};   										
	PROCESS_INFORMATION ie_pi;										
	ie_si.cb = sizeof(ie_si);										
										
//�Թ���ķ�ʽ��������										
	TCHAR szBuffer[256] = "c://GetCurrentProcessChild.exe";										
	CreateProcess(										
		NULL,                    // name of executable module									
		szBuffer,                // command line string									
		NULL, 					 // SD				
		NULL,  		             // SD							
		FALSE,                   // handle inheritance option									
		CREATE_SUSPENDED,     	 // creation flags  								
		NULL,                    // new environment block									
		NULL,                    // current directory name									
		&ie_si,                  // startup information									
		&ie_pi                   // process information									
		);									
											
										
	CONTEXT contx;  										
	contx.ContextFlags = CONTEXT_FULL;  										
											
											
	GetThreadContext(ie_pi.hThread, &contx);										
											
	//��ȡ��ڵ�ImageBase+OEP								
	DWORD dwEntryPoint = contx.Eax;										
											
	//��ȡImageBase										
	char* baseAddress =(CHAR*)contx.Ebx+8;					//���ImageBase�ĵ�ַ�������ַ���ӽ��̵�һ����ַ�������ַ�洢��ֵ�����ӽ��̵�ImageBase					
											
	memset(szBuffer,0,256);
											
	ReadProcessMemory(ie_pi.hProcess,baseAddress,szBuffer,4,NULL);							//��ȡ��һ�����̵��ڴ棬���������̾���ˣ�Ҫ��ȡ�ĵ�ַ����ȡ�����ݴ��������������ٸ��ֽڣ��������˶��ٸ��ֽڣ���������ˣ�			

	printf("entry:%x,imageBase:%x\n",dwEntryPoint,*(PDWORD)szBuffer);
																					
	ResumeThread(ie_pi.hThread);								  		
	
	getchar();
	return 0;
}

