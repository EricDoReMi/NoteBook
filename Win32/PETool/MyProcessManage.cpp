//程序线程处理
#include "stdafx.h"

//进程和模块显示的处理
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter){
	//初始化
	//设置ProcessListView的风格
	InitProcessListView(g_hwndDlg);

	//设置ModuleListView的风格
	InitModuleListView(g_hwndDlg);
	
	return 0;

}

//模块遍历的处理
DWORD WINAPI EnumModeThread(LPVOID lpParameter){
	
	EnumModules(GetDlgItem(g_hwndDlg,IDC_LIST_PROCESS));

	return 0;

}