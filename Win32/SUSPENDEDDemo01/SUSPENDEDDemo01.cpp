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
										
//以挂起的方式创建进程										
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
											
	//获取入口点ImageBase+OEP								
	DWORD dwEntryPoint = contx.Eax;										
											
	//获取ImageBase										
	char* baseAddress =(CHAR*)contx.Ebx+8;					//获得ImageBase的地址，这个地址是子进程的一个地址，这个地址存储的值就是子进程的ImageBase					
											
	memset(szBuffer,0,256);
											
	ReadProcessMemory(ie_pi.hProcess,baseAddress,szBuffer,4,NULL);							//读取另一个进程的内存，参数，进程句柄了，要读取的地址，读取的内容存在哪里，打算读多少个字节，真正读了多少个字节（输出参数了）			

	printf("entry:%x,imageBase:%x\n",dwEntryPoint,*(PDWORD)szBuffer);
																					
	ResumeThread(ie_pi.hThread);								  		
	
	getchar();
	return 0;
}

