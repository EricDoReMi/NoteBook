// MfcImeInjectDll.h : MfcImeInjectDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMfcImeInjectDllApp
// �йش���ʵ�ֵ���Ϣ������� MfcImeInjectDll.cpp
//

class CMfcImeInjectDllApp : public CWinApp
{
public:
	CMfcImeInjectDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
