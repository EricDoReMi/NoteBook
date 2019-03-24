// PETool.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

#include <commctrl.h>				
#pragma comment(lib,"comctl32.lib")				


HINSTANCE hAppInstance;

//��������
VOID EnumProcess(HWND hListProcess){
	LV_ITEM vitem;						
						
	//��ʼ��						
	memset(&vitem,0,sizeof(LV_ITEM));						
	vitem.mask = LVIF_TEXT;						
							
	vitem.pszText = "csrss.exe";						
	vitem.iItem = 0;//�ڼ���						
	vitem.iSubItem = 0;	//�ڼ���				
	//����һ���꣬��SendMessage����������һ���ģ���һ��ʱҪ��ListView_InsertItem�����������ListView_SetItem
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

//����module
//hListProcess:ProcessListView�ľ��
VOID EnumModules(HWND hListProcess,WPARAM wparam,LPARAM lparam){

	DWORD dwRowId;
	TCHAR szPid[0x20];
	LV_ITEM lv;						
						
	//��ʼ��						
	memset(&lv,0,sizeof(LV_ITEM));
	memset(szPid,0,0x20);
	
	//���processViewѡ����
	dwRowId=SendMessage(hListProcess, LVM_GETNEXTITEM,-1,LVNI_SELECTED);						
							
	if(dwRowId==-1){
		MessageBox(NULL,TEXT("��ѡ�����"),TEXT("������"),MB_OK);
		return;
	}
	
	//��ȡPID
	lv.iSubItem=1;//Ҫ��ȡ����
	lv.pszText=szPid;//ָ����ѯ����Ļ�����
	lv.cchTextMax=0x20;//��ѯ����������Ĵ�С
	SendMessage(hListProcess,LVM_GETITEMTEXT,dwRowId,(DWORD)&lv);
	
	MessageBox(0,szPid,TEXT("PID"),MB_OK);


}


//��ʼ�������б�
VOID InitProcessListView(HWND hDlg){
	LV_COLUMN lv;//�洢��								
	HWND hListProcess;//���ListView���							
									
	//��ʼ��								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//��ȡIDC_LIST_PROCESS���								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_PROCESS);								
	//��������ѡ��								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//��һ��								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("����");				//�б���				
	lv.cx = 150;								//�п�
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//�ڶ���								
	lv.pszText = TEXT("PID");								
	lv.cx = 60;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//������								
	lv.pszText = TEXT("�����ַ");								
	lv.cx = 100;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//������								
	lv.pszText = TEXT("�����С");								
	lv.cx = 100;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);								
	EnumProcess(hListProcess);
}

//��ʼ��ģ���б�
VOID InitModuleListView(HWND hDlg){
	LV_COLUMN lv;//�洢��								
	HWND hListProcess;//���ListView���							
									
	//��ʼ��								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//��ȡIDC_LIST_PROCESS���								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_MODULE);								
	//��������ѡ��								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//��һ��								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("ģ������");				//�б���				
	lv.cx = 200;								//�п�
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//�ڶ���								
	lv.pszText = TEXT("ģ��λ��");								
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
			//���ͼ����						
			/*hBigIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_BIG));	
			hSmallIcon = LoadIcon (hAppInstance, MAKEINTRESOURCE (IDI_ICON_SMALL));	

			//����ͼ��	
			SendMessage(hwndDlg,WM_SETICON,ICON_BIG,(DWORD)hBigIcon);	
			SendMessage(hwndDlg,WM_SETICON,ICON_SMALL,(DWORD)hSmallIcon);*/	

			//����ProcessListView�ķ��
			InitProcessListView(hwndDlg);

			//����ModuleListView�ķ��
			InitModuleListView(hwndDlg);
			

			break;
		
		case WM_CLOSE:

			EndDialog(hwndDlg, 0);

			return TRUE;

			//����ͨ�ÿؼ�����Ϣ
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



