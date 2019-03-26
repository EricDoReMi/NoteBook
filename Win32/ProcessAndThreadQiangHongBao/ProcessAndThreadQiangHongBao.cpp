/*第一步：在第一个文本框中输入一个值，比如1000									
									
第二步：点击抢红包，同时创建3个线程，每个线程循环进行抢红包的操作，每次抢50									在抢红包按钮被点击后创建一个线程，然后再创建3个线程来抢红包
									
第三步：使用Mutex进行线程控制，当第一个文本框中的值<50时，强红包线程结束.									否则会造成程序卡死
									
特别说明：									
									
1、四个文本框中的值总和应该为1000									
									
2、强红包线程每次延时50毫秒.									
									
3、使用WaitForMultipleObjects监听所有线程，当线程全部结束后									
   调用CloseHandle关闭互斥区的句柄.	*/								
									


#include "stdafx.h"


HINSTANCE hAppInstance=NULL;
HWND hEdit1=NULL;
HWND hEdit2=NULL;
HWND hEdit3=NULL;
HWND hEdit4=NULL;
DWORD total=0;


//抢红包的线程
DWORD WINAPI PopThread(LPVOID lpParameter){
				
				DWORD editIndex=(DWORD)lpParameter;

				//获取文本框内容
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				
				
				
				DWORD myValue=0;
				HANDLE g_hMutex = OpenMutex(MUTEX_ALL_ACCESS,FALSE, "XYZ");		
				
				while(true){
					WaitForSingleObject(g_hMutex,INFINITE);
					if(total<50){
						ReleaseMutex(g_hMutex);
						break;
					}
					
					total-=50;
					myValue+=50;
					Sleep(500);
					//转成字符串
					memset(szBuffer,0,0x50);
						
					sprintf(szBuffer,"%d",total);	
					
						//写回
					SetWindowText(hEdit1,szBuffer);	

					memset(szBuffer,0,0x50);
					sprintf(szBuffer,"%d",myValue);	
					
					switch(editIndex)
					{
						case 1:
							{
								SetWindowText(hEdit2,szBuffer);	
								break;
							}
						case 2:
							{
								SetWindowText(hEdit3,szBuffer);	
								break;
							}
						case 3:
							{
								SetWindowText(hEdit4,szBuffer);	
								break;
							}
					}

				
					ReleaseMutex(g_hMutex);
				}
			

	return 0;

}


//开始
DWORD WINAPI StartThread(LPVOID lpParameter){
	//初始化
	SetWindowText(hEdit1,"1000");
	SetWindowText(hEdit2,"0");
	SetWindowText(hEdit3,"0");
	SetWindowText(hEdit4,"0");
	total=1000;

	HANDLE g_hMutex = CreateMutex(NULL,FALSE,"XYZ");

	HANDLE hArray[2];	
	
	HANDLE hThread1 = ::CreateThread(NULL, 0, PopThread, (void*)1, 0, NULL);
	HANDLE hThread2 = ::CreateThread(NULL, 0, PopThread, (void*)2, 0, NULL);
	HANDLE hThread3 = ::CreateThread(NULL, 0, PopThread, (void*)3, 0, NULL);

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
		case   IDC_BUTTON_CLICK:	
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
	hAppInstance=hInstance;
 	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,DialogProc);


	return 0;
}



