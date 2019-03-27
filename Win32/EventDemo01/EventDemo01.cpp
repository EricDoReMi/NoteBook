// Edit1变为1000后，Edit2，Edit3，Edit4分别依次读取该值
//

#include "stdafx.h"

HINSTANCE hAppInstance=NULL;
HWND hEdit1=NULL;
HWND hEdit2=NULL;
HWND hEdit3=NULL;
HWND hEdit4=NULL;
HANDLE hThread1;		
HANDLE hThread2;		
HANDLE hThread3;		
HANDLE hThread4;
		
HANDLE g_hEvent;

DWORD WINAPI ThreadProc2(LPVOID lpParameter)				
{				
	TCHAR szBuffer[10] = {0};			
				
	//当事件变成已通知时 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//读取内容			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit2,szBuffer);
	
	Sleep(1000);
	
	SetEvent(g_hEvent);	
				
	return 0;			
}				
DWORD WINAPI ThreadProc3(LPVOID lpParameter)				
{				
	TCHAR szBuffer[10] = {0};			
				
	//当事件变成已通知时 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//读取内容			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit3,szBuffer);	
	
	Sleep(1000);

	SetEvent(g_hEvent);	
				
	return 0;			
}				
DWORD WINAPI ThreadProc4(LPVOID lpParameter)				
{				
	TCHAR szBuffer[10] = {0};			
				
	//当事件变成已通知时 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//读取内容			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit4,szBuffer);	

	Sleep(1000);
	
	SetEvent(g_hEvent);	
				
	return 0;			
}				


DWORD WINAPI ThreadProc1(LPVOID lpParameter)				
{				
	//创建事件			
	//默认安全属性  手动设置未通知状态(TRUE)  初始状态未通知 没有名字 			
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);			
	HANDLE hThread[3];			
	//创建3个线程			
	hThread[0] = ::CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);			
	hThread[1] = ::CreateThread(NULL, 0, ThreadProc3, NULL, 0, NULL);			
	hThread[2] = ::CreateThread(NULL, 0, ThreadProc4, NULL, 0, NULL);			
				
	//设置文本框的值			
	SetWindowText(hEdit1,"1000");	
	
	Sleep(1000);
				
	//设置事件为已通知			
	SetEvent(g_hEvent);			
				
	//等待线程结束 销毁内核对象			
	WaitForMultipleObjects(3, hThread, TRUE, INFINITE);  			
	CloseHandle(hThread[0]);  			
	CloseHandle(hThread[1]);			
	CloseHandle(hThread[2]);			
	CloseHandle(g_hEvent);  			
				
	return 0;			
}				
				

BOOL CALLBACK DialogProc(									
						 HWND hwndDlg,  // handle to dialog box			
						 UINT uMsg,     // message			
						 WPARAM wParam, // first message parameter			
						 LPARAM lParam  // second message parameter			
						 )			
{	
	
	switch(uMsg)								
	{								
	case  WM_INITDIALOG :
		{						
				hEdit1 = GetDlgItem(hwndDlg,IDC_EDIT1);
				hEdit2 = GetDlgItem(hwndDlg,IDC_EDIT2);
				hEdit3 = GetDlgItem(hwndDlg,IDC_EDIT3);
				hEdit4 = GetDlgItem(hwndDlg,IDC_EDIT4);

		return TRUE ;
		}
	case  WM_CLOSE:
		{
			
			EndDialog(hwndDlg, 0);
			return TRUE;
		}
									
	case  WM_COMMAND :								
									
		switch (LOWORD (wParam))							
		{							
		case   IDC_BUTTON_START:	
			{
				

			 HANDLE	hThreadSTART = ::CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
			::CloseHandle(hThreadSTART);
									
			return TRUE;						
			}
									
		
		}
		break ;							
    }									
									
	return FALSE ;								
}									
		


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	hAppInstance=hInstance;
 	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,DialogProc);


	return 0;
}



