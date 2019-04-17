// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#define  NOIME
#include "stdafx.h"
#include "tchar.h"
#include "IMM.H"

HMODULE g_hModule = NULL;
#define CLSNAME_UI _T("DLLCLASSNAME")
LRESULT WINAPI UIWndProc(HWND hUIWnd,UINT message,WPARAM wParam,LPARAM lParam);

BOOL ImeClass_Register(HINSTANCE hInstance)
{
    WNDCLASSEX wc;
    wc.cbSize         = sizeof(WNDCLASSEX);
    wc.style          = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS | CS_IME;
    wc.lpfnWndProc    = UIWndProc;
    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 2 * sizeof(LONG);
    wc.hInstance      = hInstance;
    wc.hCursor        = LoadCursor( NULL, IDC_ARROW );
    wc.hIcon          = NULL;
    wc.lpszMenuName   = (LPTSTR)NULL;
    wc.lpszClassName  = CLSNAME_UI;
    wc.hbrBackground  = NULL;
    wc.hIconSm        = NULL;

    if( !RegisterClassEx( (LPWNDCLASSEX)&wc ) )
        return FALSE;

    return TRUE;
}

void ImeClass_Unregister(HINSTANCE hInstance)
{
    UnregisterClass(CLSNAME_UI,hInstance);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        if(!ImeClass_Register(hinstDLL)) return FALSE;

        //������дҪload��DLL
        g_hModule = LoadLibrary(_T("D:\\MyDll\\ImeInject\\Debug\\MfcImeInjectDll.dll"));
        
        if (!g_hModule)
        {
            MessageBox(NULL,_T("ģ��û��load�ɹ�"),_T("��ʾ"),MB_OK);
        }
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        ImeClass_Unregister(hinstDLL);  // DLL�˳�ʱע��ע��Ĵ�����
        if (!g_hModule)
        {
            FreeLibrary(g_hModule);    // ���뷨�˳�ʱж�ؿͻ�DLL
        }
        break;
    default:
        break;
    }
    return true;
}

//���ַ������ַ�ת����Ŀ���ִ�
DWORD WINAPI ImeConversionList(HIMC hIMC,LPCTSTR lpSource,LPCANDIDATELIST lpCandList,DWORD dwBufLen,UINT uFlag)
{
    return 0;
}

//���õ�ǰime��������
//�������뷨״̬��������������
BOOL WINAPI ImeConfigure(HKL hKL,HWND hWnd, DWORD dwMode, LPVOID lpData)
{
    return FALSE;
}

//�˳���ǰʹ�õ�IME
BOOL WINAPI ImeDestroy(UINT uForce)
{
    return FALSE;
}

//Ӧ������������뷨�Ľӿں���
LRESULT WINAPI ImeEscape(HIMC hIMC,UINT uSubFunc,LPVOID lpData)
{
    return 0;
}

//��������ʼ����ǰime���뷨
BOOL WINAPI ImeInquire(LPIMEINFO lpIMEInfo,LPTSTR lpszUIClass,LPCTSTR lpszOption)
{
    //���뷨��ʼ������
    //ϵͳ������ΪINPUTCONTEXT.hPrivate����ռ�
    lpIMEInfo->dwPrivateDataSize = 0; 

    lpIMEInfo->fdwProperty = IME_PROP_KBD_CHAR_FIRST |
        IME_PROP_IGNORE_UPKEYS |
        IME_PROP_END_UNLOAD; 

    lpIMEInfo->fdwConversionCaps = IME_CMODE_FULLSHAPE |
        IME_CMODE_NATIVE;

    lpIMEInfo->fdwSentenceCaps = IME_SMODE_NONE;
    lpIMEInfo->fdwUICaps = UI_CAP_2700;

    lpIMEInfo->fdwSCSCaps = 0;

    lpIMEInfo->fdwSelectCaps = SELECT_CAP_CONVERSION;

    // ע������뷨�������������ע�ᣬ�������뷨������������
    _tcscpy(lpszUIClass,CLSNAME_UI);
    return TRUE;
}

//ime��������¼�������
BOOL WINAPI ImeProcessKey(HIMC hIMC,UINT uKey,LPARAM lKeyData,CONST LPBYTE lpbKeyState)
{
    return FALSE;
}

//������ǰ��ime���뷨
BOOL WINAPI ImeSelect(HIMC hIMC,BOOL fSelect)
{
    return FALSE;
}

//���õ�ǰ�����봦�ڻ״̬
BOOL WINAPI ImeSetActiveContext(HIMC hIMC,BOOL fFlag)
{
    return TRUE;
}

//��Ӧ�ó����������뷨����
BOOL WINAPI ImeSetCompositionString(HIMC hIMC, DWORD dwIndex, LPCVOID lpComp, DWORD dwComp, LPCVOID lpRead, DWORD dwRead)
{
    return FALSE;
}

//������ļ����¼�ת��Ϊ���ֱ����¼�
UINT WINAPI ImeToAsciiEx (UINT uVKey,UINT uScanCode,CONST LPBYTE lpbKeyState,LPDWORD lpdwTransKey,UINT fuState,HIMC hIMC)
{
    return 0;
}

//ime�¼�������
BOOL WINAPI NotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue)
{
    return FALSE;
}

//�����뷨�ֵ�ע���ַ���
BOOL WINAPI ImeRegisterWord(LPCTSTR lpszReading,DWORD   dwStyle,LPCTSTR lpszString)
{
    return 0;
}

//ɾ����ע����ַ���
BOOL WINAPI ImeUnregisterWord(LPCTSTR lpszReading,DWORD dwStyle,LPCTSTR lpszString)
{
    return FALSE;
}

UINT WINAPI ImeGetRegisterWordStyle(UINT nItem,LPSTYLEBUF lpStyleBuf)
{
    return 0;
}

UINT WINAPI ImeEnumRegisterWord(REGISTERWORDENUMPROC lpfnRegisterWordEnumProc,LPCTSTR lpszReading,DWORD dwStyle,LPCTSTR lpszString,LPVOID lpData)
{
    return 0;
}

//�û�����ӿں���
LRESULT WINAPI UIWndProc(HWND hUIWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//״̬����ע�ắ��
LRESULT WINAPI StatusWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//������봰��ע�ắ��
LRESULT WINAPI CompWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//ѡ���ִ���ע�ắ��
LRESULT WINAPI CandWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}