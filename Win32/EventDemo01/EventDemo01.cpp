// Edit1��Ϊ1000��Edit2��Edit3��Edit4�ֱ����ζ�ȡ��ֵ
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
				
	//���¼������֪ͨʱ 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//��ȡ����			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit2,szBuffer);
	
	Sleep(1000);
	
	SetEvent(g_hEvent);	
				
	return 0;			
}				
DWORD WINAPI ThreadProc3(LPVOID lpParameter)				
{				
	TCHAR szBuffer[10] = {0};			
				
	//���¼������֪ͨʱ 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//��ȡ����			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit3,szBuffer);	
	
	Sleep(1000);

	SetEvent(g_hEvent);	
				
	return 0;			
}				
DWORD WINAPI ThreadProc4(LPVOID lpParameter)				
{				
	TCHAR szBuffer[10] = {0};			
				
	//���¼������֪ͨʱ 			
	WaitForSingleObject(g_hEvent, INFINITE);			
				
	//��ȡ����			
	GetWindowText(hEdit1,szBuffer,10);			
				
	SetWindowText(hEdit4,szBuffer);	

	Sleep(1000);
	
	SetEvent(g_hEvent);	
				
	return 0;			
}				


DWORD WINAPI ThreadProc1(LPVOID lpParameter)				
{				
	//�����¼�			
	//Ĭ�ϰ�ȫ����  �ֶ�����δ֪ͨ״̬(TRUE)  ��ʼ״̬δ֪ͨ û������ 			
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);			
	HANDLE hThread[3];			
	//����3���߳�			
	hThread[0] = ::CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);			
	hThread[1] = ::CreateThread(NULL, 0, ThreadProc3, NULL, 0, NULL);			
	hThread[2] = ::CreateThread(NULL, 0, ThreadProc4, NULL, 0, NULL);			
				
	//�����ı����ֵ			
	SetWindowText(hEdit1,"1000");	
	
	Sleep(1000);
				
	//�����¼�Ϊ��֪ͨ			
	SetEvent(g_hEvent);			
				
	//�ȴ��߳̽��� �����ں˶���			
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



