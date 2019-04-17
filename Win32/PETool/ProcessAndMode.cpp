//进程和模块界面的处理
#include "stdafx.h"



//初始化进程列表
VOID InitProcessListView(HWND hDlg){
	LV_COLUMN lv;//存储列								
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
	lv.cx = 150;							//列宽
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
	LV_COLUMN lv;//存储列								
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

//遍历进程
VOID EnumProcess(HWND hListProcess){

	HANDLE hSnap;
    PROCESSENTRY32 pe;//该结构体是用来存放进程ID的
    //获取进程快照
    hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    //失败退出程序
    if (hSnap==INVALID_HANDLE_VALUE){
         return;
	}
    //PROCESSENTRY32结构体使用前必须先初始化dwSize成员
    pe.dwSize=sizeof(pe);

	DWORD processNum=0;//进程的计数器
	
	LV_ITEM vitem;						
	//初始化
	memset(&vitem,0,sizeof(LV_ITEM));

    //获取第一个进程信息
    if (Process32First(hSnap, &pe))
    {

        do
         {
             MODULEENTRY32 me;
             HANDLE hMod;
             if (pe.th32ProcessID==0)
                 continue;
             //获取pe.th32ProcessID进程的模块快照
             hMod=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,pe.th32ProcessID);
             //失败则直接跳到下一个进程
             if (hMod==INVALID_HANDLE_VALUE)
                  continue;
             //同样，MODULEENTRY32结构体使用前必须先初始化dwSize成员
             me.dwSize = sizeof(me);
             //获取该进程的第一个模块信息
             Module32First(hMod, &me)
			 			 
                 printf("%6d %-15s %s\n",pe.th32ProcessID,me.szModule,me.szExePath);
             CloseHandle(hMod);
         } while (Process32Next(hSnap,&pe));//获取下一个进程信息
     CloseHandle(hSnap);

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