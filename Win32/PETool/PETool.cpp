// PETool.cpp : Defines the entry point for the application.
//
#include "StdAfx.h"

HINSTANCE hAppInstance;
HWND g_hwndDlg;//主窗口句柄
HWND g_PEDlg;//PE窗口句柄
TCHAR szFileName[256];//PE文件的路径


BOOL CALLBACK MainDialogProc(									
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
						//创建遍历模块的线程
						HANDLE	hEnumMode = ::CreateThread(NULL, 0, EnumModeThread, NULL, 0, NULL);
						::CloseHandle(hEnumMode);
					
					}
				break;
			}
			
										
		case  WM_COMMAND:								
			{							
				switch (LOWORD (wParam))							
				{	
					//PE查看
					case  IDC_BUTTON_PE :					
						{			
							//创建查看PE的线程
							HANDLE	hPEViewThread = ::CreateThread(NULL, 0, PEViewThread, NULL, 0, NULL);
							::CloseHandle(hPEViewThread);

							return TRUE;
						}
					case IDC_BUTTON_ENCRYPT:
						{
							return TRUE;
						}
					case IDC_BUTTON_INJECTION:
						{
							return TRUE;
						}
					
					case IDC_BUTTON_About:
						{	
							return TRUE;
						}
												
					case IDC_BUTTON_LOGOUT:							
						{						
							EndDialog(hwndDlg, 0);						
												
							return TRUE;						
						}
				}

			break ;	
			}
		}									

		return FALSE;	
										
								
}					

//PE展示的Dialog
BOOL CALLBACK PEDialogProc(									
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

			g_PEDlg=hwndDlg;

			//打开PE文件获取相关信息
			//创建来读取PE信息的线程
			HANDLE	hPEReadThread = ::CreateThread(NULL, 0, PEReadThread, NULL, 0, NULL);
			::CloseHandle(hPEReadThread);
			

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

				break;
			}
			
										
		case  WM_COMMAND:								
			{							
				switch (LOWORD (wParam))							
				{	

					case IDC_BUTTON_HEAD_DIC:
						{
							return TRUE;
						}
					
					case IDC_BUTTON_PEHEAD_SECTION:
						{	
							return TRUE;
						}
												
					case IDC_BUTTON_PEHEAD_CLOSE:							
						{						
							EndDialog(hwndDlg, 0);						
												
							return TRUE;						
						}
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
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,MainDialogProc);
	return 0;
}



