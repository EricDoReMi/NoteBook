//通用的函数
#include "StdAfx.h"

//从路径获取文件名
//filePath 文件名完整的路径
char* getFileNameFromPath(char* filePath){
	char splitChar='\\';
	char* pFileName=strrchr(filePath,splitChar)+1;
	return pFileName;
}

//richEdit的常用处理

//根据窗口大小，调整richEdit的大小
void AdjustEditWindow(HWND hwndMain,HWND hwndEdit)
{
		RECT rectMain;
		RECT rectEdit;
		GetClientRect(hwndMain,&rectMain);
		GetWindowRect(hwndEdit,&rectEdit);


		int xPos = 0;
		int xLen = rectMain.right - rectMain.left - 2;
		int yPos = 0;
		int yLen = (rectMain.bottom - rectMain.top);


		MoveWindow(hwndEdit,xPos,yPos,xLen,yLen,TRUE);
}
