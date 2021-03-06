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
		//获得图标句柄						
		hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
		hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

		//设置图标	
		SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
		SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);	

		return TRUE ;							
									
	case  WM_COMMAND :								
									
		switch (LOWORD (wParam))							
		{							
		case   IDC_BUTTON_OK :	
			
			//第一步：先获取文本框的句柄
			 hEditUser = GetDlgItem(hwndDlg,IDC_EDIT_USERNAME);
			 hPassWord = GetDlgItem(hwndDlg,IDC_EDIT_PASSWORD);

			//第二步：通过文本框句柄获得文本框的内容
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



