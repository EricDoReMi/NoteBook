// SiginalDemo01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


HWND hEdit1=NULL;
HWND hEdit2=NULL;
HWND hEdit3=NULL;
HWND hEdit4=NULL;

HANDLE hSemaphore;		
HWND hEditArr[3];		


//抢红包的线程
DWORD WINAPI PopThread(LPVOID lpParameter){
				
				DWORD editIndex=(DWORD)lpParameter;

				//获取文本框内容
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				
				WaitForSingleObject(hSemaphore, INFINITE);
				DWORD count=0;
				
				while(count<100){
					if(editIndex==0){ 

						Sleep(50);
					}else{
						Sleep(80);
						}
					GetWindowText(hEditArr[editIndex],szBuffer,0x50);
					sscanf(szBuffer, "%d", &count);
					count++;
					sprintf(szBuffer,"%d",count);
					SetWindowText(hEditArr[editIndex],szBuffer);
				}

				ReleaseSemaphore(hSemaphore,1,NULL);
			

	return 0;

}

//开始
DWORD WINAPI StartThread(LPVOID lpParameter){
	//初始化
	SetWindowText(hEdit1,"0");
	SetWindowText(hEdit2,"0");
	SetWindowText(hEdit3,"0");
	SetWindowText(hEdit4,"0");
	

	hSemaphore =  CreateSemaphore(NULL,0,3,NULL);


	HANDLE hArray[2];	
	
	HANDLE hThread1 = ::CreateThread(NULL, 0, PopThread, (void*)0, 0, NULL);
	HANDLE hThread2 = ::CreateThread(NULL, 0, PopThread, (void*)1, 0, NULL);
	HANDLE hThread3 = ::CreateThread(NULL, 0, PopThread, (void*)2, 0, NULL);

	DWORD count=0;

	//缓冲区
	TCHAR szBuffer[0x50];
	memset(szBuffer,0,0x50);

	while(count<100){
		Sleep(50);
		GetWindowText(hEdit1,szBuffer,0x50);
		sscanf(szBuffer, "%d", &count);
		count++;
		sprintf(szBuffer,"%d",count);

		SetWindowText(hEdit1,szBuffer);
	}

	ReleaseSemaphore(hSemaphore,2,NULL);

	hArray[0] = hThread1;		
	hArray[1] = hThread2;		
	hArray[2] = hThread2;	
	
	::WaitForMultipleObjects(3, hArray,TRUE,INFINITE);
		

	::CloseHandle(hThread1);		
	::CloseHandle(hThread2);
	::CloseHandle(hThread3);
	
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

				hEditArr[0]=hEdit2;
				hEditArr[1]=hEdit3;
				hEditArr[2]=hEdit4;

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
				

			 HANDLE	hThreadSTART = ::CreateThread(NULL, 0, StartThread, NULL, 0, NULL);
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
 	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,DialogProc);

	return 0;
}



