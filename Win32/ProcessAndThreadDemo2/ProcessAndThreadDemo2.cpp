// ProcessAndThreadDemo2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

HINSTANCE hAppInstance;
HWND hEdit=NULL;
HANDLE hThreadSTART=NULL;



//��ʼ
DWORD WINAPI StartThread(LPVOID lpParameter){
	//��ȡ�ı�������
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				


				//ת������
				DWORD dwTimer;
				DWORD dwIndex=0;
						

				while(dwIndex<1000){

					GetWindowText(hEdit,szBuffer,0x50);
					sscanf( szBuffer, "%d", &dwTimer );	
				
					dwTimer++;
					Sleep(200);
					//ת���ַ���
					memset(szBuffer,0,0x50);
					
					sprintf(szBuffer,"%d",dwTimer);	
					
					//д��
					SetWindowText(hEdit,szBuffer);	
					dwIndex++;
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
	case  WM_INITDIALOG:
		{						
		

		//��һ�����Ȼ�ȡ�ı���ľ��
		hEdit = GetDlgItem(hwndDlg,IDC_EDIT);

		SetWindowText(hEdit,"0");
		
		return TRUE;
		}
		
	case WM_CLOSE:
		{
		EndDialog(hwndDlg, 0);
		return TRUE;			
		}
									
	case  WM_COMMAND :								
		{							
			switch (LOWORD (wParam))							
					{							
					case   IDC_BUTTON_START :	
						{
							hThreadSTART = ::CreateThread(NULL, 0, StartThread, NULL, 0, NULL);				
							
							
			
												
							return TRUE;						
						}						
					case   IDC_BUTTON_HUG:							
						{											
							::SuspendThread(hThreadSTART);	

							//������δ�����������ʾ�ֶ��л��߳�
							
							/*CONTEXT context;							
								
							context.ContextFlags = CONTEXT_CONTROL;
							BOOL ok = ::GetThreadContext(hThreadSTART,&context);

							context.Eip = 0x401000;				
				
							SetThreadContext(hThreadSTART,&context);				

							::ResumeThread(hThreadSTART);*/

							return TRUE;

						}

					case   IDC_BUTTON_RETURN :
						{
									
							::ResumeThread(hThreadSTART);				
							return TRUE;						

						}

				case   IDC_BUTTON_STOP :
					{
						::TerminateThread(hThreadSTART,3);					
						::WaitForSingleObject(hThreadSTART,INFINITE);		

					
					return TRUE;						
					}	
					
				case   IDC_BUTTON_STATU :
					{
						DWORD returnCode=0;

						if(::GetExitCodeThread(hThreadSTART,&returnCode)){
							TCHAR returnBuffer[20];
							memset(returnBuffer,0,20);
							sprintf(returnBuffer,"��ֹ�ˣ�%d",returnCode);			

							MessageBox(0,returnBuffer,0,0);
						}
		

					
					return TRUE;						
					}
								
					}
		break ;	

		}
		

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



