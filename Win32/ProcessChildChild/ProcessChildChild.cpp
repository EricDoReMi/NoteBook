// ProcessChildChild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	DWORD dwProcessHandle = -1;						
	DWORD dwThreadHandle = -1;						
	char szBuffer[256] = {0};						
							
							
	memcpy(szBuffer,argv[1],8);						
	sscanf(szBuffer,"%x",&dwProcessHandle);						
							
	memset(szBuffer,0,256);						
	memcpy(szBuffer,argv[2],8);						
	sscanf(szBuffer,"%x",&dwThreadHandle);						
							
	printf("��ȡIE���̡����߳̾��\n");						
	Sleep(10000);						
	//�������߳�						
	printf("�������߳�\n");						
	::SuspendThread((HANDLE)dwThreadHandle);						
							
	Sleep(10000);						
							
	//�ָ����߳�						
	::ResumeThread((HANDLE)dwThreadHandle);						
	printf("�ָ����߳�\n");						
							
	Sleep(10000);						
							
	//�ر�ID����						
	::TerminateProcess((HANDLE)dwProcessHandle,1);						
	::WaitForSingleObject((HANDLE)dwProcessHandle, INFINITE);						
							
	printf("ID�����Ѿ��ر�.....\n");						
						

	return 0;
}

