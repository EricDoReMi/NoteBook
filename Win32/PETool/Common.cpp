//ͨ�õĺ���
#include "StdAfx.h"

//��·����ȡ�ļ���
//filePath �ļ���������·��
char* getFileNameFromPath(char* filePath){
	char splitChar='\\';
	char* pFileName=strrchr(filePath,splitChar)+1;
	return pFileName;
}

//richEdit�ĳ��ô���

//���ݴ��ڴ�С������richEdit�Ĵ�С
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
