//�����̴߳���
#include "stdafx.h"

//���̺�ģ����ʾ�Ĵ���
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter){
	//��ʼ��
	//����ProcessListView�ķ��
	InitProcessListView(g_hwndDlg);

	//����ModuleListView�ķ��
	InitModuleListView(g_hwndDlg);
	
	return 0;

}

//ģ������Ĵ���
DWORD WINAPI EnumModeThread(LPVOID lpParameter){
	
	EnumModules(GetDlgItem(g_hwndDlg,IDC_LIST_PROCESS));

	return 0;

}