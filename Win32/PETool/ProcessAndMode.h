#ifndef __PROCESSANDMODE_H__
#define __PROCESSANDMODE_H__

#include "ProcessAndMode.h"


//��ʼ�������б�
VOID InitProcessListView(HWND hDlg);

//��ʼ��ģ���б�
VOID InitModuleListView(HWND hDlg);

//��������
VOID EnumProcess(HWND hListProcess);

//����module
//hListProcess:ProcessListView�ľ��
VOID EnumModules(HWND hListProcess);

#endif