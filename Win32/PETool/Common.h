#ifndef __COMMONERIC_H__
#define __COMMONERIC_H__
#include "Common.h"

//从路径获取文件名
//filePath 文件名完整的路径
char* getFileNameFromPath(char* filePath);

//根据窗口大小，调整richEdit的大小
void AdjustEditWindow(HWND hwndMain,HWND hwndEdit);

#endif
