// PETool.cpp : Defines the entry point for the application.
//
#include "StdAfx.h"

HINSTANCE hAppInstance;
HWND g_hwndDlg;//主窗口句柄
HWND g_PEDlg;//PE窗口的句柄
HWND g_SECTIONDlg;//PESection窗口的句柄
HWND g_DICDlg;//PE目录表窗口的句柄
HWND g_DICDetailDlg;//PE目录表详情窗口的句柄
TCHAR szFileName[256];//PE文件的路径
LPVOID pFileBuffer=NULL;//PE文件的FileBuffer
int IDC_BUTTON_DIC_Index;//被点击了的目录详情的Button的ID
HWND hDicDetailEdit;//目录详情的RichEdit


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
							//获取PE目录表对话框的线程
							//创建获得PE目录表的信息的线程
							HANDLE	hPEDicThread = ::CreateThread(NULL, 0, PEDicThread, NULL, 0, NULL);
							::CloseHandle(hPEDicThread);
							return TRUE;
						}
					
					case IDC_BUTTON_PEHEAD_SECTION:
						{	
							//获得PE节表的信息
							//创建获得PE节表的信息的线程
						HANDLE	hPESectionThread = ::CreateThread(NULL, 0, PESectionThread, NULL, 0, NULL);
						::CloseHandle(hPESectionThread);
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


//Section展示的Dialog
BOOL CALLBACK SectionDialogProc(									
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

			g_SECTIONDlg=hwndDlg;


			//获取Section相关信息
			//创建来获取Section信息的线程
			HANDLE	hPESectionReadThread = ::CreateThread(NULL, 0, PESectionReadThread, NULL, 0, NULL);
			::CloseHandle(hPESectionReadThread);
			

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
				

			break ;	
			}
		}									

		return FALSE;	
										
								
}		

//DIC展示的Dialog
BOOL CALLBACK DicDialogProc(									
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

			g_DICDlg=hwndDlg;


			//获取Directory相关信息
			//创建来获取Directory信息的线程
			HANDLE	hPEDicReadThread = ::CreateThread(NULL, 0, PEDicReadThread, NULL, 0, NULL);
			::CloseHandle(hPEDicReadThread);
			

			break;
			}
		case WM_SIZE:
			{
				AdjustEditWindow(hwndDlg,hDicDetailEdit);
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

					case IDC_BUTTON_DIC_IMPORT:
						{
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_IMPORT;
							
							

							AlertDicDetail();		
							return TRUE;
						}
					
					case IDC_BUTTON_DIC_EXPORT:
						{	
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_EXPORT;
							//AlertDicDetail();
							return TRUE;
						}
					case IDC_BUTTON_DIC_RESOURSE:
						{	
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_RESOURSE;
							//AlertDicDetail();
							return TRUE;
						}
					case IDC_BUTTON_DIC_RELOCATION:
						{	
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_RELOCATION;
							//AlertDicDetail();
							return TRUE;
						}
					case IDC_BUTTON_DIC_BOUND:
						{	
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_BOUND;
							//AlertDicDetail();
							return TRUE;
						}
					case IDC_BUTTON_DIC_IAT:
						{	
							IDC_BUTTON_DIC_Index=IDC_BUTTON_DIC_IAT;
							//AlertDicDetail();
							return TRUE;
						}
						
					case IDC_BUTTON_DIC_CLOSE:							
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

//目录表详情
BOOL CALLBACK DicDetailDialogProc(									
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

			g_DICDetailDlg=hwndDlg;


			//获取PE目录详细信息
			//创建来获取PE目录详细信息的线程
			HANDLE	hPEDicDetailReadThread = ::CreateThread(NULL, 0, PEDicDetailReadThread, NULL, 0, NULL);
			::CloseHandle(hPEDicDetailReadThread);
			

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
    HINSTANCE edit_hinstance=LoadLibrary(TEXT("RichEd20.dll"));


	//使用通用控件
	INITCOMMONCONTROLSEX icex;				
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);				
	icex.dwICC = ICC_WIN95_CLASSES;				
	InitCommonControlsEx(&icex);				
	

 	hAppInstance=hInstance;

	


	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,MainDialogProc);
	
	if (edit_hinstance)
	{
		FreeLibrary(edit_hinstance);
	}
	
	return 0;
}





