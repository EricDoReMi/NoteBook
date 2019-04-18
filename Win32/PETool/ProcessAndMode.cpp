//���̺�ģ�����Ĵ���
#include "stdafx.h"



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
	lv.cx = 150;							//�п�
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
	lv.cx = 100;								//�п�
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//�ڶ���								
	lv.pszText = TEXT("ģ��λ��");								
	lv.cx = 200;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);
	
	//������								
	lv.pszText = TEXT("�����ַ");								
	lv.cx = 200;								
	lv.iSubItem = 2;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,2,(DWORD)&lv);

	//������								
	lv.pszText = TEXT("�����С");								
	lv.cx = 200;								
	lv.iSubItem = 3;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,3,(DWORD)&lv);
							
}

//��������
VOID EnumProcess(HWND hListProcess){
	//���ڴ洢�ַ����Ļ�����
	TCHAR szBuffer[0x50];

	HANDLE hSnap;
    PROCESSENTRY32 pe;//�ýṹ����������Ž���ID��
    //��ȡ���̿���
    hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    //ʧ���˳�����
    if (hSnap==INVALID_HANDLE_VALUE){
         return;
	}
    //PROCESSENTRY32�ṹ��ʹ��ǰ�����ȳ�ʼ��dwSize��Ա
    pe.dwSize=sizeof(pe);
	
	LV_ITEM vitem;						

	DWORD processNum=0;//���̵ļ�����						
    //��ȡ��һ��������Ϣ
    if (Process32First(hSnap, &pe))
    {

        do
         {
             MODULEENTRY32 me;
             HANDLE hMod;
             if (pe.th32ProcessID==0)
                 continue;
             //��ȡpe.th32ProcessID���̵�ģ�����
             hMod=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,pe.th32ProcessID);
             //ʧ����ֱ��������һ������
             if (hMod==INVALID_HANDLE_VALUE)
                  continue;
             //ͬ����MODULEENTRY32�ṹ��ʹ��ǰ�����ȳ�ʼ��dwSize��Ա
             me.dwSize = sizeof(me);
             //��ȡ�ý��̵ĵ�һ��ģ����Ϣ
             Module32First(hMod, &me);

			//��ʼ��
			memset(&vitem,0,sizeof(LV_ITEM));
			vitem.mask = LVIF_TEXT;

			vitem.pszText = pe.szExeFile;						
			vitem.iItem = processNum;//�ڼ���						
			vitem.iSubItem = 0;	//�ڼ���				
			//����һ���꣬��SendMessage����������һ���ģ���һ��ʱҪ��ListView_InsertItem�����������ListView_SetItem
			//ListView_InsertItem(hListProcess, &vitem);
			SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);	
			//ת���ַ���
			memset(szBuffer,0,0x50);
			sprintf(szBuffer,"%d",pe.th32ProcessID);						
			vitem.pszText = TEXT(szBuffer);						
			vitem.iItem = processNum;						
			vitem.iSubItem = 1;						
			ListView_SetItem(hListProcess, &vitem);						
					
			memset(szBuffer,0,0x50);
			sprintf(szBuffer,"%X",me.modBaseAddr);						
			vitem.pszText = TEXT(szBuffer);						
			vitem.iItem = processNum;						
			vitem.iSubItem = 2;						
			ListView_SetItem(hListProcess, &vitem);						
					
			memset(szBuffer,0,0x50);
			sprintf(szBuffer,"%X",me.modBaseSize);						
			vitem.pszText = TEXT(szBuffer);	
			vitem.iItem = processNum;						
			vitem.iSubItem = 3;						
			ListView_SetItem(hListProcess, &vitem);	
				
				
             CloseHandle(hMod);
			 processNum++;
         } while (Process32Next(hSnap,&pe));//��ȡ��һ��������Ϣ

     CloseHandle(hSnap);
												


	}
}

//����module
//hListProcess:ProcessListView�ľ��
VOID EnumModules(HWND hListProcess){
	
	HWND hModeListProcess;//���ModeListView���
	//��ȡIDC_LIST_PROCESS���								
	hModeListProcess = GetDlgItem(g_hwndDlg,IDC_LIST_MODULE);

	//���ڴ洢�ַ����Ļ�����
	TCHAR szBuffer[0x50];

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
	
	DWORD DProcessID=0;
	sscanf(szPid,"%d",&DProcessID );

	//����ϵͳ��API
	MODULEENTRY32 me;
    HANDLE hMod;
	//��ȡProcessID���̵�ģ�����
    hMod=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,DProcessID);

	
	
	//ͬ����MODULEENTRY32�ṹ��ʹ��ǰ�����ȳ�ʼ��dwSize��Ա
    me.dwSize = sizeof(me);
    //��ȡ�ý��̵ĵ�һ��ģ����Ϣ
    if(Module32First(hMod, &me)){

		//��ʼ��
		DWORD ModNum=0;//ģ��ļ�����
		LV_ITEM vitem;
		memset(&vitem,0,sizeof(LV_ITEM));
		vitem.mask = LVIF_TEXT;

		do{
			
			if (hMod==INVALID_HANDLE_VALUE)
                  continue;
			
			vitem.pszText = me.szModule;					
			vitem.iItem = ModNum;//�ڼ���						
			vitem.iSubItem = 0;	//�ڼ���				
			//����һ���꣬��SendMessage����������һ���ģ���һ��ʱҪ��ListView_InsertItem�����������ListView_SetItem
			//ListView_InsertItem(hListProcess, &vitem);
			SendMessage(hModeListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);	
								
			vitem.pszText = me.szExePath;						
			vitem.iItem = ModNum;						
			vitem.iSubItem = 1;						
			ListView_SetItem(hModeListProcess, &vitem);						
					
			memset(szBuffer,0,0x50);
			sprintf(szBuffer,"%X",me.modBaseAddr);						
			vitem.pszText = TEXT(szBuffer);						
			vitem.iItem = ModNum;						
			vitem.iSubItem = 2;						
			ListView_SetItem(hModeListProcess, &vitem);						
					
			memset(szBuffer,0,0x50);
			sprintf(szBuffer,"%X",me.modBaseSize);						
			vitem.pszText = TEXT(szBuffer);	
			vitem.iItem = ModNum;						
			vitem.iSubItem = 3;						
			ListView_SetItem(hModeListProcess, &vitem);	
		
			ModNum++;
		}while(Module32Next(hMod,&me));	

		CloseHandle(hMod);
	
	}
	

}