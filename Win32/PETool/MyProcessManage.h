//程序线程处理
#ifndef __MYPROCESSMANAGE_H__
#define __MYPROCESSMANAGE_H__

#include "MyProcessManage.h"

//进程和模块显示的处理
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter);

//模块遍历的处理
DWORD WINAPI EnumModeThread(LPVOID lpParameter);
#endif

