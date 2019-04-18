#ifndef __PROCESSANDMODE_H__
#define __PROCESSANDMODE_H__

#include "ProcessAndMode.h"


//初始化进程列表
VOID InitProcessListView(HWND hDlg);

//初始化模块列表
VOID InitModuleListView(HWND hDlg);

//遍历进程
VOID EnumProcess(HWND hListProcess);

//遍历module
//hListProcess:ProcessListView的句柄
VOID EnumModules(HWND hListProcess);

#endif