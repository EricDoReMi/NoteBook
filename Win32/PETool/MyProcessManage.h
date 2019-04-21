//程序线程处理
#ifndef __MYPROCESSMANAGE_H__
#define __MYPROCESSMANAGE_H__

#include "MyProcessManage.h"

//进程和模块显示的处理
DWORD WINAPI ProcessAndModeThread(LPVOID lpParameter);

//模块遍历的处理
DWORD WINAPI EnumModeThread(LPVOID lpParameter);

//PE文件查看处理
DWORD WINAPI PEViewThread(LPVOID lpParameter);

//读取PE文件内容的线程
DWORD WINAPI PEReadThread(LPVOID lpParameter);

//获取PE节表对话框的线程
DWORD WINAPI PESectionThread(LPVOID lpParameter);

//读取PE节表信息的线程
DWORD WINAPI PESectionReadThread(LPVOID lpParameter);

#endif

