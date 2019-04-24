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

//展示PEDic信息
void ShowPEDic();

//初始化Dic列表
VOID InitPEDicView(HWND hDlg);

//按照目录表点击的.....按钮来显示目录详情对话框
void AlertDicDetail();

//打开目录详情对话框
void ShowDicDetail();

//初始化PE的目录详情
void InitPEDicDetailView(HWND hDlg);


//=================打印目录表详情===================
//打印导出表
VOID PrintExportTable(HWND hRichEdit);


//打印导入表
VOID PrintImportTable(HWND hRichEdit);

//打印重定位表
VOID PrintRelocationTable(HWND hRichEdit);

//打印绑定导入表
/*VOID PrintBoundImportTable(LPVOID pFileBuffer);

//打印资源表
VOID PrintResourceTable(LPVOID pFileBuffer);

//递归打印资源表的函数
//TableAddr:资源表表头的位置
//pResourceDir
//index:层数
VOID printResource(LPVOID pFileBuffer,DWORD TableAddr,PIMAGE_RESOURCE_DIRECTORY pResourceDir,int index);

//打印names
//index 层数
//names
VOID printIndexTitle(int index,WCHAR* names);

//打印names
//index 层数
//names
VOID printIndexTitle(int index,CHAR* names);

//打印ID
//index 层数
//id
VOID printIndexID(int index,DWORD id);*/

#endif