// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include<memory.h>
#include <windows.h>
#include<malloc.h>
#include <stdio.h>
#include "resource.h"
#include <CommDlg.h>
#include "Common.h"
#include "PEUtil.h"
#include <Tlhelp32.h>
#include <commctrl.h>				
#pragma comment(lib,"comctl32.lib")	
#include <richedit.h>	
#include "DebugTool.h"
#include "PETool.h"
#include "ProcessAndMode.h"
#include "MyProcessManage.h"
#include "PEView.h"


extern HINSTANCE hAppInstance;
extern HWND g_hwndDlg;//主窗口句柄
extern HWND g_PEDlg;//PE窗口句柄
extern HWND g_SECTIONDlg;//PESection窗口的句柄
extern HWND g_DICDlg;//PE目录表窗口的句柄
extern HWND g_DICDetailDlg;//PE目录表详情窗口的句柄
extern TCHAR szFileName[256];//PE文件的路径
extern LPVOID pFileBuffer;//PE文件的FileBuffer
extern int IDC_BUTTON_DIC_Index;//被点击了的目录详情的Button的ID
extern HWND hDicDetailEdit;//目录详情的RichEdit


// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
