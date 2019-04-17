// PETool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

HINSTANCE hAppInstance;
HWND g_hwndDlg;//主窗口句柄

BOOL CALLBACK DialogProc(									
						 HWND hwndDlg,  // handle to dialog box			
						 UINT uMsg,     // message			
						 WPARAM wParam, // first message parameter			
						 LPARAM lParam  // second message parameter			
						 )			
{	
	HICON hBigIcon=NULL;	
	HICON hSmallIcon=NULL;	

	HWND hEditUser=NULL;
	HWND hPassWord=NULL;

	
	switch(uMsg)								
	{								
		case  WM_INITDIALOG :
			{
			//获得图标句柄						
			/*hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
			hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

			//设置图标	
			SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
			SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);*/	
			g_hwndDlg=hwndDlg;

			//创建进程和线程视图线程
			HANDLE	hProcessAndMode = ::CreateThread(NULL, 0, ProcessAndModeThread, NULL, 0, NULL);
			::CloseHandle(hProcessAndMode);

			
			

			break;
			}
		case WM_CLOSE:
			{
			EndDialog(hwndDlg, 0);

			return TRUE;
			}
			//处理通用控件的消息
		case WM_NOTIFY:
			{
				NMHDR* pNMHDR = (NMHDR*)lParam;
				if(wParam == IDC_LIST_PROCESS && pNMHDR->code == NM_CLICK){
					EnumModules(GetDlgItem(hwndDlg,IDC_LIST_PROCESS),wParam,lParam);
					}
				break;
			}
			
										
		case  WM_COMMAND:								
			{							
				switch (LOWORD (wParam))							
				{							
					case  IDC_BUTTON_PE :					
												
						return TRUE;

					case IDC_BUTTON_About:

						return TRUE;
												
					case IDC_BUTTON_LOGOUT:							
												
						EndDialog(hwndDlg, 0);						
												
						return TRUE;						
				}

			break ;	
			}
		}									

		return FALSE;	
										
								
}					

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	INITCOMMONCONTROLSEX icex;				
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);				
	icex.dwICC = ICC_WIN95_CLASSES;				
	InitCommonControlsEx(&icex);				


 	hAppInstance=hInstance;
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,DialogProc);
	return 0;
}



