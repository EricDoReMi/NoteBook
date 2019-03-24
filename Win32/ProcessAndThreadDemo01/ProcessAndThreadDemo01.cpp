/*要求：		
		
点击开始后，第一个文本框的值从1000每隔1秒种减1 直到0		
		
第二个文本框从0每隔1秒钟加1 直到1000		*/


#include "stdafx.h"
#include "resource.h"
#include <stdio.h>

HINSTANCE hAppInstance;

HWND hEdit1=NULL;
HWND hEdit2=NULL;

DWORD WINAPI TimerEdit1(LPVOID lpParameter){
	//获取文本框内容
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				GetWindowText(hEdit1,szBuffer,0x50);


				//转成整数
				DWORD dwTimer;
				sscanf( szBuffer, "%d", &dwTimer );			

				while(dwTimer>=0){
					//--
					dwTimer--;
				
					//转成字符串
					memset(szBuffer,0,0x50);
					Sleep(1000);
					sprintf(szBuffer,"%d",dwTimer);	
					
					//写回
					SetWindowText(hEdit1,szBuffer);	
				
				}

	return 0;

}

DWORD WINAPI TimerEdit2(LPVOID lpParameter){
	//获取文本框内容
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				GetWindowText(hEdit2,szBuffer,0x50);


				//转成整数
				DWORD dwTimer;
				sscanf( szBuffer, "%d", &dwTimer );			

				while(dwTimer<=1000){
					//++
					dwTimer++;
				
					//转成字符串
					memset(szBuffer,0,0x50);
					Sleep(1000);
					sprintf(szBuffer,"%d",dwTimer);	
					
					//写回
					SetWindowText(hEdit2,szBuffer);	
				
				}
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

			//第一步：先获取文本框的句柄
			 hEdit1 = GetDlgItem(hwndDlg,IDC_EDIT_LEFT);
			 hEdit2 = GetDlgItem(hwndDlg,IDC_EDIT_RIGHT);

			//第二步：通过文本框句柄获得文本框的内容
			TCHAR szEdit1Buff[0x50];	
			TCHAR szEdit2Buff[0x50];	
			
			strcpy(szEdit1Buff,"1000");
			strcpy(szEdit2Buff,"0");

			SetWindowText(hEdit1,szEdit1Buff);			
			SetWindowText(hEdit2,szEdit2Buff);

		return TRUE ;
	
	case WM_CLOSE:
		EndDialog(hwndDlg, 0);
		return TRUE;
									
	case  WM_COMMAND :								
									
		switch (LOWORD (wParam))							
		{							
			case  IDC_BUTTON_START :	
			
			HANDLE hThread1 = ::CreateThread(NULL, 0, TimerEdit1, NULL, 0, NULL);				
			HANDLE hThread2 = ::CreateThread(NULL, 0, TimerEdit2, NULL, 0, NULL);				
					
			//如果不在其他的地方引用它 关闭句柄				并不是关闭线程	
			::CloseHandle(hThread1);					
			::CloseHandle(hThread2);					
			

		
			return TRUE;						
										
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
 	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG1),NULL,DialogProc);

	
	return 0;
}



