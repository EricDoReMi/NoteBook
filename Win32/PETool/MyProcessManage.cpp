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