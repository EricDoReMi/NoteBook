/*Ҫ��		
		
�����ʼ�󣬵�һ���ı����ֵ��1000ÿ��1���ּ�1 ֱ��0		
		
�ڶ����ı����0ÿ��1���Ӽ�1 ֱ��1000		*/


#include "stdafx.h"
#include "resource.h"
#include <stdio.h>

HINSTANCE hAppInstance;

HWND hEdit1=NULL;
HWND hEdit2=NULL;

DWORD WINAPI TimerEdit1(LPVOID lpParameter){
	//��ȡ�ı�������
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				GetWindowText(hEdit1,szBuffer,0x50);


				//ת������
				DWORD dwTimer;
				sscanf( szBuffer, "%d", &dwTimer );			

				while(dwTimer>=0){
					//--
					dwTimer--;
				
					//ת���ַ���
					memset(szBuffer,0,0x50);
					Sleep(1000);
					sprintf(szBuffer,"%d",dwTimer);	
					
					//д��
					SetWindowText(hEdit1,szBuffer);	
				
				}

	return 0;

}

DWORD WINAPI TimerEdit2(LPVOID lpParameter){
	//��ȡ�ı�������
				TCHAR szBuffer[0x50];
				memset(szBuffer,0,0x50);
				GetWindowText(hEdit2,szBuffer,0x50);


				//ת������
				DWORD dwTimer;
				sscanf( szBuffer, "%d", &dwTimer );			

				while(dwTimer<=1000){
					//++
					dwTimer++;
				
					//ת���ַ���
					memset(szBuffer,0,0x50);
					Sleep(1000);
					sprintf(szBuffer,"%d",dwTimer);	
					
					//д��
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

			//��һ�����Ȼ�ȡ�ı���ľ��
			 hEdit1 = GetDlgItem(hwndDlg,IDC_EDIT_LEFT);
			 hEdit2 = GetDlgItem(hwndDlg,IDC_EDIT_RIGHT);

			//�ڶ�����ͨ���ı���������ı��������
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
					
			//������������ĵط������� �رվ��				�����ǹر��߳�	
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



