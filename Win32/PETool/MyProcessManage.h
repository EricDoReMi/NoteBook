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

//获取PE目录表对话框的线程
DWORD WINAPI PEDicThread(LPVOID lpParameter);

//读取PE目录表信息的线程
DWORD WINAPI PEDicReadThread(LPVOID lpParameter);

//获取PE目录详情表对话框的线程
DWORD WINAPI PEDicDetailThread(LPVOID lpParameter);

//读取PE目录表详细信息的线程
DWORD WINAPI PEDicDetailReadThread(LPVOID lpParameter);

#endif

