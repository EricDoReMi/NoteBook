// MfcImeInjectDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MfcImeInjectDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CMfcImeInjectDllApp

BEGIN_MESSAGE_MAP(CMfcImeInjectDllApp, CWinApp)
END_MESSAGE_MAP()


// CMfcImeInjectDllApp ����

CMfcImeInjectDllApp::CMfcImeInjectDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMfcImeInjectDllApp ����

CMfcImeInjectDllApp theApp;


// CMfcImeInjectDllApp ��ʼ��

BOOL CMfcImeInjectDllApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}
