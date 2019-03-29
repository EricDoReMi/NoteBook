// ThreadGetCharactors.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

HWND hEditResource=NULL;
HWND hEditCash1=NULL;
HWND hEditCash2=NULL;
HWND hEditEat1=NULL;
HWND hEditEat2=NULL;
HWND hEditEat3=NULL;
HWND hEditEat4=NULL;

HANDLE g_hSet, g_hGet;
HANDLE hSemaphore;		
HWND hEditEatArr[4];
HWND hEditCashArr[2];


//写字母的线程
DWORD WINAPI PushThread(LPVOID lpParameter){
				
				//获取文本框内容
				TCHAR rsBuffer[0x50];
				memset(rsBuffer,0,0x50);
				TCHAR cashBuffer[0x50];
				memset(cashBuffer,0,0x50);
				TCHAR charTmp=0;
				TCHAR setBuffer[0x50];
				memset(setBuffer,0,0x50);
				TCHAR* pSourcePointer=0;
				DWORD index=0;
				DWORD i=0;
				
				
				GetWindowText(hEditResource,rsBuffer,0x50);

				
				charTmp=rsBuffer[0];
				for(index=0;index<strlen(rsBuffer);index++){
					
					
					for(i=0;i<2;i++){
						
						memset(cashBuffer,0,0x50);

						
						WaitForSingleObject(g_hSet, INFINITE);
						GetWindowText(hEditCashArr[i],cashBuffer,0x50);

						if(!strlen(cashBuffer)){
							
							Sleep(1000);

							memset(setBuffer,0,0x50);
							setBuffer[0]=charTmp;
							SetWindowText(hEditCashArr[i],setBuffer);
							charTmp=rsBuffer[index+1];
							
							
						}
						SetEvent(g_hGet);
					
					}

					

					

				
				}
				
					
	return 0;

}



//抢字母的线程
DWORD WINAPI PopThread(LPVOID lpParameter){
				
				DWORD editIndex=(DWORD)lpParameter;

				//获取文本框内容
				TCHAR rsBuffer[0x50];
				memset(rsBuffer,0,0x50);
				TCHAR cashBuffer[0x50];
				memset(cashBuffer,0,0x50);
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				TCHAR charTmp=0;
				TCHAR setBuffer[0x50];
				memset(setBuffer,0,0x50);
				DWORD index=0;
				DWORD i=0;
				
				
				GetWindowText(hEditResource,rsBuffer,0x50);
			

				
				for(index=0;index<strlen(rsBuffer);index++){
					
					
					for(i=0;i<2;i++){
						memset(cashBuffer,0,0x50);
						WaitForSingleObject(hSemaphore, INFINITE);
						WaitForSingleObject(g_hGet, INFINITE);
						GetWindowText(hEditCashArr[i],cashBuffer,0x50);

							if(strlen(cashBuffer)){
								
								Sleep(1000);
								charTmp=cashBuffer[0];
								
								memset(setBuffer,0,0x50);
								setBuffer[0]=charTmp;
								setBuffer[1]=TEXT(',');

								memset(szBuffer,0,0x50);
								
								GetWindowText(hEditEatArr[editIndex],szBuffer,0x50);
								
								strcat(szBuffer,setBuffer);

								SetWindowText(hEditEatArr[editIndex],szBuffer);

								SetWindowText(hEditCashArr[i],"");
								
								
											
							}
						
						
						SetEvent(g_hSet);	
						ReleaseSemaphore(hSemaphore,1,NULL);
						
						
					}

					

					

				}
				
				
				
			

	return 0;

}

//开始
DWORD WINAPI StartThread(LPVOID lpParameter){
	//初始化
	SetWindowText(hEditCash1,"");
	SetWindowText(hEditCash2,"");
	SetWindowText(hEditEat1,"");
	SetWindowText(hEditEat2,"");
	SetWindowText(hEditEat3,"");
	SetWindowText(hEditEat4,"");
	

	hSemaphore =  CreateSemaphore(NULL,0,2,NULL);
	g_hSet = CreateEvent(NULL, FALSE, TRUE, NULL);  					
    g_hGet = CreateEvent(NULL, FALSE, FALSE, NULL); 						



	HANDLE hArray[5];
	HANDLE hThreadPush = ::CreateThread(NULL, 0, PushThread,NULL, 0, NULL);
	
	HANDLE hThreadPop1 = ::CreateThread(NULL, 0, PopThread, (void*)0, 0, NULL);
	HANDLE hThreadPop2 = ::CreateThread(NULL, 0, PopThread, (void*)1, 0, NULL);
	HANDLE hThreadPop3 = ::CreateThread(NULL, 0, PopThread, (void*)2, 0, NULL);
	HANDLE hThreadPop4 = ::CreateThread(NULL, 0, PopThread, (void*)3, 0, NULL);

	ReleaseSemaphore(hSemaphore,1,NULL);

	hArray[0] = hThreadPush;		
	hArray[1] = hThreadPop1;		
	hArray[2] = hThreadPop2;
	hArray[3] = hThreadPop3;
	hArray[4] = hThreadPop4;
	
	::WaitForMultipleObjects(5, hArray,TRUE,INFINITE);
		

	::CloseHandle(hThreadPush);		
	::CloseHandle(hThreadPop1);
	::CloseHandle(hThreadPop2);
	::CloseHandle(hThreadPop3);
	::CloseHandle(hThreadPop4);
	
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
				hEditResource = GetDlgItem(hwndDlg,IDC_EDIT_RESOURCE);
				hEditCash1 = GetDlgItem(hwndDlg,IDC_EDIT_CASH1);
				hEditCash2 = GetDlgItem(hwndDlg,IDC_EDIT_CASH2);
				hEditEat1 = GetDlgItem(hwndDlg,IDC_EDIT_EATER1);
				hEditEat2 = GetDlgItem(hwndDlg,IDC_EDIT_EATER3);
				hEditEat3 = GetDlgItem(hwndDlg,IDC_EDIT_EATER4);
				hEditEat4 = GetDlgItem(hwndDlg,IDC_EDIT_EATER2);

				hEditEatArr[0]=hEditEat1;
				hEditEatArr[1]=hEditEat2;
				hEditEatArr[2]=hEditEat3;
				hEditEatArr[3]=hEditEat4;
				hEditCashArr[0]=hEditCash1;
				hEditCashArr[1]=hEditCash2;

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



