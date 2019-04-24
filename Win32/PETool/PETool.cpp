// PETool.cpp : Defines the entry point for the application.
//
#include "StdAfx.h"

HINSTANCE hAppInstance;
HWND g_hwndDlg;//�����ھ��
HWND g_PEDlg;//PE���ڵľ��
HWND g_SECTIONDlg;//PESection���ڵľ��
HWND g_DICDlg;//PEĿ¼���ڵľ��
HWND g_DICDetailDlg;//PEĿ¼�����鴰�ڵľ��
TCHAR szFileName[256];//PE�ļ���·��
LPVOID pFileBuffer=NULL;//PE�ļ���FileBuffer
int IDC_BUTTON_DIC_Index;//������˵�Ŀ¼�����Button��ID
HWND hDicDetailEdit;//Ŀ¼�����RichEdit


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
			//���ͼ����						
			/*hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
			hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

			//����ͼ��	
			SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
			SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);*/	
			g_hwndDlg=hwndDlg;

			//�������̺��߳���ͼ�߳�
			HANDLE	hProcessAndMode = ::CreateThread(NULL, 0, ProcessAndModeThread, NULL, 0, NULL);
			::CloseHandle(hProcessAndMode);

			
			

			break;
			}
		case WM_CLOSE:
			{
			EndDialog(hwndDlg, 0);

			return TRUE;
			}
			//����ͨ�ÿؼ�����Ϣ
		case WM_NOTIFY:
			{
				NMHDR* pNMHDR = (NMHDR*)lParam;
				if(wParam == IDC_LIST_PROCESS && pNMHDR->code == NM_CLICK){
						//��������ģ����߳�
						HANDLE	hEnumMode = ::CreateThread(NULL, 0, EnumModeThread, NULL, 0, NULL);
						::CloseHandle(hEnumMode);
					
					}
				break;
			}
			
										
		case  WM_COMMAND:								
			{							
				switch (LOWORD (wParam))							
				{	
					//PE�鿴
					case  IDC_BUTTON_PE :					
						{			
							//�����鿴PE���߳�
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

//PEչʾ��Dialog
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

			//��PE�ļ���ȡ�����Ϣ
			//��������ȡPE��Ϣ���߳�
			HANDLE	hPEReadThread = ::CreateThread(NULL, 0, PEReadThread, NULL, 0, NULL);
			::CloseHandle(hPEReadThread);
			

			break;
			}
		case WM_CLOSE:
			{
			EndDialog(hwndDlg, 0);

			return TRUE;
			}
			//����ͨ�ÿؼ�����Ϣ
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
							//��ȡPEĿ¼��Ի�����߳�
							//�������PEĿ¼�����Ϣ���߳�
							HANDLE	hPEDicThread = ::CreateThread(NULL, 0, PEDicThread, NULL, 0, NULL);
							::CloseHandle(hPEDicThread);
							return TRUE;
						}
					
					case IDC_BUTTON_PEHEAD_SECTION:
						{	
							//���PE�ڱ����Ϣ
							//�������PE�ڱ����Ϣ���߳�
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


//Sectionչʾ��Dialog
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


			//��ȡSection�����Ϣ
			//��������ȡSection��Ϣ���߳�
			HANDLE	hPESectionReadThread = ::CreateThread(NULL, 0, PESectionReadThread, NULL, 0, NULL);
			::CloseHandle(hPESectionReadThread);
			

			break;
			}
		case WM_CLOSE:
			{
			EndDialog(hwndDlg, 0);

			return TRUE;
			}
			//����ͨ�ÿؼ�����Ϣ
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

//DICչʾ��Dialog
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


			//��ȡDirectory�����Ϣ
			//��������ȡDirectory��Ϣ���߳�
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
			//����ͨ�ÿؼ�����Ϣ
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

//Ŀ¼������
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


			//��ȡPEĿ¼��ϸ��Ϣ
			//��������ȡPEĿ¼��ϸ��Ϣ���߳�
			HANDLE	hPEDicDetailReadThread = ::CreateThread(NULL, 0, PEDicDetailReadThread, NULL, 0, NULL);
			::CloseHandle(hPEDicDetailReadThread);
			

			break;
			}
		case WM_CLOSE:
			{
			EndDialog(hwndDlg, 0);

			return TRUE;
			}
			//����ͨ�ÿؼ�����Ϣ
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


	//ʹ��ͨ�ÿؼ�
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





