#ifndef __COMMONERIC_H__
#define __COMMONERIC_H__
#include "Common.h"

//��·����ȡ�ļ���
//filePath �ļ���������·��
char* getFileNameFromPath(char* filePath);


//���Ŀ¼���Ƿ����
bool checkDicTableExist();

//��richEdit����д������
void appendRichEdit(HWND hRichEdit,TCHAR* szBuffer,DWORD sizeOfSzBuffer);

#endif
