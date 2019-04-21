#ifndef __PEVIEW_H__
#define __PEVIEW_H__

#include "PEView.h"

//展示PE头信息
void ShowPEHead();

//读取PE头信息
void ReadPEHead();

//展示PESections信息
void ShowPESections();

//初始化Section列表
VOID InitSectionListView(HWND hDlg);

//遍历Section
VOID EnumPESections(HWND hListProcess);

//初始化Dic列表
VOID InitPEDIcView(HWND hDlg);

//展示PEDic信息
void ShowPEDic();

//初始化Dic列表
VOID InitPEDicView(HWND hDlg);

#endif