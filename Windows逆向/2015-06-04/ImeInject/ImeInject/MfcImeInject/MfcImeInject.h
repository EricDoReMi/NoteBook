// MfcImeInject.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMfcImeInjectApp:
// �йش����ʵ�֣������ MfcImeInject.cpp
//

class CMfcImeInjectApp : public CWinApp
{
public:
	CMfcImeInjectApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMfcImeInjectApp theApp;