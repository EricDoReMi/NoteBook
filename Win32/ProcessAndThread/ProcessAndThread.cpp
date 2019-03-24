//进程和线程的说明
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter){
	int* pI=(int*)lpParameter;

	for(int i=0;i<1000;i++){
		Sleep(1000);
		printf("-----------%d--\n",*pI);
	
	}
	
	delete pI;
	return 0;

}	

void myTest(){

	int* pI=new int();
	*pI=5;
	HANDLE hThread = ::CreateThread(NULL, 0, ThreadProc,pI, 0, NULL);

					
	//如果不在其他的地方引用它 关闭句柄					
	::CloseHandle(hThread);					

}		
						


int main(int argc, char* argv[])
{
	myTest();

	for(int i=0;i<1000;i++){
		Sleep(1000);
		printf("+++++++++++\n");
	}

	return 0;
}
