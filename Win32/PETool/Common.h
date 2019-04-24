#ifndef __COMMONERIC_H__
#define __COMMONERIC_H__
#include "Common.h"

//从路径获取文件名
//filePath 文件名完整的路径
char* getFileNameFromPath(char* filePath);


//检查目录表是否存在
bool checkDicTableExist();

//向richEdit增加写入内容
void appendRichEdit(HWND hRichEdit,TCHAR* szBuffer,DWORD sizeOfSzBuffer);

#endif
