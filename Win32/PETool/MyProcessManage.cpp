//�����̴߳���
#include "StdAfx.h"

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

//PE�ļ��鿴����
DWORD WINAPI PEViewThread(LPVOID lpParameter){
	
	ShowPEHead();

	return 0;

}

//��ȡPE�ļ����ݵ��߳�
DWORD WINAPI PEReadThread(LPVOID lpParameter){
	
	ReadPEHead();

	return 0;

}