//�����̴߳���
#ifndef __MYPROCESSMANAGE_H__
#define __MYPROCESSMANAGE_H__

#include "MyProcessManage.h"

//���̺�ģ����ʾ�Ĵ���
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter);

//ģ������Ĵ���
DWORD WINAPI EnumModeThread(LPVOID lpParameter);

//PE�ļ��鿴����
DWORD WINAPI PEViewThread(LPVOID lpParameter);

//��ȡPE�ļ����ݵ��߳�
DWORD WINAPI PEReadThread(LPVOID lpParameter);

//��ȡPE�ڱ�Ի�����߳�
DWORD WINAPI PESectionThread(LPVOID lpParameter);

//��ȡPE�ڱ���Ϣ���߳�
DWORD WINAPI PESectionReadThread(LPVOID lpParameter);

#endif

