// PETool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include <commctrl.h>				
#pragma comment(lib,"comctl32.lib")				


HINSTANCE hAppInstance;

//遍历进程
VOID EnumProcess(HWND hListProcess){
	LV_ITEM vitem;						
						
	//初始化						
	memset(&vitem,0,sizeof(LV_ITEM));						
	vitem.mask = LVIF_TEXT;						
							
	vitem.pszText = "csrss.exe";						
	vitem.iItem = 0;//第几行						
	vitem.iSubItem = 0;	//第几列				
	//这是一个宏，和SendMessage做的事情是一样的，第一列时要用ListView_InsertItem，后面的列用ListView_SetItem
	//ListView_InsertItem(hListProcess, &vitem);
	SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);						
							
	vitem.pszText = TEXT("448");						
	vitem.iItem = 0;						
	vitem.iSubItem = 1;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("56590000");						
	vitem.iItem = 0;						
	vitem.iSubItem = 2;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("000F0000");						
	vitem.iItem = 0;						
	vitem.iSubItem = 3;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("winlogon.exe");						
	vitem.iItem = 1;						
	vitem.iSubItem = 0;						
	//ListView_InsertItem(hListProcess, &vitem);						
	SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);						
							
	vitem.pszText = TEXT("456");						
	vitem.iSubItem = 1;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("10000000");						
	vitem.iSubItem = 2;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("000045800");						
	vitem.iSubItem = 3;						
	ListView_SetItem(hListProcess, &vitem);						

}

//遍历module
//hListProcess:ProcessListView的句柄
VOID EnumModules(HWND hListProcess,WPARAM wparam,LPARAM lparam){

	DWORD dwRowId;
	TCHAR szPid[0x20];
	LV_ITEM lv;						
						
	//初始化						
	memset(&lv,0,sizeof(LV_ITEM));
	memset(szPid,0,0x20);
	
	//获得processView选定行
	dwRowId=SendMessage(hListProcess, LVM_GETNEXTITEM,-1,LVNI_SELECTED);						
							
	if(dwRowId==-1){
		MessageBox(NULL,TEXT("请选择进程"),TEXT("出错啦"),MB_OK);
		return;
	}
	
	//获取PID
	lv.iSubItem=1;//要获取的列
	lv.pszText=szPid;//指定查询结果的缓冲区
	lv.cchTextMax=0x20;//查询结果缓冲区的大小
	SendMessage(hListProcess,LVM_GETITEMTEXT,dwRowId,(DWORD)&lv);
	
	MessageBox(0,szPid,TEXT("PID"),MB_OK);


}


//初始化进程列表
VOID InitProcessListView(HWND hDlg){
	LV_COLUMN lv;//存储了								
	HWND hListProcess;//获得ListView句柄							
									
	//初始化								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//获取IDC_LIST_PROCESS句柄								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_PROCESS);								
	//设置整行选中								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//第一列								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("进程");				//列标题				
	lv.cx = 150;								//列宽
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//第二列								
	lv.pszText = TEXT("PID");								
	lv.cx = 60;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//第三列								
	lv.pszText = TEXT("镜像基址");								
	lv.cx = 100;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//第四列								
	lv.pszText = TEXT("镜像大小");								
	lv.cx = 100;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);								
	EnumProcess(hListProcess);
}

//初始化模块列表
VOID InitModuleListView(HWND hDlg){
	LV_COLUMN lv;//存储了								
	HWND hListProcess;//获得ListView句柄							
									
	//初始化								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//获取IDC_LIST_PROCESS句柄								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_MODULE);								
	//设置整行选中								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//第一列								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("模块名称");				//列标题				
	lv.cx = 200;								//列宽
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//第二列								
	lv.pszText = TEXT("模块位置");								
	lv.cx = 200;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
							
}



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
			/*hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
			hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

			//设置图标	
			SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
			SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);*/	

			//设置ProcessListView的风格
			InitProcessListView(hwndDlg);

			//设置ModuleListView的风格
			InitModuleListView(hwndDlg);
			

			break;
		
		case WM_CLOSE:

			EndDialog(hwndDlg, 0);

			return TRUE;

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



