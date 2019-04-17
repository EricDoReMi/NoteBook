// dllmain.cpp : 定义 DLL 应用程序的入口点。
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

        //这里填写要load的DLL
        g_hModule = LoadLibrary(_T("D:\\MyDll\\ImeInject\\Debug\\MfcImeInjectDll.dll"));
        
        if (!g_hModule)
        {
            MessageBox(NULL,_T("模块没有load成功"),_T("提示"),MB_OK);
        }
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        ImeClass_Unregister(hinstDLL);  // DLL退出时注销注册的窗口类
        if (!g_hModule)
        {
            FreeLibrary(g_hModule);    // 输入法退出时卸载客户DLL
        }
        break;
    default:
        break;
    }
    return true;
}

//将字符串或字符转换成目标字串
DWORD WINAPI ImeConversionList(HIMC hIMC,LPCTSTR lpSource,LPCANDIDATELIST lpCandList,DWORD dwBufLen,UINT uFlag)
{
    return 0;
}

//配置当前ime参数函数
//设置输入法状态函数，如光标跟随等
BOOL WINAPI ImeConfigure(HKL hKL,HWND hWnd, DWORD dwMode, LPVOID lpData)
{
    return FALSE;
}

//退出当前使用的IME
BOOL WINAPI ImeDestroy(UINT uForce)
{
    return FALSE;
}

//应用软件访问输入法的接口函数
LRESULT WINAPI ImeEscape(HIMC hIMC,UINT uSubFunc,LPVOID lpData)
{
    return 0;
}

//启动并初始化当前ime输入法
BOOL WINAPI ImeInquire(LPIMEINFO lpIMEInfo,LPTSTR lpszUIClass,LPCTSTR lpszOption)
{
    //输入法初始化过程
    //系统根据它为INPUTCONTEXT.hPrivate分配空间
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

    // 注意该输入法基本窗口类必须注册，否则输入法不能正常运行
    _tcscpy(lpszUIClass,CLSNAME_UI);
    return TRUE;
}

//ime输入键盘事件管理函数
BOOL WINAPI ImeProcessKey(HIMC hIMC,UINT uKey,LPARAM lKeyData,CONST LPBYTE lpbKeyState)
{
    return FALSE;
}

//启动当前的ime输入法
BOOL WINAPI ImeSelect(HIMC hIMC,BOOL fSelect)
{
    return FALSE;
}

//设置当前的输入处于活动状态
BOOL WINAPI ImeSetActiveContext(HIMC hIMC,BOOL fFlag)
{
    return TRUE;
}

//由应用程序设置输入法编码
BOOL WINAPI ImeSetCompositionString(HIMC hIMC, DWORD dwIndex, LPCVOID lpComp, DWORD dwComp, LPCVOID lpRead, DWORD dwRead)
{
    return FALSE;
}

//将输入的键盘事件转换为汉字编码事件
UINT WINAPI ImeToAsciiEx (UINT uVKey,UINT uScanCode,CONST LPBYTE lpbKeyState,LPDWORD lpdwTransKey,UINT fuState,HIMC hIMC)
{
    return 0;
}

//ime事件管理函数
BOOL WINAPI NotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue)
{
    return FALSE;
}

//向输入法字典注册字符串
BOOL WINAPI ImeRegisterWord(LPCTSTR lpszReading,DWORD   dwStyle,LPCTSTR lpszString)
{
    return 0;
}

//删除被注册的字符串
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

//用户界面接口函数
LRESULT WINAPI UIWndProc(HWND hUIWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//状态窗口注册函数
LRESULT WINAPI StatusWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//输入编码窗口注册函数
LRESULT WINAPI CompWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}

//选择汉字窗口注册函数
LRESULT WINAPI CandWndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    return 0;
}