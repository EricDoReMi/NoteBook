//�����̴߳���
#ifndef __MYPROCESSMANAGE_H__
#define __MYPROCESSMANAGE_H__

#include "MyProcessManage.h"

//���̺�ģ����ʾ�Ĵ���
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter);

//ģ������Ĵ���
DWORD WINAPI EnumModeThread(LPVOID lpParameter);
#endif

