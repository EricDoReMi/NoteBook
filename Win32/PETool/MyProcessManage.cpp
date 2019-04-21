//程序线程处理
#include "StdAfx.h"

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

//PE文件查看处理
DWORD WINAPI PEViewThread(LPVOID lpParameter){
	
	ShowPEHead();

	return 0;

}

//读取PE文件内容的线程
DWORD WINAPI PEReadThread(LPVOID lpParameter){
	
	ReadPEHead();

	return 0;

}


//获取PE节表对话框的线程
DWORD WINAPI PESectionThread(LPVOID lpParameter){
	
	//展示PESections信息
	ShowPESections();

	InitSectionListView(g_hwndDlg);

	return 0;

}

//读取PE节表信息的线程
DWORD WINAPI PESectionReadThread(LPVOID lpParameter){
	
	
	InitSectionListView(g_SECTIONDlg);

	return 0;

}


//获取PE目录表对话框的线程
DWORD WINAPI PEDicThread(LPVOID lpParameter){
	
	//展示PEDic信息
	ShowPEDic();


	return 0;

}


//读取PE目录表信息的线程
DWORD WINAPI PEDicReadThread(LPVOID lpParameter){
	
	InitPEDicView(g_DICDlg);

	return 0;

}