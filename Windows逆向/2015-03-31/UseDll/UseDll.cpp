// UseDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

//#pragma comment(lib,"InjectDll.lib")
//extern "C" __declspec(dllimport) void ExportFunction();  
//ExportFunction();
int main(int argc, char* argv[])
{
	typedef void ( *lpTest)();

	lpTest MyFunction;
	//����DLL
	HINSTANCE   hModule = LoadLibrary("InjectDll.dll"); 

	//��ȡ������ַ
	MyFunction = (lpTest)GetProcAddress(hModule,"ExportFunction");

	//���ú���
	MyFunction();

	//�ͷ�DLL
	FreeLibrary(hModule);
	
	
	return 0;
}

