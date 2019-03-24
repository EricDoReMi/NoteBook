// DialogFirst.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

HINSTANCE hAppInstance;

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
		//���ͼ����						
		hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
		hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

		//����ͼ��	
		SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
		SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);	

		return TRUE ;							
									
	case  WM_COMMAND :								
									
		switch (LOWORD (wParam))							
		{							
		case   IDC_BUTTON_OK :	
			
			//��һ�����Ȼ�ȡ�ı���ľ��
			 hEditUser = GetDlgItem(hwndDlg,IDC_EDIT_USERNAME);
			 hPassWord = GetDlgItem(hwndDlg,IDC_EDIT_PASSWORD);

			//�ڶ�����ͨ���ı���������ı��������
			TCHAR szUserNameBuff[0x50];	
			TCHAR szPassWordBuff[0x50];	
	
			GetWindowText(hEditUser,szUserNameBuff,0x50);	
			GetWindowText(hPassWord,szPassWordBuff,0x50);
									
			MessageBox(NULL,TEXT("IDC_BUTTON_OK"),TEXT("OK"),MB_OK);						
									
			return TRUE;						
									
		case   IDC_BUTTON_ERROR:							
									
			MessageBox(NULL,TEXT("IDC_BUTTON_ERROR"),TEXT("ERROR"),MB_OK);						
									
			EndDialog(hwndDlg, 0);						
									
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
 	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG1_MAIN),NULL,DialogProc);

	return 0;
}



