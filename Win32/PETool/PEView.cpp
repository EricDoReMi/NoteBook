//����չʾPE�ļ�
#include "StdAfx.h"

//չʾPEͷ��Ϣ
void ShowPEHead(){
	//��ȡ�����PE�ļ���·��
	OPENFILENAME stopenfile;

	TCHAR szPeFileExt[100]="*.exe;*.dll;*.scr;*.drv;*.sys";
	
	memset(szFileName,0,256);
	memset(&stopenfile,0,sizeof(OPENFILENAME));
	stopenfile.lStructSize=sizeof(OPENFILENAME);
	stopenfile.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST;
	stopenfile.hwndOwner=g_hwndDlg;
	stopenfile.lpstrFilter=szPeFileExt;
	stopenfile.lpstrFile=szFileName;
	stopenfile.nMaxFile=MAX_PATH;
	GetOpenFileName(&stopenfile);
	
	//��PE�Ի���
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_HEADER),g_hwndDlg,PEDialogProc);
	return;


}

//��ȡPEͷ��Ϣ
void ReadPEHead(){
	//���ڴ洢�ַ���������
	TCHAR szBuffer[256];
	
	
	PIMAGE_FILE_HEADER pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER32 pOptionHeader = NULL;
	
	
	if(!ReadPEFile(szFileName,&pFileBuffer)){
		return;
	}

	
	pPEHeader=getPEHeader(pFileBuffer);
	pOptionHeader=getOptionHeader(pFileBuffer);

	//��ڵ�
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->AddressOfEntryPoint);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_AddressOfEntryPoint,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//�������ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->ImageBase);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_ImageBase,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//�����С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfImage);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfImage,WM_SETTEXT,0,(DWORD)szBuffer);

	//�����ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfCode);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfCode,WM_SETTEXT,0,(DWORD)szBuffer);

	//���ݻ�ַ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->BaseOfData);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_BaseOfData,WM_SETTEXT,0,(DWORD)szBuffer);

	//�ڴ����
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SectionAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SectionAlignment,WM_SETTEXT,0,(DWORD)szBuffer);

	//�ļ�����
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->FileAlignment);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_FileAlignment,WM_SETTEXT,0,(DWORD)szBuffer);
	
	//��־ֵ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Magic);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Magic,WM_SETTEXT,0,(DWORD)szBuffer);

	//��ϵͳ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->Subsystem);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Subsystem,WM_SETTEXT,0,(DWORD)szBuffer);

	//������Ŀ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->NumberOfSections);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_NumberOfSections,WM_SETTEXT,0,(DWORD)szBuffer);

	//ʱ���
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->TimeDateStamp);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_TimeDateStamp,WM_SETTEXT,0,(DWORD)szBuffer);

	//PEͷ��С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->SizeOfHeaders);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfHeaders,WM_SETTEXT,0,(DWORD)szBuffer);

	//����ֵ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->Characteristics);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_Characteristics,WM_SETTEXT,0,(DWORD)szBuffer);

	//У���
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->CheckSum);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_CheckSum,WM_SETTEXT,0,(DWORD)szBuffer);

	//��ѡPEͷ��С
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pPEHeader->SizeOfOptionalHeader);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_PEHEAD_SizeOfOptionalHeader,WM_SETTEXT,0,(DWORD)szBuffer);

	//Ŀ¼����Ŀ
	memset(szBuffer,0,256);
	sprintf(szBuffer,"%x",pOptionHeader->NumberOfRvaAndSizes);
	SendDlgItemMessage(g_PEDlg,IDC_EDIT_NumberOfRvaAndSizes,WM_SETTEXT,0,(DWORD)szBuffer);

}

//չʾPESections��Ϣ
void ShowPESections(){

	
	//��PESection�Ի���
	DialogBox(hAppInstance,MAKEINTRESOURCE(IDD_DIALOG_SECTION),g_PEDlg,SectionDialogProc);
	return;


}


//��ʼ��Section�б�
VOID InitSectionListView(HWND hDlg){
	LV_COLUMN lv;//�洢��								
	HWND hListProcess;//���ListView���							
									
	//��ʼ��								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//��ȡIDC_LIST_SECTIONVIEW���								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_SECTIONVIEW);								
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
	lv.pszText = TEXT("�ļ�ƫ��");								
	lv.cx = 100;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//������								
	lv.pszText = TEXT("�ļ���С");								
	lv.cx = 100;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//������								
	lv.pszText = TEXT("�ڴ�ƫ��");								
	lv.cx = 100;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);
	//������								
	lv.pszText = TEXT("�ڴ��С");								
	lv.cx = 100;								
	lv.iSubItem = 4;								
	ListView_InsertColumn(hListProcess, 4, &lv);

	//������								
	lv.pszText = TEXT("��������");								
	lv.cx = 100;								
	lv.iSubItem = 5;								
	ListView_InsertColumn(hListProcess, 5, &lv);

	EnumPESections(hListProcess);
}

//����Section
VOID EnumPESections(HWND hListProcess){
	//���ڴ洢�ַ����Ļ�����
	TCHAR szBuffer[0x50];

	LV_ITEM vitem;						


	//��ȡ�ڱ���Ϣ
	PIMAGE_SECTION_HEADER pSectionHeader = NULL;
	
	pSectionHeader=getSectionHeader(pFileBuffer);
	
	WORD sectionNum=getSectionNum(pFileBuffer);

	WORD i=0;
	for(i=0;i<sectionNum;i++){
		BYTE names[9]={0};
		BYTE* p_name=names;
		p_name=pSectionHeader->Name;

		//��ʼ��
		memset(&vitem,0,sizeof(LV_ITEM));
		vitem.mask = LVIF_TEXT;

		//����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%s",p_name);
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;//�ڼ���						
		vitem.iSubItem = 0;	//�ڼ���				
		//����һ���꣬��SendMessage����������һ���ģ���һ��ʱҪ��ListView_InsertItem�����������ListView_SetItem
		//ListView_InsertItem(hListProcess, &vitem);
		SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);


		//�ļ�ƫ����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->PointerToRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 1;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ļ������ĳߴ�
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->SizeOfRawData);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 2;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ڴ�ƫ����
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",FileOffsetToRva(pFileBuffer,pSectionHeader->PointerToRawData));						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 3;						
		ListView_SetItem(hListProcess, &vitem);	

		//�ڴ�����ĳߴ�
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Misc.VirtualSize);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 4;						
		ListView_SetItem(hListProcess, &vitem);	

		//������
		memset(szBuffer,0,0x50);
		sprintf(szBuffer,"%X",pSectionHeader->Characteristics);						
		vitem.pszText = TEXT(szBuffer);						
		vitem.iItem = i;						
		vitem.iSubItem = 5;						
		ListView_SetItem(hListProcess, &vitem);	

		//�����һ���ڱ���Ϣ
		pSectionHeader=(PIMAGE_SECTION_HEADER)((char*)pSectionHeader+40);
		
		
	}
	
   						

}
