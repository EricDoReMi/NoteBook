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


//��ȡPE�ڱ�Ի�����߳�
DWORD WINAPI PESectionThread(LPVOID lpParameter){
	
	//չʾPESections��Ϣ
	ShowPESections();

	InitSectionListView(g_hwndDlg);

	return 0;

}

//��ȡPE�ڱ���Ϣ���߳�
DWORD WINAPI PESectionReadThread(LPVOID lpParameter){
	
	
	InitSectionListView(g_SECTIONDlg);

	return 0;

}


//��ȡPEĿ¼��Ի�����߳�
DWORD WINAPI PEDicThread(LPVOID lpParameter){
	
	//չʾPEDic��Ϣ
	ShowPEDic();


	return 0;

}


//��ȡPEĿ¼����Ϣ���߳�
DWORD WINAPI PEDicReadThread(LPVOID lpParameter){
	
	InitPEDicView(g_DICDlg);

	return 0;

}