#ifndef __PROCESSANDMODE_H__
#define __PROCESSANDMODE_H__

#include "ProcessAndMode.h"



//��������
VOID EnumProcess(HWND hListProcess);

//����module
//hListProcess:ProcessListView�ľ��
VOID EnumModules(HWND hListProcess,WPARAM wparam,LPARAM lparam);

//��ʼ�������б�
VOID InitProcessListView(HWND hDlg);

//��ʼ��ģ���б�
VOID InitModuleListView(HWND hDlg);

#endif